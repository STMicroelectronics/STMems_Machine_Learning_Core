import os
import subprocess
from mlc_script_log import *
import external_tools
import re

class mlc_configurator:
	
    class mlc_feature(object):
        def __init__(self, name=None, input=None, threshold=0):
            self.name = name
            self.input = input
            self.threshold = threshold
            
    class mlc_filter: 
        def __init__(self, filter_id="filter_1", 
                     name=None, 
                     coef_b1=0.5, 
                     coef_b2=-0.5, 
                     coef_b3=0, 
                     coef_a2=0, 
                     coef_a3=0, 
                     coef_gain=1):
            self.filter_id = filter_id
            self.name = name
            self.coef_b1 = coef_b1
            self.coef_b2 = coef_b2
            self.coef_b3 = coef_b3
            self.coef_a2 = coef_a2
            self.coef_a3 = coef_a3
            self.coef_gain = coef_gain

    def get_devices(): 
        device_list = ["LSM6DSOX", "LSM6DSRX", "ISM330DHCX", "LSM6DSO32X", "IIS2ICLX"] 
        return device_list

    def get_mlc_odr( device_name ): 
        mlc_odr = ["12.5 Hz", "26 Hz", "52 Hz", "104 Hz"]
        return mlc_odr

    def get_mlc_input_type( device_name ): 
        if device_name == "IIS2ICLX":
            mlc_input_type = ["accelerometer_only"]
        else: 
            mlc_input_type = ["accelerometer_only", "accelerometer+gyroscope"]
        return mlc_input_type

    def get_mlc_inputs( device_name, input_type ): 
        mlc_inputs = []
        if input_type == "accelerometer_only":
            if device_name == "IIS2ICLX":
                mlc_inputs = ["Acc_X", "Acc_Y", "Acc_V", "Acc_V2"]
            else:
                mlc_inputs = ["Acc_X", "Acc_Y", "Acc_Z", "Acc_V", "Acc_V2"]
        elif input_type == "accelerometer+gyroscope":
            mlc_inputs = ["Acc_X", "Acc_Y", "Acc_Z", "Acc_V", "Acc_V2", 
                          "Gyr_X", "Gyr_Y", "Gyr_Z", "Gyr_V", "Gyr_V2"]
        return mlc_inputs

    def get_accelerometer_fs( device_name ):
        if device_name == "LSM6DSOX":
            accelerometer_fs = ["2 g", "4 g", "8 g", "16 g"]
        if device_name == "LSM6DSO32X":
            accelerometer_fs = ["4 g", "8 g", "16 g", "32 g"]
        elif device_name == "IIS2ICLX":
            accelerometer_fs = ["0.5 g", "1 g", "2 g", "3 g"]
        elif device_name == "LSM6DSRX" or device_name == "ISM330DHCX":
            accelerometer_fs = ["2 g", "4 g", "8 g", "16 g"]
        else:
            logging.error("ERROR: device \"" + device_name + "\" not supported")
        return accelerometer_fs

    def get_accelerometer_odr( device_name ):
        if device_name == "LSM6DSOX":
            accelerometer_odr = ["12.5 Hz", "26 Hz", "52 Hz", "104 Hz", "208 Hz", "416 Hz", "833 Hz", "1666 Hz", "3332 Hz", "6664 Hz"]
        elif device_name == "LSM6DSO32X":
            accelerometer_odr = ["12.5 Hz", "26 Hz", "52 Hz", "104 Hz", "208 Hz", "416 Hz", "833 Hz", "1666 Hz", "3332 Hz", "6664 Hz"]
        elif device_name == "IIS2ICLX":
            accelerometer_odr = ["12.5 Hz", "26 Hz", "52 Hz", "104 Hz", "208 Hz", "416 Hz", "833 Hz"]
        elif device_name == "LSM6DSRX" or device_name == "ISM330DHCX": 
            accelerometer_odr = ["12.5 Hz", "26 Hz", "52 Hz", "104 Hz", "208 Hz", "416 Hz", "833 Hz", "1666 Hz", "3332 Hz", "6667 Hz"]
        else:
            logging.error("ERROR: device \"" + device_name + "\" not supported")
        return accelerometer_odr

    def get_gyroscope_fs( device_name ):
        if device_name == "LSM6DSOX":
            gyroscope_fs = ["125 dps", "250 dps", "500 dps", "1000 dps", "2000 dps"]
        elif device_name == "LSM6DSO32X":
            gyroscope_fs = ["125 dps", "250 dps", "500 dps", "1000 dps", "2000 dps"]
        elif device_name == "LSM6DSRX" or device_name == "ISM330DHCX": 
            gyroscope_fs = ["125 dps", "250 dps", "500 dps", "1000 dps", "2000 dps", "4000 dps"]
        else:
            logging.error("ERROR: device \"" + device_name + "\" not supported")
        return gyroscope_fs

    def get_gyroscope_odr( device_name ):
        if device_name == "LSM6DSOX":
            gyroscope_odr = ["12.5 Hz", "26 Hz", "52 Hz", "104 Hz", "208 Hz", "416 Hz", "833 Hz", "1666 Hz", "3332 Hz", "6664 Hz"]
        elif device_name == "LSM6DSO32X":
            gyroscope_odr = ["12.5 Hz", "26 Hz", "52 Hz", "104 Hz", "208 Hz", "416 Hz", "833 Hz", "1666 Hz", "3332 Hz", "6664 Hz"]
        elif device_name == "LSM6DSRX" or device_name == "ISM330DHCX": 
            gyroscope_odr = ["12.5 Hz", "26 Hz", "52 Hz", "104 Hz", "208 Hz", "416 Hz", "833 Hz", "1666 Hz", "3332 Hz", "6667 Hz"]
        else:
            logging.error("ERROR: device \"" + device_name + "\" not supported")
        return gyroscope_odr

    def get_filter_names( input_type ):
        filter_names = []
        if input_type == "accelerometer_only":
            filter_names = ["HP_Acc_XYZ", "HP_Acc_V", "HP_Acc_V2",
                            "BP_Acc_XYZ", "BP_Acc_V", "BP_Acc_V2", 
                            "IIR1_Acc_XYZ", "IIR1_Acc_V", "IIR1_Acc_V2", 
                            "IIR2_Acc_XYZ", "IIR2_Acc_V", "IIR2_Acc_V2"]
        elif input_type == "accelerometer+gyroscope":
            filter_names = ["HP_Acc_XYZ", "HP_Acc_V", "HP_Acc_V2", "HP_Gyr_XYZ", "HP_Gyr_V",  "HP_Gyr_V2",
                            "BP_Acc_XYZ", "BP_Acc_V", "BP_Acc_V2", "BP_Gyr_XYZ", "BP_Gyr_V", "BP_Gyr_V2",
                            "IIR1_Acc_XYZ", "IIR1_Acc_V", "IIR1_Acc_V2", "IIR1_Gyr_XYZ", "IIR1_Gyr_V", "IIR1_Gyr_V2", 
                            "IIR2_Acc_XYZ", "IIR2_Acc_V", "IIR2_Acc_V2", "IIR2_Gyr_XYZ", "IIR2_Gyr_V", "IIR2_Gyr_V2"]
        return filter_names

    def get_feature_names():
        feature_names = ["MEAN", 
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
                         "ABS_MAXIMUM"]
        return feature_names

    def arff_generator( device_name, 
	                   datalogs, 
                       results,
                       mlc_odr, 
                       input_type, 
                       accelerometer_fs, 
                       accelerometer_odr, 
                       gyroscope_fs, 
                       gyroscope_odr, 
                       n_decision_trees, 
                       window_length, 
                       filters_list, 
                       features_list, 
                       arff_filename,
                       current_directory ):
                       
        if device_name not in mlc_configurator.get_devices():
            logging.error("ERROR: device \"" + device_name + "\" not supported")
            return
        
        if len(features_list) == 0:
            logging.error("ERROR: features_list empty")
            return

        config_for_ARFF_gen_filename = os.path.join(current_directory, "ARFF_generation.txt")

        with open(config_for_ARFF_gen_filename, "w") as f:
            for i in range(len(datalogs)):
                if os.path.isfile(datalogs[i]):
                    f.write("%d,0,%s,%s\n" % (i, results[i], datalogs[i]))
                else:
                    logging.error("\nERROR: The following file does not exist: " + datalogs[i])

            f.write("configurationStarted\n")
            f.write(device_name + "\n")
            f.write(mlc_odr + "\n")
            f.write("<input_type>" + input_type + ",") 

            # accelerometer settings
            f.write(accelerometer_fs +",")  
            f.write(accelerometer_odr + ",") 

            # gyroscope settings
            if "gyroscope" in input_type:
                f.write(gyroscope_fs + ",")  
                f.write(gyroscope_odr + ",")

            f.write('\n');
            f.write('%d\n' % (n_decision_trees))  ## Number of decision trees
            f.write('%d\n' % (window_length))  ## Window length (supported values: from 1 to 255)


            # Filters
            for i in range(len(filters_list)):
                if filters_list[i].name not in mlc_configurator.get_filter_names(input_type):
                    logging.error("ERROR: filter \"" + filters_list[i].name + "\" not supported")
                    return
                f.write("<"+ filters_list[i].filter_id +">" + filters_list[i].name + "\n")
                if "BP" in filters_list[i].name:
                    f.write("<coefficients>" + 
                            str(filters_list[i].coef_a2) + "," + 
                            str(filters_list[i].coef_a3) + "," + 
                            str(filters_list[i].coef_gain) + "\n")
                elif "IIR1" in filters_list[i].name:
                    f.write("<coefficients>" + 
                            str(filters_list[i].coef_b1) + "," + 
                            str(filters_list[i].coef_b2) + "," + 
                            str(filters_list[i].coef_a2) + "\n")
                elif "IIR2" in filters_list[i].name:
                    f.write("<coefficients>" + 
                            str(filters_list[i].coef_b1) + "," + 
                            str(filters_list[i].coef_b2) + "," + 
                            str(filters_list[i].coef_b3) + "," + 
                            str(filters_list[i].coef_a2) + "," + 
                            str(filters_list[i].coef_a3) + "\n")
            f.write("<filter>" + "END_FILTERS" + "\n") 

            # Features
            for i in range(len(features_list)):
                if features_list[i].name not in mlc_configurator.get_feature_names():
                    logging.error("ERROR: feature \"" + features_list[i].name + "\" not supported")
                    return
                if features_list[i].input not in mlc_configurator.get_mlc_inputs(device_name, input_type):
                    if "_filter_" not in features_list[i].input:
                        logging.error("ERROR: feature input \"" + features_list[i].input + "\" not supported")
                        return
                f.write("<feature>" + features_list[i].name + "_" + features_list[i].input + "\n")
                if "ZERO_CROSSING" in features_list[i].name or "PEAK_DETECTOR" in features_list[i].name:
                    f.write("<threshold>" + str(features_list[i].threshold) + "\n") 
            f.write("<feature>" + "END_FEATURES" + "\n") 
            f.write(arff_filename + "\n")
            f.write("EXIT_APP")
            f.close()

            logging.info("\nCalling MLC app for features computation and ARFF generation...")
            args = [external_tools.mlc_app, "-" + device_name, "-MLC_script", config_for_ARFF_gen_filename]
            mlc_app_ret_value = subprocess.call(args)
            if (mlc_app_ret_value == 0):
                logging.info("\nARFF generated successfully: " + arff_filename)
            elif (mlc_app_ret_value == 37):
                logging.error("\nERROR: too many features")
            elif (mlc_app_ret_value == 40):
                logging.error("\nERROR: 0 features configured")
            elif (mlc_app_ret_value == 36):
                logging.error("\nERROR: too many filters")
            elif (mlc_app_ret_value == 35):
                logging.error("\nERROR: data pattern cannot be loaded")
            else:
                logging.error("\nERROR: ", mlc_app_ret_value)

    def ucf_generator(  device_name, 
	                   arff_filename, 
                       dectree_filenames,
                       result_names, 
                       result_values, 
                       metaclassifier_values, 
                       ucf_filename,
                       current_directory ):

        config_for_ARFF_gen_filename = os.path.join(current_directory, "ARFF_generation.txt")
        config_for_UCF_gen_filename = os.path.join(current_directory, "UCF_generation.txt")

        for i in range(0,8): 
            if not result_names[i]:
                break
        n_decision_trees = i
        if n_decision_trees != len(dectree_filenames): 
           logging.error("\nERROR: wrong number of decision trees detected. Please check result_names and dectree_filenames")

        results_DT1 = result_names[0]
        results_DT2 = result_names[1]
        results_DT3 = result_names[2]
        results_DT4 = result_names[3]
        results_DT5 = result_names[4]
        results_DT6 = result_names[5]
        results_DT7 = result_names[6]
        results_DT8 = result_names[7]

        result_values_DT1 = result_values[0]
        result_values_DT2 = result_values[1]
        result_values_DT3 = result_values[2]
        result_values_DT4 = result_values[3]
        result_values_DT5 = result_values[4]
        result_values_DT6 = result_values[5]
        result_values_DT7 = result_values[6]
        result_values_DT8 = result_values[7]

        metaclassifier1_values = metaclassifier_values[0]
        metaclassifier2_values = metaclassifier_values[1]
        metaclassifier3_values = metaclassifier_values[2]
        metaclassifier4_values = metaclassifier_values[3]
        metaclassifier5_values = metaclassifier_values[4]
        metaclassifier6_values = metaclassifier_values[5]
        metaclassifier7_values = metaclassifier_values[6]
        metaclassifier8_values = metaclassifier_values[7]
        
        # Prepare file for UCF configuration
        configurationStarted = False
        configurationStopped = False
        with open(config_for_ARFF_gen_filename, "r") as input:
          with open(config_for_UCF_gen_filename, "w") as output:
            for line in input:
              if (configurationStarted == False):
                if  line.rstrip() == "configurationStarted":
                  configurationStarted = True
                  output.write(line)
              else: #after configurationStarted
                if line.rstrip() == "<feature>END_FEATURES":
                  configurationStopped = True
                  output.write(line)

                  #read ARFF to get feature names
                  with open(arff_filename) as arff_file:
                    lines_of_arff = arff_file.readlines()
                    for line_of_arff in lines_of_arff:
                      if line_of_arff.startswith( '@attribute F' ) or line_of_arff.startswith('@ATTRIBUTE F'):
                        line_of_arff_splitted = line_of_arff.split();
                        output.write(line_of_arff_splitted[1] + '\n')

                  #read ARFF to get class names
                  with open(arff_filename) as arff_file:
                    lines_of_arff = arff_file.readlines()
                    for line_of_arff in lines_of_arff:
                      if line_of_arff.startswith( '@attribute class' ):
                        classes_string = line_of_arff[line_of_arff.find('{') + 1 : line_of_arff.find('}')]
                        classes_list = classes_string.split(', ')
                        logging.info("Classes from ARFF: " + ', '.join(classes_list))

                elif (configurationStopped == False):
                  if line.strip() != "":
                    output.write(line)
        input.close()
        output.close()

        f = open(config_for_UCF_gen_filename, "a+")

        # Results (classes)
        result_values_DT1_string = ""
        result_values_DT2_string = ""
        result_values_DT3_string = ""
        result_values_DT4_string = ""
        result_values_DT5_string = ""
        result_values_DT6_string = ""
        result_values_DT7_string = ""
        result_values_DT8_string = ""
        max_DT_classes = 256
        if device_name == "LSM6DSOX" or device_name == "LSM6DSO32X":
            max_DT_classes = 16
        elif device_name == "LSM6DSRX" or device_name == "ISM330DHCX" or device_name == "IIS2ICLX":
            max_DT_classes = 256
        else:
            logging.error("ERROR: device \"" + device_name + "\" not supported")
        for i in range(0, max_DT_classes):
          if i > 0:
            result_values_DT1_string += " ; "
            result_values_DT2_string += " ; "
            result_values_DT3_string += " ; "
            result_values_DT4_string += " ; "
            result_values_DT5_string += " ; "
            result_values_DT6_string += " ; "
            result_values_DT7_string += " ; "
            result_values_DT8_string += " ; "
          if i in result_values_DT1:
            result_values_DT1_string += results_DT1[result_values_DT1.index(i)]
          if i in result_values_DT2:
            result_values_DT2_string += results_DT2[result_values_DT2.index(i)]
          if i in result_values_DT3:
            result_values_DT3_string += results_DT3[result_values_DT3.index(i)]
          if i in result_values_DT4:
            result_values_DT4_string += results_DT4[result_values_DT4.index(i)]
          if i in result_values_DT5:
            result_values_DT5_string += results_DT5[result_values_DT5.index(i)]
          if i in result_values_DT6:
            result_values_DT6_string += results_DT6[result_values_DT6.index(i)]
          if i in result_values_DT7:
            result_values_DT7_string += results_DT7[result_values_DT7.index(i)]
          if i in result_values_DT8:
            result_values_DT8_string += results_DT8[result_values_DT8.index(i)]
        f.write(result_values_DT1_string + "\n")
        if n_decision_trees >= 2:
            f.write(result_values_DT2_string + "\n")
        if n_decision_trees >= 3:
            f.write(result_values_DT3_string + "\n")
        if n_decision_trees >= 4:
            f.write(result_values_DT4_string + "\n")
        if n_decision_trees >= 5:
            f.write(result_values_DT5_string + "\n")
        if n_decision_trees >= 6:
            f.write(result_values_DT6_string + "\n")
        if n_decision_trees >= 7:
            f.write(result_values_DT7_string + "\n")
        if n_decision_trees >= 8:
            f.write(result_values_DT8_string + "\n")

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
        args = [external_tools.mlc_app, "-" + device_name, "-MLC_script", config_for_UCF_gen_filename]
        mlc_app_ret_value = subprocess.call(args)
        if (mlc_app_ret_value == 0):
            logging.info("\n.ucf file generated successfully: " + ucf_filename)
        elif (mlc_app_ret_value == 38):
            logging.error("\nERROR: Maximum number of nodes exceeded")
        elif (mlc_app_ret_value == 39):
            logging.error("\nERROR: Cannot open decision tree file")
        else:
            logging.error("\nERROR: ", mlc_app_ret_value)


    def h_generator(ucf_filename, h_filename):
        with open(ucf_filename, "r") as f:
            ucff = f.readlines()

        conf_data = ""
        conf_regex = "Ac\s+([0-9,A-F]+)\s+([0-9,A-F]+)"
        for i in range(len(ucff)):
            res = re.search(conf_regex, ucff[i])
            if(res and len(res.groups()) == 2):
                hline = ("\n\t{.address = 0x%s, .data = 0x%s,}" % res.groups())
                if(i < len(ucff) - 1):
                    hline += ","
                conf_data += hline

        hstr = (
            '''
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
            ''' % conf_data
        )

        with open(h_filename, "w") as hout:
            hout.write(hstr)
        logging.info("Header file successfully generated. %s  ->  %s" % (ucf_filename, h_filename))