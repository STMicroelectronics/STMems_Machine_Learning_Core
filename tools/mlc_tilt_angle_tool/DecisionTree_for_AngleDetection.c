#include <stdio.h>
#include <stdlib.h> // atoi and atof
#include <math.h> // sqrt, sin, cos
#include <float.h> // DBL_MAX

//#define PRINT_LEAF_INFO
//#define PRINT_ANGLES

#define MAX_LEAVES 255
#define THS_PERCENTAGE_OF_G 1.0

#define DEG2RAD (M_PI / 180.0)

/* Mode, that is the axis used: H = horizontal axis, V = vertical axis, T = third axis
 * Usually X and Y are in the horizontal plane, Z is aligned with vertical
 */
enum {
	H_MODE = 0, // horizontal: X or Y axis for +/-90 deg pitch
	V_MODE, // vertical: Z axis for 0-180 deg tilt
	HV_MODE, // dual: XZ or YZ axes for +/-180 deg rotation
	HVT_MODE // dual+: XZ or YZ axes for +/-180 deg rotation + check for no rotation on third axis
};

enum {
	OPT_SHALLOW = 0, // shallow: decision tree has minimum depth
	OPT_RMS_SAFE // RMS-safe: threshold has maximum distance
};

static int hv_mode;

static double angle1; // start angle, fist leaf
static double angle2; // end angle, last leaf
static double angle_min, angle_max; // set based on mode
static double angle_step;

static int leaves;

static int opt_mode;

/* If unit of measure is [g] then gravity is 1.0
 * IIS2ICLX uses [g/4] therefore gravity is 4.0
 * LSM6DSO32X uses [2g] therefore gravity is 0.5
 */
static double gravity;

static double rms_noise;
static double t_ths;

static double h_offset, h_sensitivity; // horizontal axis
static double v_offset, v_sensitivity; // vertical axis
static double t_offset, t_sensitivity; // third axis
static char *h_str;
static char *v_str;
static char *t_str;

static double angles[MAX_LEAVES];
static double h_acc[MAX_LEAVES], h_ths[MAX_LEAVES];
static double v_acc[MAX_LEAVES], v_ths[MAX_LEAVES];
static int rms_flags[MAX_LEAVES];

static char *rec_str = "|   ";
static int max_rec_level;
static int tree_size; // should be equal to (leaves - 1) * 2

static char *fname_dectree = "dectree.txt";
static char *fname_session = "session.txt";
static FILE *fp_dectree;
static FILE *fp_session;

static void params_set_default(void)
{
	hv_mode = H_MODE;

	angle1 = -90.0;
	angle2 = +90.0;

	leaves = 15;

	gravity = 1.0;

	rms_noise = 0.0;
	t_ths = gravity * THS_PERCENTAGE_OF_G / 100.0;

	h_offset = 0.0;
	h_sensitivity = 1.0;
	h_str = "accX";

	v_offset = 0.0;
	v_sensitivity = 1.0;
	v_str = "accZ";

	t_offset = 0.0;
	t_sensitivity = 1.0;
	t_str = "accY";
}

static void params_print(void)
{
	fprintf(fp_session, "---- parameters\n");

	switch (hv_mode) {
	case H_MODE:
		fprintf(fp_session, "  m = 0, horizontal axis mode (%s)\n", h_str);
		break;
	case V_MODE:
		fprintf(fp_session, "  m = 1, vertical axis mode (%s)\n", v_str);
		break;
	case HV_MODE:
		fprintf(fp_session, "  m = 2, dual axis mode (%s and %s)\n", h_str, v_str);
		break;
	case HVT_MODE:
		fprintf(fp_session, "  m = 3, dual + third axis mode (%s and %s + %s)\n", h_str, v_str, t_str);
		break;
	default:
		fprintf(fp_session, "unknown mode\n");
	}

	fprintf(fp_session, "  angle from %.4f to %.4f deg\n", angle1, angle2);
	fprintf(fp_session, "  %d leaves\n", leaves);

	switch (opt_mode) {
		case OPT_SHALLOW:
			fprintf(fp_session, "  opt = 0, shallow decision tree\n");
			break;
		case OPT_RMS_SAFE:
			fprintf(fp_session, "  opt = 1, RMS-safe decision tree\n");
			break;
		default:
			fprintf(fp_session, "unknown optimization\n");
	}

	fprintf(fp_session, "  gravity = %.6f\n", gravity);

	if (rms_noise > 0.0)
		fprintf(fp_session, "  RMS noise = %.6f\n", rms_noise);

	if (hv_mode == HVT_MODE)
		fprintf(fp_session, "  third axis threshold = %.6f\n", t_ths);

	if (hv_mode != V_MODE)
		fprintf(fp_session, "  horiz. axis offset = %+.6f, sensitivity = %+.6f, string = %s\n", h_offset, h_sensitivity, h_str);

	if (hv_mode != H_MODE)
		fprintf(fp_session, "  vert.  axis offset = %+.6f, sensitivity = %+.6f, string = %s\n", v_offset, v_sensitivity, v_str);

	if (hv_mode == HVT_MODE)
		fprintf(fp_session, "  third  axis offset = %+.6f, sensitivity = %+.6f, string = %s\n", t_offset, t_sensitivity, t_str);

	fprintf(fp_session, "\n");
}

