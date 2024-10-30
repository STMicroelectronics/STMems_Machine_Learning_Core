from typing import List, Optional
from dataclasses import dataclass
import subprocess
import logging
import sys
import os
import re


MLC_TOOL_EXECUTABLE: str = "mlc_configuration_tool"
if sys.platform == "win32":
    MLC_TOOL_EXECUTABLE += ".exe"
GEN_ARFF_FILENAME: str = "gen_arff.txt"
GEN_UCF_FILENAME: str = "gen_ucf.txt"


@dataclass
class MLCFeature:
    name: str
    input: str
    threshold: Optional[float] = None
    param_list: Optional[List[float]] = None


@dataclass
class MLCFilter:
    filter_id: str
    name: str
    coef_b1: float = 0.5
    coef_b2: float = -0.5
    coef_b3: float = 0.0
    coef_a2: float = 0.0
    coef_a3: float = 0.0
    coef_gain: float = 1.0


def get_devices() -> List[str]:
    return [
        "ASM330LHB",
        "ASM330LHBG1",
        "ASM330LHHX",
        "ASM330LHHXG1",
        "IIS2ICLX",
        "ISM330BX",
        "ISM330DHCX",
        "LIS2DUX12",
        "LIS2DUXS12",
        "LSM6DSO32X",
        "LSM6DSOX",
        "LSM6DSRX",
        "LSM6DSV16BX",
        "LSM6DSV16X",
        "LSM6DSV32X",
        "ST1VAFE3BX",
        "ST1VAFE6AX",
    ]


def get_mlc_odr(device_name) -> Optional[List[str]]:
    mlc_odr = None
    if device_name in ["LSM6DSV16X", "LSM6DSV32X", "ST1VAFE6AX"]:
        mlc_odr = ["15 Hz", "30 Hz", "60 Hz", "120 Hz", "240 Hz"]
    elif device_name in ["LSM6DSV16BX", "ISM330BX"]:
        mlc_odr = ["15 Hz", "30 Hz", "60 Hz", "120 Hz", "240 Hz", "480 Hz",
                   "960 Hz"]
    elif device_name in ["LIS2DUX12", "LIS2DUXS12"]:
        mlc_odr = ["12.5 Hz", "25 Hz", "50 Hz", "100 Hz", "200 Hz"]
    elif device_name == "ST1VAFE3BX":
        mlc_odr = ["12.5 Hz", "25 Hz", "50 Hz", "100 Hz", "200 Hz", "400 Hz",
                   "800 Hz"]
    elif device_name in get_devices():
        mlc_odr = ["12.5 Hz", "26 Hz", "52 Hz", "104 Hz"]
    else:
        logging.error("ERROR: device '%s' not supported", device_name)
    return mlc_odr


def get_mlc_input_type(device_name) -> Optional[List[str]]:
    mlc_input_type = None
    if device_name == "IIS2ICLX":
        mlc_input_type = ["accelerometer_only",
                          "accelerometer+external_sensor"]
    elif device_name == "LIS2DUX12":
        mlc_input_type = ["accelerometer_only",
                          "accelerometer+temperature"]
    elif device_name == "LIS2DUXS12":
        mlc_input_type = ["accelerometer_only",
                          "accelerometer+temperature/qvar"]
    elif device_name == "ST1VAFE3BX":
        mlc_input_type = ["accelerometer_only",
                          "accelerometer+vafe"]
    elif device_name in ["LSM6DSV16X", "LSM6DSV32X"]:
        mlc_input_type = ["accelerometer_only",
                          "accelerometer+gyroscope",
                          "accelerometer+external_sensor/qvar",
                          "accelerometer+gyroscope+external_sensor/qvar"]
    elif device_name in ["LSM6DSV16BX"]:
        mlc_input_type = ["accelerometer_only",
                          "accelerometer+gyroscope",
                          "accelerometer+qvar",
                          "accelerometer+gyroscope+qvar"]
    elif device_name in ["ST1VAFE6AX"]:
        mlc_input_type = ["accelerometer_only",
                          "accelerometer+gyroscope",
                          "accelerometer+vafe",
                          "accelerometer+gyroscope+vafe"]
    elif device_name in get_devices():
        mlc_input_type = ["accelerometer_only",
                          "accelerometer+gyroscope",
                          "accelerometer+external_sensor",
                          "accelerometer+gyroscope+external_sensor"]
    else:
        logging.error("ERROR: device '%s' not supported", device_name)
    return mlc_input_type


