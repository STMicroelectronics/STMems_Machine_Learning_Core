# Python scripts for MLC 

This folder contains Python scripts for the **Machine Learning Core** (MLC) of ST MEMS devices. 

The directory is organized as follows: 

* [Logs](./Logs): contains data logs to easily run the scripts with the default configuration
* [Script](./Script): contains the Python scripts for the MLC 

The main script is available as a Jupyter notebook named [mlc.ipynb](./Script/mlc.ipynb), with comments and instructions which describe how to customize the MLC configuration.

## Description

The Python scripts interact with an external tool which is run in the background to perform some tasks (e.g. *.arff* file generation and *.ucf*  file generation). 

The script performs all the MLC configuration steps, starting from the data logs to the device configuration (*.ucf* file generation). In the Jupyter notebook *mlc.ipynb*, after some general settings at the beginning, five main steps are available in four separate sections: 

1. Data pattern management and labeling
2. Filters/features computation (*.arff* file)
3. Decision tree training (*dectree.txt* file)
4. Sensor register configuration (*.ucf* file)
5. (Optional) decision tree validation

## Setup

1. Download the [Unico GUI](https://www.st.com/en/development-tools/unico-gui.html) or the newest [MEMS Studio](https://www.st.com/en/development-tools/mems-studio.html) for ST sensors evaluation

2. Find the folder containing an executable named **mlc_configuration_tool.exe** inside the installation folder; depending on the software downloaded, this may be in one of the following locations:
	* Unico GUI: `C:\Program Files (x86)\STMicroelectronics\Unico-GUI\tools\mlc_configuration_tool`
	* MEMS Studio: `C:\Users\<username>\AppData\Local\STMicroelectronics\MEMS Studio\tools\mlc_configuration_tool`

3. Add the **mlc_configuration_tool** folder to the environmental variable **Path** on your system:

	* Windows:
		1. Type **Edit environmental variables for your account** in the search bar and press enter
		2. Select **Path** inside the **User variables for \<username\>** and press **Edit**
		3. Press **New** and then **Browse** to select the absolute path of the **mlc_configuration_tool** folder and press **OK**

	* Linux and macOS:
	
		Add to your **.bashrc** or equivalent shell startup file the following line:
		```shell
		export PATH=$PATH":/path/to/mlc_configuration_tool"
		```

------

**More information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2023 STMicroelectronics**