static int angle_out_of_range(double angle)
{
	if (angle < angle_min || angle > angle_max)
		return 1;
	else
		return 0;
}

static int params_check(void)
{
	int error = 0;

	switch (hv_mode) {
	case H_MODE:
		angle_min = -90.0;
		angle_max = +90.0;
		break;
	case V_MODE:
		angle_min = 0.0;
		angle_max = +180.0;
		break;
	case HV_MODE:
	case HVT_MODE:
		angle_min = -180.0;
		angle_max = +180.0;
		break;
	default:
		printf("ERROR: unknown mode m = %d\n", hv_mode);
		error = 1;
	}

	if (angle_out_of_range(angle1)) {
		printf("ERROR: first angle a1 = %.4f out of range (%.0f to %.0f deg)\n", angle1, angle_min, angle_max);
		error = 1;
	}

	if (angle_out_of_range(angle2)) {
		printf("ERROR: last angle a2 = %.4f out of range (%.0f to %.0f deg)\n", angle2, angle_min, angle_max);
		error = 1;
	}

	if (angle1 >= angle2) {
		printf("ERROR: first angle a1 = %.4f >= last angle a2 %.4f\n", angle1, angle2);
		error = 1;
	}

	if (leaves < 2 || leaves > MAX_LEAVES) {
		printf("ERROR: N = %d leaves out of range (2-%d)\n", leaves, MAX_LEAVES);
		error = 1;
	}

	switch (opt_mode) {
	case 0:
		opt_mode = OPT_SHALLOW;
		break;
	case 1:
		opt_mode = OPT_RMS_SAFE;
		break;
	default:
		printf("ERROR: unknown optimization opt = %d\n", opt_mode);
		error = 1;
	}

	if (gravity <= 0.0) {
		printf("ERROR: gravity value must be > 0\n");
		error = 1;
	}

	if (rms_noise * 3.0 > gravity)
		printf("WARNING: 3 * RMS noise > gravity\n");

	if (hv_mode == HVT_MODE) {
		if (t_ths <= 0.0) {
			printf("ERROR: third axis threshold must be > 0\n");
			error = 1;
		} else if (rms_noise > 0.0 && rms_noise * 3 > t_ths) {
			printf("WARNING: 3 * RMS noise > third axis threshold\n");
		}
	}

	if (hv_mode != V_MODE && h_sensitivity == 0.0) {
		printf("ERROR: horiz. axis sensitivity cannot be 0\n");
		error = 1;
	}

	if (hv_mode != H_MODE && v_sensitivity == 0.0) {
		printf("ERROR: vert. axis sensitivity cannot be 0\n");
		error = 1;
	}

	if (hv_mode == HVT_MODE && t_sensitivity == 0.0) {
		printf("ERROR: third axis sensitivity cannot be 0\n");
		error = 1;
	}

	if (error)
		printf("\n");

	return error;
}