def get_mlc_inputs(input_type) -> Optional[List[str]]:
    mlc_inputs = []
    input_types = input_type.split("+")
    if any(x in input_types for x in ["accelerometer_only", "accelerometer"]):
        mlc_inputs += ["Acc_X", "Acc_Y", "Acc_Z", "Acc_V", "Acc_V2"]
    if "gyroscope" in input_types:
        mlc_inputs += ["Gyr_X", "Gyr_Y", "Gyr_Z", "Gyr_V", "Gyr_V2"]
    if "external_sensor/qvar" in input_types:
        mlc_inputs += ["Ext/Qvar_X", "Ext/Qvar_Y", "Ext/Qvar_Z", "Ext/Qvar_V",
                       "Ext/Qvar_V2"]
    elif "external_sensor" in input_types:
        mlc_inputs += ["Ext_X", "Ext_Y", "Ext_Z", "Ext_V", "Ext_V2"]
    elif "temperature/qvar" in input_types:
        mlc_inputs += ["Temp/Qvar_X"]
    elif "temperature" in input_types:
        mlc_inputs += ["Temp_X"]
    elif "qvar" in input_types:
        mlc_inputs += ["Qvar_X"]
    elif "vafe" in input_types:
        mlc_inputs += ["vAFE_X"]
    if len(mlc_inputs) == 0:
        logging.error("ERROR: input type '%s' not supported", input_type)
        return None
    return mlc_inputs


def get_accelerometer_fs(device_name) -> Optional[List[str]]:
    accelerometer_fs = None
    if device_name in ["LSM6DSO32X", "LSM6DSV32X"]:
        accelerometer_fs = ["4 g", "8 g", "16 g", "32 g"]
    elif device_name == "IIS2ICLX":
        accelerometer_fs = ["0.5 g", "1 g", "2 g", "3 g"]
    elif device_name == "ISM330BX":
        accelerometer_fs = ["2 g", "4 g", "8 g"]
    elif device_name in get_devices():
        accelerometer_fs = ["2 g", "4 g", "8 g", "16 g"]
    else:
        logging.error("ERROR: device '%s' not supported", device_name)
    return accelerometer_fs


def get_accelerometer_odr(device_name) -> Optional[List[str]]:
    accelerometer_odr = None
    if device_name == "IIS2ICLX":
        accelerometer_odr = ["12.5 Hz", "26 Hz", "52 Hz", "104 Hz",
                             "208 Hz", "416 Hz", "833 Hz"]
    elif device_name in ["LSM6DSRX", "ISM330DHCX", "ASM330LHHX",
                         "ASM330LHHXG1", "ASM330LHB", "ASM330LHBG1",
                         "IIS2ICLX"]:
        accelerometer_odr = ["12.5 Hz", "26 Hz", "52 Hz", "104 Hz", "208 Hz",
                             "416 Hz", "833 Hz", "1666 Hz", "3332 Hz",
                             "6667 Hz"]
    elif device_name == "ISM330BX":
        accelerometer_odr = ["15 Hz", "30 Hz", "60 Hz", "120 Hz", "240 Hz",
                             "480 Hz", "960 Hz", "1920 Hz", "3840 Hz"]
    elif device_name in ["LSM6DSV16X", "LSM6DSV32X", "LSM6DSV16BX",
                         "ST1VAFE6AX"]:
        accelerometer_odr = ["15 Hz", "30 Hz", "60 Hz", "120 Hz", "240 Hz",
                             "480 Hz", "960 Hz", "1920 Hz", "3840 Hz",
                             "7680 Hz"]
    elif device_name in ["LIS2DUX12", "LIS2DUXS12", "ST1VAFE3BX"]:
        accelerometer_odr = ["12.5 Hz", "25 Hz", "50 Hz", "100 Hz", "200 Hz",
                             "400 Hz", "800 Hz"]
    if device_name in get_devices():
        accelerometer_odr = ["12.5 Hz", "26 Hz", "52 Hz", "104 Hz", "208 Hz",
                             "416 Hz", "833 Hz", "1666 Hz", "3332 Hz",
                             "6664 Hz"]
    else:
        logging.error("ERROR: device '%s' not supported", device_name)
    return accelerometer_odr


