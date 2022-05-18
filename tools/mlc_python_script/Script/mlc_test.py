import subprocess
from mlc_script_log import *
import external_tools

def test_arff_on_decisiontree( dectree_filename, arff_filename, testresults_filename, device_name ):  
    logging.info("\nCalling MLC app for testing ARFF on decision tree...")
    args = [external_tools.mlc_app, "-" + device_name, "./CLI", "-MLC_test_arff", dectree_filename, arff_filename, testresults_filename]
    mlc_app_ret_value = subprocess.call(args)
    if (mlc_app_ret_value == 0):
        logging.info("\nTest file generated successfully: " + testresults_filename)
    elif (mlc_app_ret_value == 70):
        logging.error("\nERROR: file not found")
    else:
        logging.error("\nERROR: ", mlc_app_ret_value)