void params_help_print(char *bin_name)
{
	params_set_default();

	printf("---- help\n");
	printf("%s m a1 a2 N [opt g RMS ths hofs hsns hstr vofs vsns vstr tofs tsns tstr]\n\n", bin_name);
	printf("     m: mode 0 = horizontal, 1 = vertical, 2 = dual, 3 = dual+\n");
	printf("    a1: first angle in degrees\n");
	printf("    a2: last angle in degrees\n");
	printf("     N: number of leaves, max %d\n", MAX_LEAVES);
	printf("\n");
	printf("   opt: 0 = shallow, 1 = RMS-safe,     default: 0 for horiz/vert, 1 for dual/+\n");
	printf("     g: gravity vector value,          default: %.6f\n", gravity);
	printf("   RMS: RMS noise value,               default: %.6f\n", rms_noise);
	printf("   ths: threshold for third axis,      default: %.6f\n", t_ths);
	printf("\n");
	printf("  hofs: horiz. axis offset,            default: %.6f\n", h_offset);
	printf("  hsns: horiz. axis sensitivity,       default: %.6f\n", h_sensitivity);
	printf("  hstr: horiz. axis string,            default: %s\n", h_str);
	printf("\n");
	printf("  vofs: horiz. axis offset,            default: %.6f\n", v_offset);
	printf("  vsns: horiz. axis sensitivity,       default: %.6f\n", v_sensitivity);
	printf("  vstr: horiz. axis string,            default: %s\n", v_str);
	printf("\n");
	printf("  tofs: third  axis offset,            default: %.6f\n", t_offset);
	printf("  tsns: third  axis sensitivity,       default: %.6f\n", t_sensitivity);
	printf("  tstr: third  axis string,            default: %s\n", t_str);
	printf("\n");
	printf("Horiz. mode for angle between horiz. axis and horiz. plane (pitch: -90 to +90 deg)\n");
	printf("Vert. mode for angle between vert. axis and the vertical (tilt: 0 to +180 deg)\n");
	printf("Dual mode for rotation constrained around the third axis (angle: -180 to +180 deg)\n");
	printf("Dual+ mode extends the decision tree to check that third axis is below threshold\n");
	printf("\n");
	printf("Use negative sensitivity to flip the corresponding axis\n");
	printf("\n");
}

static int params_parse(int argc, char *argv[])
{
	if (argc < 5) {
		params_help_print(argv[0]);
		return 1;
	}

	hv_mode = atoi(argv[1]);
	angle1 = atof(argv[2]);
	angle2 = atof(argv[3]);
	leaves = abs(atoi(argv[4]));

	opt_mode = hv_mode == HV_MODE || hv_mode == HVT_MODE; // default

	if (argc > 18)
		argc = 18; // ignore args in excess

	switch (argc) {
	case 18:
		t_str = argv[17];
		// fall-through
	case 17:
		t_sensitivity = atof(argv[16]);
		// fall-through
	case 16:
		t_offset = atof(argv[15]);
		// fall-through
	case 15:
		v_str = argv[14];
		// fall-through
	case 14:
		v_sensitivity = atof(argv[13]);
		// fall-through
	case 13:
		v_offset = atof(argv[12]);
		// fall-through
	case 12:
		h_str = argv[11];
		// fall-through
	case 11:
		h_sensitivity = atof(argv[10]);
		// fall-through
	case 10:
		h_offset = atof(argv[9]);
		// fall-through
	case 9:
		t_ths = fabs(atof(argv[8]));
		// fall-through
	case 8:
		rms_noise = fabs(atof(argv[7]));
		// fall-through
	case 7:
		gravity = fabs(atof(argv[6]));
		// fall-through
	case 6:
		opt_mode = atoi(argv[5]);
		// fall-through
	}

	return 0;
}