def get_gyroscope_fs(device_name) -> Optional[List[str]]:
    gyroscope_fs = None
    if device_name in ["LSM6DSRX", "ISM330DHCX", "ASM330LHHX",
                       "ASM330LHHXG1", "ASM330LHB", "ASM330LHBG1", "IIS2ICLX"]:
        gyroscope_fs = ["125 dps", "250 dps", "500 dps", "1000 dps",
                        "2000 dps", "4000 dps"]
    elif device_name in ["LSM6DSOX", "LSM6DSO32X"]:
        gyroscope_fs = ["125 dps", "250 dps", "500 dps", "1000 dps",
                        "2000 dps"]
    elif device_name in (
        set(get_devices()) - {"IIS2ICLX", "LIS2DUX12", "LIS2DUXS12", "ST1VAFE3BX"}
    ):
        gyroscope_fs = ["125 dps", "250 dps", "500 dps", "1000 dps",
                        "2000 dps", "4000 dps"]
    else:
        logging.error("ERROR: device '%s' not supported", device_name)
    return gyroscope_fs


def get_gyroscope_odr(device_name) -> Optional[List[str]]:
    gyroscope_odr = None
    if device_name in ["LSM6DSRX", "ISM330DHCX", "ASM330LHHX",
                       "ASM330LHHXG1", "ASM330LHB", "ASM330LHBG1", "IIS2ICLX"]:
        gyroscope_odr = ["12.5 Hz", "26 Hz", "52 Hz", "104 Hz", "208 Hz",
                         "416 Hz", "833 Hz", "1666 Hz", "3332 Hz", "6667 Hz"]
    elif device_name == "ISM330BX":
        gyroscope_odr = ["15 Hz", "30 Hz", "60 Hz", "120 Hz", "240 Hz",
                         "480 Hz", "960 Hz", "1920 Hz", "3840 Hz"]
    elif device_name in ["LSM6DSV16X", "LSM6DSV32X", "LSM6DSV16BX",
                         "ST1VAFE6AX"]:
        gyroscope_odr = ["15 Hz", "30 Hz", "60 Hz", "120 Hz", "240 Hz",
                         "480 Hz", "960 Hz", "1920 Hz", "3840 Hz", "7680 Hz"]
    elif device_name in (
        set(get_devices()) - {"IIS2ICLX", "LIS2DUX12", "LIS2DUXS12", "ST1VAFE3BX"}
    ):
        gyroscope_odr = ["12.5 Hz", "26 Hz", "52 Hz", "104 Hz", "208 Hz",
                         "416 Hz", "833 Hz", "1666 Hz", "3332 Hz",
                         "6664 Hz"]
    else:
        logging.error("ERROR: device '%s' not supported", device_name)
    return gyroscope_odr


def get_filter_names(input_type) -> Optional[List[str]]:
    mlc_inputs = get_mlc_inputs(input_type)
    if mlc_inputs is None:
        logging.error("ERROR: input type '%s' not supported", input_type)
        return None
    mlc_filters = []
    for filt in ["HP", "BP", "IIR1", "IIR2"]:
        for inp in mlc_inputs:
            if inp.endswith("_X"):
                inp = inp.replace("_X", "_XYZ")
            elif any(inp.endswith(x) for x in ["_Y", "_Z"]):
                continue
            mlc_filters.append(f"{filt}_{inp}")
    return mlc_filters


def get_feature_names(device_name) -> Optional[List[str]]:
    if device_name not in get_devices():
        logging.error("ERROR: device name '%s' not supported", device_name)
        return None
    feature_list = [
        "MEAN",
        "ABS_MEAN",
        "VARIANCE",
        "ABS_VARIANCE",
        "ENERGY",
        "PEAK_TO_PEAK",
        "ABS_PEAK_TO_PEAK",
        "ZERO_CROSSING",
        "POSITIVE_ZERO_CROSSING",
        "NEGATIVE_ZERO_CROSSING",
        "PEAK_DETECTOR",
        "POSITIVE_PEAK_DETECTOR",
        "NEGATIVE_PEAK_DETECTOR",
        "MINIMUM",
        "ABS_MINIMUM",
        "MAXIMUM",
        "ABS_MAXIMUM",
    ]
    if device_name in ["LSM6DSV16X", "LSM6DSV32X", "LSM6DSV16BX", "ISM330BX",
                       "ST1VAFE6AX", "LIS2DUX12", "LIS2DUXS12"]:
        feature_list += ["RECURSIVE_MEAN_RMS_VARIANCE",
                         "RECURSIVE_MAX_MIN_PEAKTOPEAK"]
    return feature_list


