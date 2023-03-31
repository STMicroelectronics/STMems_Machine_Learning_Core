from mlc_script_log import *

# Unico version check: 
from win32com.client import Dispatch
ver_parser = Dispatch('Scripting.FileSystemObject')
mlc_app = "C:/Program Files (x86)/STMicroelectronics/Unico-GUI/tools/mlc_configuration_tool/mlc_configuration_tool.exe"  ## Windows
app_version = "0.0.0.0"
if os.path.isfile(mlc_app):
    app_version = ver_parser.GetFileVersion(mlc_app)
    logging.info("app version: " + app_version)
expected_version = "0.1.2.0"
if app_version != expected_version:
#    logging.error("\nERROR: wrong Unico version. Please download version " + expected_version + " from: https://www.st.com/en/development-tools/unico-gui.html")
    logging.error("\nERROR: wrong app version")

# error codes: 
def decodeErrorCode(error_code):
    if (error_code == 35):
        logging.error("\nERROR: data pattern cannot be loaded")
    elif (error_code == 36):
        logging.error("\nERROR: too many filters")
    elif (error_code == 37):
        logging.error("\nERROR: too many features")
    elif (error_code == 38):
        logging.error("\nERROR: Maximum number of nodes exceeded")
    elif (error_code == 39):
        logging.error("\nERROR: Cannot open file")
    elif (error_code == 40):
        logging.error("\nERROR: 0 features configured")
    elif (error_code == 41):
        logging.error("\nERROR: sensor settings not supported")
    elif (error_code == 70):
        logging.error("\nERROR: file not found")
    elif (error_code == 71):
        logging.error("\nERROR: device not supported")
    else:
        logging.error("\nERROR: ", error_code)