static int params_interactive(void)
{
	int mode, opt;

	printf("---- interactive input\n");

	printf("  mode 0 = horiz, 1 = vert, 2 = dual, 3 = dual + third axis? ");

	if (scanf("%d", &mode) != 1)
		return 1;

	switch (mode) {
	case 0:
		hv_mode = H_MODE;
		printf("angle range -90 to +90 deg\n");
		break;
	case 1:
		hv_mode = V_MODE;
		printf("angle range 0 to +180 deg\n");
		break;
	case 2:
		hv_mode = HV_MODE;
		printf("angle range -180 to +180 deg\n");
		break;
	case 3:
		hv_mode = HVT_MODE;
		printf("angle range -180 to +180 deg\n");
		break;
	default:
		printf("ERROR: out of range\n");
		return 1;
	}

	printf("  first angle? ");
	if (scanf("%lf", &angle1) != 1)
		return 1;

	printf("  last angle? ");
	if (scanf("%lf", &angle2) != 1)
		return 1;

	printf("  number of leaves (2-%d)? ", MAX_LEAVES);
	if (scanf("%d", &leaves) != 1)
		return 1;

	printf("  optimization: 0 = shallow tree, 1 = RMS-safe? ");
	if (scanf("%d", &opt) != 1)
		return 1;

	switch (opt) {
		case 0:
			opt_mode = OPT_SHALLOW;
			break;
		case 1:
			opt_mode = OPT_RMS_SAFE;
			break;
		default:
			printf("ERROR: out of range\n");
			return 1;
	}

	printf("  gravity value (> 0)? ");
	if (scanf("%lf", &gravity) != 1)
		return 1;

	printf("  RMS noise value (>= 0)? ");
	if (scanf("%lf", &rms_noise) != 1)
		return 1;

	if (hv_mode == HVT_MODE) {
		printf("  third axis threshold (> 0)? ");
		if (scanf("%lf", &t_ths) != 1)
			return 1;
	}

	printf("\n");

	return 0;
}

static double angle2acc(double angle, int mode)
{
	double acc;

	if (mode == H_MODE)
		acc = gravity * h_sensitivity * sin(angle * DEG2RAD) + h_offset;
	else
		acc = gravity * v_sensitivity * cos(angle * DEG2RAD) + v_offset;

	return acc;
}

void dectree_design_init(void)
{
#ifdef PRINT_ANGLES
	fprintf(fp_session, "---- angles and conversion formula\n");
#else
	fprintf(fp_session, "---- conversion formula\n");
#endif

	angle_step = (angle2 - angle1) / (double)(leaves - 1);
	fprintf(fp_session, "  angle resolution = %.4f deg\n", angle_step);

#ifdef PRINT_ANGLES
	fprintf(fp_session, "  %d angles:\n    ", leaves);
#endif
	for (int i = 0; i < leaves; i++) {
		rms_flags[i] = 0;
		angles[i] = angle1 + angle_step * (double)i;
		h_acc[i] = angle2acc(angles[i], H_MODE);
		v_acc[i] = angle2acc(angles[i], V_MODE);
#ifdef PRINT_ANGLES
		fprintf(fp_session, "%10.4f, ", angles[i]);
		if (i % 6 == 5)
			fprintf(fp_session, "\n    ");
#endif
	}
#ifdef PRINT_ANGLES
	fprintf(fp_session, "\n");
#endif

	fprintf(fp_session, "  conversion formula for output codes (0-%d):\n", leaves - 1);
	fprintf(fp_session, "    angle = output code * %.6f + (%.6f) deg\n\n", angle_step, angle1);

	if (angle1 == -180.0 && angle2 == +180.0) {
		fprintf(fp_session, "NOTE: first and last angles are actually the same orientation.\n");
		fprintf(fp_session, "  one can be removed and decision tree can be re-designed.\n");
		fprintf(fp_session, "  when first is removed the range is from %.4f to +180.0 deg\n", angles[1]);
		fprintf(fp_session, "  when last is removed the range is from -180.0 to %.4f deg\n\n", angles[leaves - 2]);
	}

	for(int i = 0; i < leaves; i++) {
		if (i == leaves - 1) {
			h_ths[i] = (h_acc[i] + h_acc[0]) / 2.0;
			v_ths[i] = (v_acc[i] + v_acc[0]) / 2.0;
		} else {
			h_ths[i] = (h_acc[i] + h_acc[i + 1]) / 2.0;
			v_ths[i] = (v_acc[i] + v_acc[i + 1]) / 2.0;
		}
	}

	max_rec_level = 0;
	tree_size = 0;
}

static int angle_i_cmp(const void *a, const void *b)
{
	return angles[*(int *)a] - angles[*(int *)b];
}

static void angle_arr_unwrap(double *angle_arr, int len)
{
	double delta, offset = 0.0;

	for (int i = 1; i < len; i++) {
		angle_arr[i] += offset;
		delta = angle_arr[i] - angle_arr[i - 1];
		if (delta > +180.0) {
			angle_arr[i] -= 360.0;
			offset -= 360.0;
		} else if (delta < -180.0) {
			angle_arr[i] += 360.0;
			offset += 360.0;
		}
	}
}