def arff_generator(
    device_name: str,
    datalogs: List[str],
    results: List[int],
    mlc_odr: str,
    input_type: str,
    accelerometer_fs: str,
    accelerometer_odr: str,
    gyroscope_fs: str,
    gyroscope_odr: str,
    n_decision_trees: int,
    window_length: int,
    filters_list: List[MLCFilter],
    features_list: List[MLCFeature],
    arff_filename: str,
    current_directory: str,
) -> None:
    if device_name not in get_devices():
        logging.error("ERROR: device '%s' not supported", device_name)
        return

    if len(features_list) == 0:
        logging.error("ERROR: features_list empty")
        return

    input_names = get_mlc_inputs(input_type)
    if input_names is None:
        return

    filter_names = get_filter_names(input_type)
    if filter_names is None:
        return

    feature_names = get_feature_names(device_name)
    if feature_names is None:
        return

    gen_arff_path = os.path.join(current_directory, GEN_ARFF_FILENAME)
    with open(gen_arff_path, "w", encoding="ascii") as f:
        for i, datalog in enumerate(datalogs):
            if os.path.isfile(datalog):
                f.write(f"{i},0,{results[i]},{datalog}\n")
            else:
                logging.error("\nERROR: The following file does not exist: %s",
                              datalog)

        f.write("configurationStarted\n")
        f.write(device_name + "\n")
        f.write(mlc_odr + "\n")
        f.write("<input_type>" + input_type + ",")

        # accelerometer settings
        f.write(accelerometer_fs + ",")
        f.write(accelerometer_odr + ",")

        # gyroscope settings
        if "gyroscope" in input_type:
            f.write(gyroscope_fs + ",")
            f.write(gyroscope_odr + ",")

        f.write("\n")
        f.write(f"{n_decision_trees}\n")  # Number of decision trees
        f.write(f"{window_length}\n")  # Window length (from 1 to 255)

        # Filters
        for i, filt in enumerate(filters_list):
            if filt.name not in filter_names:
                logging.error("ERROR: filter '%s' not supported", filt.name)
                return
            f.write(f"<{filt.filter_id}>{filt.name}\n")
            if "BP" in filt.name:
                f.write("<coefficients>"
                        f"{filt.coef_a2},{filt.coef_a3},{filt.coef_gain}\n")
            elif "IIR1" in filt.name:
                f.write("<coefficients>"
                        f"{filt.coef_b1},{filt.coef_b2},{filt.coef_a2}\n")
            elif "IIR2" in filt.name:
                f.write("<coefficients>"
                        f"{filt.coef_b1},{filt.coef_b2},{filt.coef_b3},"
                        f"{filt.coef_a2},{filt.coef_a3}\n")
        f.write("<filter>" + "END_FILTERS" + "\n")

        # Features
        for i, feat in enumerate(features_list):
            if feat.name not in feature_names:
                logging.error("ERROR: feature '%s' not supported", feat.name)
                return

            feat_input, *filter_id = feat.input.split("_filter_")
            if feat_input not in input_names:
                logging.error("ERROR: feature input '%s' not supported",
                              feat.input)
                return

            if len(filter_id) > 0:
                id_val = int(filter_id[0])
                if id_val > len(filters_list):
                    logging.error("ERROR: feature '%s' is using a filter id "
                                  "value greater that the number of filters "
                                  "'%d'", feat.name, len(filters_list))
                    return

            f.write("<feature>" + feat.name + "_" + feat.input + "\n")
            if any(x in feat.name for x in ["ZERO_CROSSING", "PEAK_DETECTOR"]):
                f.write(f"<threshold>{feat.threshold}\n")
            if any(x in feat.name for x in ["RECURSIVE_MEAN_RMS_VARIANCE",
                                            "RECURSIVE_MAX_MIN_PEAKTOPEAK"]):
                f.write(f"<paramList>{feat.param_list}\n")

        f.write("<feature>" + "END_FEATURES" + "\n")
        f.write(arff_filename + "\n")
        f.write("EXIT_APP")
        f.close()

        logging.info("\nCalling MLC app for features computation and ARFF "
                     "generation...")
        args = [
            MLC_TOOL_EXECUTABLE,
            f"-{device_name}",
            "-MLC_script", gen_arff_path,
        ]
        proc = subprocess.run(
            args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=False)
        if proc.returncode == 0:
            logging.info("\nARFF generated successfully: %s", arff_filename)
        else:
            logging.error("\n%s", proc.stderr.decode())


