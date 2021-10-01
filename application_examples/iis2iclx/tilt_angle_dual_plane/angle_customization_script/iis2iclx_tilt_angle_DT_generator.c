/********************************************************************/
/*					Author: Martin Polacek							*/
/*					Copyright © 2021 STMicroelectronics				*/
/********************************************************************/

/*
 * This script creates two text files, each of which contains a decision tree (for the x and y axis) in the format required by Unico to generate the MLC.
 * It is recommended to keep the defines unchanged
 *
 *
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>

#if (defined(_WIN32) || defined(__WIN32__))
	#include <direct.h>
	#define mkdir(x, y) _mkdir(x)
#else
	extern int errno;
#endif

// defines for CLI argument handling
#define OPT_STR "-:ho:a:s:"			// for getopt() function

#define FORBIDDEN_FOLDER_NAME "\\/:*?\"<>|"
#define USAGE_MSG "[-a anglerange] [-o outputfolder] [-h]\r\n"
#define HELP "\
This program creates two text files, each of which contains a decision tree (for the x and y axis) in the format required by Unico to generate the MLC.\r\n \
\r\n\
USAGE:\r\n\
\t%s.exe %s\
\r\n\
where\r\n\
\tanglerange\tRequired angle range.\r\n\
\t\t\tIt must be an integer in the range from %d to %d [deg].\r\n\
\toutputfolder\tFolder where the decision trees (.txt files) should be stored.\r\n\
\t\t\tThe folder will be created in the same directory where the program is run.\r\n\
\t\t\tA folder name cannot contain any of the following characters:\r\n\
\t\t\t%s\r\n\
\r\n\
\tOptions:\r\n\
\t-h\t\tDisplay this help message\r\n\
\t-a\t\tSet the angle range\r\n\
\t-o\t\tSet the output folder name\r\n\
\r\n\
Default parameter configuration:\r\n\
\tangle range = +/- 20 degrees\r\n\
\toutput folder name = \"dec_tree\"\r\n\
\r\n\
STMicroelectronics 2021\r\n"

// general defines
#define DEFAULT_ANGLE_RANGE 20		// default angle range in degrees [-DEFAULT_ANGLE_RANGE, DEFAULT_ANGLE_RANGE] -> if FS is set to +/- 0.5 g, then a maximum of 20 degrees should be selected
#define DEFAULT_FOLDER "dec_tree"   // default folder name

#define MAX_RESULTS 255 			// maximum number of nodes (results) is 256 per decision tree (512 is the total maximum);
									// 255 consists of 127 negative values, 127 positive values and zero

#define MIN_ANGLE_RANGE 2			// minimum configurable angle range
#define MAX_ANGLE_RANGE 90			// maximum configurable angle range

#define MAX_FOLDER_NAME_LEN 64 		// for folder name definition
#define MAX_STRING_LEN 1024 		// for output buffer
#define MAX_SPACE_LEN (128 * 4)		// four chars "|   "

#define FEATURE_1 "mean_x" 	// define the attribute name of the MLC feature 1 (F1_MEAN_on_ACC_X) used in the decision tree text file
#define FEATURE_2 "mean_y" 	// define the attribute name of the MLC feature 2 (F1_MEAN_on_ACC_Y) used in the decision tree text file

#define DEG_TO_RAD ((float)M_PI / 180.0f)

// typedef enum for is_valid function
typedef enum
{
	NUMBER,
	NAME
} chck_t;

// possible errors when parsing the program input arguments
enum
{
	ERR_NONE = 0,
	ERR_ANGLE_NAN,
	ERR_ANGLE_RANGE,
	ERR_ANGLE_LEN,
	ERR_FOLDER_NAME,
	ERR_FOLDER_NAME_LEN,
	ERR_UNKNOWN_OPTION,
	ERR_UNKNOWN,
} opt_errs;

// function prototypes
static void process_args(int argc, char **argv, uint8_t *angle_range, char *folder_name);
static uint8_t is_valid(chck_t type, char *str, uint8_t len);
static void indent(char *str, uint16_t depth);

// main function
int main(int argc, char **argv)
{
	FILE *fp;

	uint16_t depth = 0;
	int status;
	uint8_t i, j;

	uint8_t angle_range;
	float ang_sensitivity;

	char folder_name[MAX_FOLDER_NAME_LEN];
	char out_buffer[MAX_STRING_LEN];
	char space_buffer[MAX_SPACE_LEN];

	float threshold_arr[MAX_RESULTS]; 	// Threshold array has only MAX_RESULTS-1 useful values (the last one is out of range)
	uint8_t result_arr[MAX_RESULTS];
	char stmp[75];						// Temporary string for labels used in the x and y axis cycle

	angle_range = DEFAULT_ANGLE_RANGE;
	memset(folder_name, '\0', MAX_FOLDER_NAME_LEN);
	strcpy(folder_name, DEFAULT_FOLDER);

	// set parameters based on the input arguments of the program
	process_args(argc, argv, &angle_range, folder_name);

	ang_sensitivity = ((2.0f * (float)angle_range) / ((float)MAX_RESULTS - 1.0f));

	// print information about the script configuration - for the MLC Configuration in Unico
	printf("\r\nNumber of results generated per decision tree: \t\t\t%d\r\n", MAX_RESULTS);
	printf("Selected range: \t\t\t\t\t\t[-%d, %d] deg\r\n", angle_range, angle_range);
	printf("Calculated angular sensitivity: \t\t\t\t%f deg/LSB\r\n\r\n", ang_sensitivity);

	printf("The attribute name used in the decision tree file for feature: \r\n\t1. Feature 1 (F1_MEAN_...): \t\t\t\t\'%s\'\r\n\t2. Feature 2 (F2_MEAN_...): \t\t\t\t\'%s\'\r\n\r\n\r\n", FEATURE_1, FEATURE_2);

	/********************************************************/
	// create two temporary arrays: with threshold values and with MLC results
	for (i = 0; i < MAX_RESULTS; i++)
	{
		// Create an array of thresholds (sin[deg->rad] / 4)
		threshold_arr[i] = sinf((-(angle_range - (ang_sensitivity / 2.0f)) + (ang_sensitivity * i)) * DEG_TO_RAD) * 4.0f;

		// Create an array of MLC results
		result_arr[i] = (int8_t)(-((MAX_RESULTS - 1) / 2) + i);
	}

	/********************************************************/
	// print the array of results - used to generate MLC in Unico:
	printf("An array of Results for the MLC Configuration in Unico:\r\n---\r\n");

	for (i = (MAX_RESULTS - 1) / 2; i < MAX_RESULTS; i++)
		printf("%d; ", result_arr[i]);

	for (i = 0; i < (256 - MAX_RESULTS); i++)
		printf("; ");

	for (i = 0; i < ((MAX_RESULTS - 1) / 2); i++)
	{
		if (i < (((MAX_RESULTS - 1) / 2) - 1))
			printf("%d; ", result_arr[i]);
		else
			printf("%d\r\n---\r\n\r\n", result_arr[i]);
	}


	/********************************************************/
	// Make a folder for decision tree text files
	// memset(stmp, 0 , sizeof(stmp));
	sprintf(stmp,"./%s", folder_name);

	status = mkdir(stmp, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	if (status != 0 && errno != EEXIST)
	{
		printf("ERROR: Folder \"%s\" could not be created\r\n", folder_name);
		exit(EXIT_FAILURE);
	}

	// Create two decision trees: for x and y axis
	for (i = 0; i < 2; i++)
	{
		sprintf(stmp,"./%s/DT%d.txt", folder_name, i + 1);

		// open/create a file
		printf("Opening/creating the data file \"%s\"...\r\n", stmp);

		fp = fopen(stmp, "w+");
		if (fp == NULL)
		{
			printf("ERROR: File (\"%s\") could not be opened!\r\n", stmp);
			exit(EXIT_FAILURE);
		}

		// Define the attribute name of the used MLC feature (MEAN)
		if (i == 0)
			strcpy(stmp, FEATURE_1);
		else
			strcpy(stmp, FEATURE_2);

		// Print first two lines of the decision tree
		fprintf(fp, "%s <= %0.6f: %d\r\n", stmp, threshold_arr[0], result_arr[0]);
		fprintf(fp, "%s > %0.6f\r\n", stmp, threshold_arr[0]);

		// Print the rest of the decision tree
		for (depth = 1; depth <= (MAX_RESULTS - 2); depth++)
		{
			// check the depth
			if (depth > (MAX_SPACE_LEN / 2))
			{
				fprintf(stderr, "ERROR: Unexpected depth of the decision tree\r\n");
				exit(EXIT_FAILURE);
			}

			// Print two lines of the decision tree in required format
			for (j = 0; j < 2; j++)
			{
				memset(out_buffer, 0 , sizeof(out_buffer));
				memset(space_buffer, 0 , sizeof(space_buffer));

				// Set indentation based on the depth
				indent(space_buffer, depth);

				if (depth >= (MAX_RESULTS - 2))
				{
					fprintf(fp, "%s%s <= %0.6f: %d\r\n", space_buffer, stmp, threshold_arr[depth], result_arr[depth]);
					fprintf(fp, "%s%s > %0.6f: %d\r\n", space_buffer, stmp, threshold_arr[depth], result_arr[depth + 1]);
					break;
				}
				else
				{
					if (j == 0)
						fprintf(fp, "%s%s <= %0.6f: %d\r\n", space_buffer, stmp, threshold_arr[depth], result_arr[depth]);
					else
						fprintf(fp, "%s%s > %0.6f\r\n", space_buffer, stmp, threshold_arr[depth]);
				}
			}
		}

		/********************************************************/
		// Print decision tree information
		fprintf(fp, "\r\nNumber of Leaves  : \t%d\r\n\r\n", MAX_RESULTS);
		fprintf(fp, "Size of the tree : \t%d ", (((MAX_RESULTS - 1) * 2) + 1));

		printf("Decision Tree (%d/2) has been successfully created\r\n", i + 1);

		sprintf(stmp,"./%s/DT%d.txt", folder_name, i + 1);
		printf("Closing the file \"%s\"...\r\n\r\n", stmp);
		fclose(fp);
	}

	printf("Done\r\n");

	exit(EXIT_SUCCESS);
}