static double angle_i_var(int *angle_i, int len)
{
	if (len == 0)
		return -1.0; // negative value is impossible and signals an error
	if (len == 1)
		return 0.0;

	double *angle_arr = malloc(sizeof(double) * len);
	if (angle_arr == NULL) {
		printf("ERROR: cannot allocate memory (var, %d).\n", len);
		return -1.0;
	}

	for (int i = 0; i < len; i++)
		angle_arr[i] = angles[angle_i[i]];

	angle_arr_unwrap(angle_arr, len);

	// one-pass based on sum of squares with compensated summation
	double m = 0.0, m2 = 0.0, comp_m = 0.0, comp_m2 = 0.0;
	double old_m, delta_m, old_m2, delta_m2, n;
	volatile double inc; // to prevent optimization

	for (int i = 0; i < len; i++) {
		n = (double)(i + 1);

		old_m = m;
		delta_m = (angle_arr[i] - m) - comp_m;
		inc = (delta_m / n) + comp_m;
		m += inc;
		comp_m = (old_m - m) + inc;

		old_m2 = m2;
		delta_m2 = delta_m * ((angle_arr[i] - m) - comp_m);
		inc = delta_m2 + comp_m2;
		m2 += inc;
		comp_m2 = (old_m2 - m2) + inc;
	}

	n = (double)len;
	double var = m2 / (n - 1.0); // unbiased variance

	free(angle_arr);

	return var;
}

static int angle_i_split(int *angle_i, int len, double *acc_arr, double ths, int **angle_i1, int *len1, int **angle_i2, int *len2)
{
	int cnt = 0;

	for (int i = 0; i < len; i++) {
		if (acc_arr[angle_i[i]] <= ths)
			cnt++;
	}

	if (cnt == 0 || cnt == len)
		return 0;

	*len1 = cnt;
	*angle_i1 = malloc(sizeof(int) * cnt);
	if (*angle_i1 == NULL) {
		printf("ERROR: cannot allocate memory (split1, %d).\n", cnt);
		return 0;
	}

	*len2 = len - cnt;
	*angle_i2 = malloc(sizeof(int) * (len - cnt));
	if (*angle_i2 == NULL) {
		printf("ERROR: cannot allocate memory (split2, %d).\n", len - cnt);
		free(*angle_i1);
		return 0;
	}

	int i1 = 0, i2 = 0;
	for (int i = 0; i < len; i++)
		if (acc_arr[angle_i[i]] <= ths)
			(*angle_i1)[i1++] = angle_i[i];
		else
			(*angle_i2)[i2++] = angle_i[i];

	return 1;
}

static int angle_i_find_ths(int *angle_i, int len, double *acc_arr, double *ths_arr, int ths_len, double var, double *var_delta, double *dist_min, double *merit)
{
	double ths, var1, var2, t_var_delta, t_dist, t_dist_min, t_merit;
	int *angle_i1 = NULL, *angle_i2 = NULL, len1, len2;
	int upd, ths_sel = -1;

	for (int t = 0; t < ths_len; t++) {
		ths = ths_arr[t];

		if (isnan(ths))
			continue;

		if (!angle_i_split(angle_i, len, acc_arr, ths, &angle_i1, &len1, &angle_i2, &len2))
			continue;

		var1 = angle_i_var(angle_i1, len1) * (double)len1 / (double)len;
		var2 = angle_i_var(angle_i2, len2) * (double)len2 / (double)len;

		free(angle_i1);
		free(angle_i2);

		t_var_delta = var - var1 - var2;

		t_dist_min = DBL_MAX;
		for (int i = 0; i < len; i++) {
			t_dist = fabs(acc_arr[angle_i[i]] - ths);
			if (t_dist < t_dist_min)
				t_dist_min = t_dist;
		}

		if (t_var_delta >= 0.0)
			t_merit = sqrt(t_var_delta * t_dist_min);
		else
			t_merit = -sqrt(-t_var_delta * t_dist_min);

		upd = 0;
		switch (opt_mode) {
		case OPT_SHALLOW:
			if ((t_var_delta > *var_delta && t_dist_min >  0.0) ||
				(t_var_delta >= *var_delta && t_dist_min > *dist_min))
				upd = 1;
			break;
		case OPT_RMS_SAFE:
			if (t_merit > *merit)
				upd = 1;
			break;
		}

		if (upd) {
			*var_delta = t_var_delta;
			*dist_min = t_dist_min;
			*merit = t_merit;
			ths_sel = t;
		}
	}

	return ths_sel;
}