def ucf_generator(
    device_name: str,
    arff_filename: str,
    dectree_filenames: List[str],
    result_names: List[str],
    result_values: List[List[int]],
    metaclassifier_values: List[str],
    ucf_filename: str,
    current_directory: str,
) -> None:
    gen_arff_path = os.path.join(current_directory, GEN_ARFF_FILENAME)
    gen_ucf_path = os.path.join(current_directory, GEN_UCF_FILENAME)

    for i in range(0, 8):
        if not result_names[i]:
            break
    n_decision_trees = i
    if n_decision_trees != len(dectree_filenames):
        logging.error("\nERROR: wrong number of decision trees detected. "
                      "Please check result_names and dectree_filenames")

    results_dt1 = result_names[0]
    results_dt2 = result_names[1]
    results_dt3 = result_names[2]
    results_dt4 = result_names[3]
    results_dt5 = result_names[4]
    results_dt6 = result_names[5]
    results_dt7 = result_names[6]
    results_dt8 = result_names[7]

    result_values_dt1 = result_values[0]
    result_values_dt2 = result_values[1]
    result_values_dt3 = result_values[2]
    result_values_dt4 = result_values[3]
    result_values_dt5 = result_values[4]
    result_values_dt6 = result_values[5]
    result_values_dt7 = result_values[6]
    result_values_dt8 = result_values[7]

    metaclassifier1_values = metaclassifier_values[0]
    metaclassifier2_values = metaclassifier_values[1]
    metaclassifier3_values = metaclassifier_values[2]
    metaclassifier4_values = metaclassifier_values[3]
    metaclassifier5_values = metaclassifier_values[4]
    metaclassifier6_values = metaclassifier_values[5]
    metaclassifier7_values = metaclassifier_values[6]
    metaclassifier8_values = metaclassifier_values[7]

    # Prepare file for UCF configuration
    inp = open(gen_arff_path, "r", encoding="ascii")
    out = open(gen_ucf_path, "w", encoding="ascii")
    config_started = False
    config_stopped = False

    for line in inp:
        if config_started is False:
            if line.rstrip() == "configurationStarted":
                config_started = True
                out.write(line)
            continue

        if line.rstrip() == "<feature>END_FEATURES":
            config_stopped = True
            out.write(line)

            # read ARFF to get feature names
            with open(arff_filename, mode="r", encoding="ascii") as arff_file:
                lines_of_arff = arff_file.readlines()
                for line_of_arff in lines_of_arff:
                    if any(
                        line_of_arff.startswith(x)
                        for x in ["@attribute F", "@ATTRIBUTE F"]
                    ):
                        line_of_arff_splitted = line_of_arff.split()
                        out.write(line_of_arff_splitted[1] + "\n")

            # read ARFF to get class names
            with open(arff_filename, mode="r", encoding="ascii") as arff_file:
                lines_of_arff = arff_file.readlines()
                for line_of_arff in lines_of_arff:
                    if line_of_arff.startswith("@attribute class"):
                        classes_string = line_of_arff[
                            line_of_arff.find("{") + 1:
                            line_of_arff.find("}")
                        ]
                        classes_list = classes_string.split(", ")
                        logging.info("Classes from ARFF: %s",
                                     ", ".join(classes_list))

        elif config_stopped is False:
            if line.strip() != "":
                out.write(line)

    inp.close()
    out.close()

    f = open(gen_ucf_path, "a+", encoding="ascii")

    if device_name in ["LSM6DSRX", "ISM330DHCX", "ASM330LHHX", "ASM330LHHXG1",
                       "ASM330LHB", "ASM330LHBG1", "IIS2ICLX"]:
        max_dectree_classes = 256
    elif device_name in get_devices():
        max_dectree_classes = 16
    else:
        logging.error("ERROR: device '%s' not supported", device_name)
        return

    # Results (classes)
    result_values_dt1_str = ""
    result_values_dt2_str = ""
    result_values_dt3_str = ""
    result_values_dt4_str = ""
    result_values_dt5_str = ""
    result_values_dt6_str = ""
    result_values_dt7_str = ""
    result_values_dt8_str = ""

    for i in range(0, max_dectree_classes):
        if i > 0:
            result_values_dt1_str += " ; "
            result_values_dt2_str += " ; "
            result_values_dt3_str += " ; "
            result_values_dt4_str += " ; "
            result_values_dt5_str += " ; "
            result_values_dt6_str += " ; "
            result_values_dt7_str += " ; "
            result_values_dt8_str += " ; "

        if i in result_values_dt1:
            result_values_dt1_str += results_dt1[result_values_dt1.index(i)]
        if i in result_values_dt2:
            result_values_dt2_str += results_dt2[result_values_dt2.index(i)]
        if i in result_values_dt3:
            result_values_dt3_str += results_dt3[result_values_dt3.index(i)]
        if i in result_values_dt4:
            result_values_dt4_str += results_dt4[result_values_dt4.index(i)]
        if i in result_values_dt5:
            result_values_dt5_str += results_dt5[result_values_dt5.index(i)]
        if i in result_values_dt6:
            result_values_dt6_str += results_dt6[result_values_dt6.index(i)]
        if i in result_values_dt7:
            result_values_dt7_str += results_dt7[result_values_dt7.index(i)]
        if i in result_values_dt8:
            result_values_dt8_str += results_dt8[result_values_dt8.index(i)]

    f.write(result_values_dt1_str + "\n")
    if n_decision_trees >= 2:
        f.write(result_values_dt2_str + "\n")
    if n_decision_trees >= 3:
        f.write(result_values_dt3_str + "\n")
    if n_decision_trees >= 4:
        f.write(result_values_dt4_str + "\n")
    if n_decision_trees >= 5:
        f.write(result_values_dt5_str + "\n")
    if n_decision_trees >= 6:
        f.write(result_values_dt6_str + "\n")
    if n_decision_trees >= 7:
        f.write(result_values_dt7_str + "\n")
    if n_decision_trees >= 8:
        f.write(result_values_dt8_str + "\n")

    # Decision tree files
    for i in range(n_decision_trees):
        f.write(dectree_filenames[i] + "\n")

    # Meta-classifiers
    f.write(metaclassifier1_values + "\n")
    if n_decision_trees >= 2:
        f.write(metaclassifier2_values + "\n")
    if n_decision_trees >= 3:
        f.write(metaclassifier3_values + "\n")
    if n_decision_trees >= 4:
        f.write(metaclassifier4_values + "\n")
    if n_decision_trees >= 5:
        f.write(metaclassifier5_values + "\n")
    if n_decision_trees >= 6:
        f.write(metaclassifier6_values + "\n")
    if n_decision_trees >= 7:
        f.write(metaclassifier7_values + "\n")
    if n_decision_trees >= 8:
        f.write(metaclassifier8_values + "\n")

    # UCF file
    f.write(ucf_filename + "\n")
    f.write("EXIT_APP")
    f.close()

    logging.info("\nCalling MLC app for .ucf file generation...")
    args = [
        MLC_TOOL_EXECUTABLE,
        f"-{device_name}",
        "-MLC_script",
        gen_ucf_path,
    ]
    proc = subprocess.run(
        args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=False)
    if proc.returncode == 0:
        logging.info("\n.ucf file generated successfully: %s", ucf_filename)
    else:
        logging.error("\n%s", proc.stderr.decode())