// Set indentation of current line
static void indent(char *str, uint16_t depth)
{
	char separator[] = "|   ";
	uint16_t i;

	for (i = 0; i < depth; i++)
		strcat(str, separator);
}

// Process any input arguments of the program
static void process_args(int argc, char **argv, uint8_t *angle_range, char *folder_name)
{
	int option;
	int angle_range_tmp;
	uint8_t err_flag, err_occured;

	err_flag = ERR_NONE;
	angle_range_tmp = 0;
	err_occured = 0;

	// get all arguments
	while ((option = getopt(argc, argv, OPT_STR)) != -1)
	{
		switch (option)
		{
		case 'h': // help
			printf("\r\n\r\n");
			// print help message
			printf(HELP, argv[0], USAGE_MSG, MIN_ANGLE_RANGE, MAX_ANGLE_RANGE, FORBIDDEN_FOLDER_NAME);
			exit(EXIT_SUCCESS);
			break;
		case 'a': // set angle range
			if (strlen(optarg) > powf(2.0f, (sizeof(uint8_t) * 8.0f)))
			{
				err_flag = ERR_ANGLE_LEN;
			}
			else
			{
				// check that the input argument is valid
				if (is_valid(NUMBER, optarg, strlen(optarg)) != 0)
				{
					// convert the input string into integer
					angle_range_tmp = atoi(optarg);

					if (angle_range_tmp < MIN_ANGLE_RANGE || angle_range_tmp > MAX_ANGLE_RANGE)
						err_flag = ERR_ANGLE_RANGE;
					else
						// if the input value is inside the expected range: save it into 'angle_range' variable
						*angle_range = angle_range_tmp;
				}
				else
				{
					err_flag = ERR_ANGLE_NAN;
				}
			}
			break;
		case 'o': // set output folder
			if (strlen(optarg) > MAX_FOLDER_NAME_LEN)
			{
				err_flag = ERR_FOLDER_NAME_LEN;
			}
			else
			{
				// check that the input argument is valid
				if (is_valid(NAME, optarg, strlen(optarg)) != 0)
				{
					memset(folder_name, '\0', MAX_FOLDER_NAME_LEN);
					strcpy(folder_name, optarg);
				}
				else
				{
					err_flag = ERR_FOLDER_NAME;
				}
			}
			break;
		case ':': // argument missing
			if (optopt == 'a')
			{
				err_flag = ERR_ANGLE_NAN;
			}
			else if (optopt == 'o')
			{
				err_flag = ERR_FOLDER_NAME;
			}
			else
			{
				err_flag = ERR_UNKNOWN;
			}
			break;
		default: /* '?' */ // unknown error
			err_flag = ERR_UNKNOWN_OPTION;
		}

		// if there is any error then print the corresponding error message
		switch (err_flag)
		{
		case ERR_NONE:
			break;
		case ERR_ANGLE_NAN:
		case ERR_ANGLE_RANGE:
			fprintf(stderr, "Option '-a' requires an integer argument in range from %d to %d [deg].\r\n", MIN_ANGLE_RANGE, MAX_ANGLE_RANGE);
			break;
		case ERR_ANGLE_LEN:
			fprintf(stderr, "Argument of the option '-a' is too long. It requires an integer argument in range from %d to %d [deg].\r\n", MIN_ANGLE_RANGE, MAX_ANGLE_RANGE);
			break;
		case ERR_FOLDER_NAME:
			fprintf(stderr, "Option '-o' requires an argument that does not contain any of the following characters:\r\n%s\r\n", FORBIDDEN_FOLDER_NAME);
			break;
		case ERR_FOLDER_NAME_LEN:
			fprintf(stderr, "Argument of the option '-o' (folder name) is too long.\r\n");
			break;
		case ERR_UNKNOWN_OPTION:
			if (isprint(optopt))
			{
				if(optopt == '?')
					fprintf (stderr, "Unknown option entered.\r\n");
				else
					fprintf (stderr, "Unknown option '-%c'.\r\n", optopt);
			}
			else
			{
				fprintf (stderr, "Unknown option character `\\x%x'.\r\n", optopt);
			}
			break;
		default:
			fprintf(stderr, "An Unknown Error Has Occurred\r\n");
		}

		if (err_flag != ERR_NONE)
		{
			err_flag = ERR_NONE;
			err_occured = 1;
		}
	}

	if (err_occured)
	{
		fprintf(stderr, "USAGE: %s.exe %s", argv[0], USAGE_MSG);
		exit(EXIT_FAILURE);
	}
}

// check the option argument
static uint8_t is_valid(chck_t type, char *str, uint8_t len)
{
	int i;
	int (*fp)(int);
	const char fbd_chars[] = FORBIDDEN_FOLDER_NAME;

	if (type == NAME) // argument type: NAME
	{
		// check that the input argument does not contain forbidden characters
		if (strpbrk(str, fbd_chars) != NULL)
			return 0;

		fp = isprint; // set function pointer = isprint()
	}
	else // argument type: NUMBER
	{
		fp = isdigit; // set function pointer = isdigit()
	}

	// check that all the characters are numbers or printable characters -> depending to the selected argument type (used function)
	for (i = 0; i < len; i++)
	{
		if (fp(str[i]) == 0)
			return 0;
	}

	return 1;
}