static void angle_i_rms_flag(int *angle_i, int len, double *acc_arr, double ths)
{
	for (int i = 0; i < len; i++) {
		if (fabs(acc_arr[angle_i[i]] - ths) < (rms_noise * 3.0))
			rms_flags[angle_i[i]] = 1;
	}
}

static void dectree_design_node(int *angle_i, int len, int rec_level)
{
	if (len <= 1)
		return;

	if (rec_level > max_rec_level)
		max_rec_level = rec_level;

	qsort(angle_i, len, sizeof(int), angle_i_cmp);

	double var = angle_i_var(angle_i, len);
	double var_delta = -DBL_MAX, dist_min = -DBL_MAX, merit = -DBL_MAX;
	int hv_sel = -1, ths_sel = -1, sel;

	if (hv_mode != V_MODE) {
		sel = angle_i_find_ths(angle_i, len, h_acc, h_ths, leaves, var, &var_delta, &dist_min, &merit);
		if (sel >= 0) {
			hv_sel = 0;
			ths_sel = sel;
		}
	}

	if (hv_mode != H_MODE) {
		sel = angle_i_find_ths(angle_i, len, v_acc, v_ths, leaves, var, &var_delta, &dist_min, &merit);
		if (sel >= 0) {
			hv_sel = 1;
			ths_sel = sel;
		}
	}

	if (hv_sel < 0) {
		printf("ERROR: no feature selected\n");
		return;
	}

	char *str;
	double ths, *acc_arr;

	switch (hv_sel) {
	case 0:
		str = h_str;
		acc_arr = h_acc;
		ths = h_ths[ths_sel];
		//h_ths[ths_sel] = nan("0"); // comment to allow re-use
		break;
	case 1:
		str = v_str;
		acc_arr = v_acc;
		ths = v_ths[ths_sel];
		//v_ths[ths_sel] = nan("0"); // comment to allow re-use
		break;
	}

	int *angle_i1 = NULL, *angle_i2 = NULL, len1, len2;

	if (!angle_i_split(angle_i, len, acc_arr, ths, &angle_i1, &len1, &angle_i2, &len2))
		return;

	angle_i_rms_flag(angle_i, len, acc_arr, ths);

	// upper node, <=
	for (int r = 0; r < rec_level; r++)
		fprintf(fp_dectree, "%s", rec_str);

	if (len1 > 1) {
#ifdef PRINT_LEAF_INFO
		fprintf(fp_dectree, "%s <= %.6f (%d/%d)\n", str, ths, len1, len);
#else
		fprintf(fp_dectree, "%s <= %.6f\n", str, ths);
#endif
		dectree_design_node(angle_i1, len1, rec_level + 1);
	} else {
		double angle = angles[angle_i1[0]];
		int n = (int)round((angle - angle1) / angle_step);
#ifdef PRINT_LEAF_INFO
		fprintf(fp_dectree, "%s <= %.6f: %d (%.4f deg, %d/%d)\n", str, ths, n, angle, len1, len);
#else
		fprintf(fp_dectree, "%s <= %.6f: %d\n", str, ths, n);
#endif
	}

	// lower node, >
	for (int r = 0; r < rec_level; r++)
		fprintf(fp_dectree, "%s", rec_str);

	if (len2 > 1) {
#ifdef PRINT_LEAF_INFO
		fprintf(fp_dectree, "%s > %.6f (%d/%d)\n", str, ths, len2, len);
#else
		fprintf(fp_dectree, "%s > %.6f\n", str, ths);
#endif
		dectree_design_node(angle_i2, len2, rec_level + 1);
	} else {
		double angle = angles[angle_i2[0]];
		int n = (int)round((angle - angle1) / angle_step);
#ifdef PRINT_LEAF_INFO
		fprintf(fp_dectree, "%s > %.6f: %d (%.4f deg, %d/%d)\n", str, ths, n, angle, len2, len);
#else
		fprintf(fp_dectree, "%s > %.6f: %d\n", str, ths, n);
#endif
	}

	tree_size += 2; // one node -> two lines have been printed

	free(angle_i1);
	free(angle_i2);
}

