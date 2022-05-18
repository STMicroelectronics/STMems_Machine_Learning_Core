from mlc_script_log import *

# Unico version check: 
from win32com.client import Dispatch
ver_parser = Dispatch('Scripting.FileSystemObject')
mlc_app = "C:/Program Files (x86)/STMicroelectronics/Unico-GUI/unico.exe"  ## Windows
app_version = "0.0.0.0"
if os.path.isfile(mlc_app):
    app_version = ver_parser.GetFileVersion(mlc_app)
    logging.info("app version: " + app_version)
expected_version = "9.12.0.0"
if app_version != expected_version:
#    logging.error("\nERROR: wrong Unico version. Please download version " + expected_version + " from: https://www.st.com/en/development-tools/unico-gui.html")
    logging.error("\nERROR: wrong app version")