def h_generator(ucf_filename: str, h_filename: str) -> None:
    with open(ucf_filename, "r", encoding="ascii") as f:
        ucff = f.readlines()

    conf_data = ""
    conf_regex = r"Ac\s+([0-9,A-F]+)\s+([0-9,A-F]+)"
    for i, ucf in enumerate(ucff):
        res = re.search(conf_regex, ucf)
        if not isinstance(res, re.Match):
            continue
        if len(res.groups()) != 2:
            continue
        g1, g2 = res.groups()
        hline = "\n\t{" + f".address = 0x{g1}, .data = 0x{g2}" + ",}"
        if i < len(ucff) - 1:
            hline += ","
        conf_data += hline

    hstr = """
/*
******************************************************************************
configuration header file generated from ucf file
******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MLC_CONFIGURATION_H
#define MLC_CONFIGURATION_H

#ifdef __cplusplus
    extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#ifndef MEMS_UCF_SHARED_TYPES
#define MEMS_UCF_SHARED_TYPES

/** Common data block definition **/
typedef struct {
    uint8_t address;
    uint8_t data;
} ucf_line_t;

#endif /* MEMS_UCF_SHARED_TYPES */

/** Configuration array generated from Unico Tool **/
const ucf_line_t mlc_configuration[] = {%s
};

#ifdef __cplusplus
}
#endif

#endif /* MLC_CONFIGURATION_H */
            """ % conf_data

    with open(h_filename, "w", encoding="ascii") as hout:
        hout.write(hstr)

    logging.info("Header file successfully generated. %s  ->  %s",
                 ucf_filename, h_filename)