static void dectree_design_root(void)
{
	if (hv_mode == HVT_MODE) {
		fprintf(fp_dectree, "%s <= %.6f\n", t_str, t_ths);
#ifdef PRINT_LEAF_INFO
		fprintf(fp_dectree, "%s%s <= %.6f: %d (wrong rotation)\n", rec_str, t_str, -t_ths, -1);
#else
		fprintf(fp_dectree, "%s%s <= %.6f: %d\n", rec_str, t_str, -t_ths, -1);
#endif
		fprintf(fp_dectree, "%s%s > %.6f\n", rec_str, t_str, -t_ths);
	}

	int *angle_i = malloc(sizeof(int) * leaves);

	if (angle_i == NULL) {
		printf("ERROR: cannot allocate memory (root, %d).\n", leaves);
		return;
	}

	for (int i = 0; i < leaves; i++)
		angle_i[i] = i;

	int rec_level = hv_mode != HVT_MODE ? 0 : 2;

	dectree_design_node(angle_i, leaves, rec_level);
	free(angle_i);

	if (hv_mode == HVT_MODE) {
#ifdef PRINT_LEAF_INFO
		fprintf(fp_dectree, "%s > %.6f: %d (wrong rotation)\n", t_str, t_ths, -1);
#else
		fprintf(fp_dectree, "%s > %.6f: %d\n", t_str, t_ths, -1);
#endif
	}

	fprintf(fp_dectree, "\n");
}

static void dectree_design_finish(void)
{
	fprintf(fp_dectree, "Number of Leaves: %d\n", leaves + (hv_mode == HVT_MODE ? 2 : 0));
	fprintf(fp_dectree, "Size of Tree: %d\n", tree_size + (hv_mode == HVT_MODE ? 4 : 0));

	if (tree_size != (leaves - 1) * 2)
		printf("ERROR: something is wrong.\n");

	fprintf(fp_dectree, "\n");

	fprintf(fp_session, "---- output codes/labels\n");

	if (hv_mode == HVT_MODE)
		fprintf(fp_session, "-1; ");

	for (int i = 0; i < leaves; i++) {
		if (i == leaves - 1)
			fprintf(fp_session, "%d\n", i);
		else
			fprintf(fp_session, "%d; ", i);
	}

	fprintf(fp_session, "\n");

	fprintf(fp_session, "---- other information\n");
	fprintf(fp_session, "Max recursion level: %d\n", max_rec_level);

	if (rms_noise > 0.0) {
		int rms_cnt = 0;

		for (int i = 0; i < leaves; i++) {
			if (rms_flags[i])
				rms_cnt++;
		}

		fprintf(fp_session, "Leaves/angles prone to RMS noise: %d\n", rms_cnt);

		for (int i = 0; i < leaves; i++) {
			if (rms_flags[i])
				fprintf(fp_session, "*");
			else
				fprintf(fp_session, ".");

			if (i % 40 == 39)
				fprintf(fp_session, "\n");
		}
	}
}

int main(int argc, char *argv[])
{
	params_set_default();

	if (argc > 1) {
		if (params_parse(argc, argv))
			return 1;
	} else {
		params_help_print(argv[0]);

		if (params_interactive())
			return 1;
	}

	fp_dectree = fopen(fname_dectree, "w");
	if (fp_dectree == NULL) {
		printf("ERROR: cannot open output file %s.\n", fname_dectree);
		return 1;
	}

	fp_session = fopen(fname_session, "w");
	if (fp_session == NULL) {
		printf("ERROR: cannot open output file %s.\n", fname_session);
		return 1;
	}

	params_print();
	if (params_check()) {
		fclose(fp_dectree);
		fclose(fp_session);
		return 1;
	}

	dectree_design_init();
	dectree_design_root();
	dectree_design_finish();

	fclose(fp_dectree);
	fclose(fp_session);

	return 0;
}