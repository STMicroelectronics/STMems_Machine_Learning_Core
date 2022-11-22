## 1 - Python scripts for MLC 

This folder contains Python scripts for the **Machine Learning Core** (MLC) of ST MEMS devices. 

The directory is organized as follows: 

- [Logs](./Logs) folder: contains data logs to easily run the scripts with the default configuration

- [Script](./Script) folder: contains the Python scripts for the MLC 

  The main script is available as a Jupyter notebook ([MLC.ipynb]((./Script/MLC.ipynb))), with comments and instructions which describe how to customize the MLC configuration. Some Python modules (*.py* files) are included in the main script to perform dedicated tasks.

*Note*: **Python** version **3.8.8** has been used, and [Unico GUI](https://www.st.com/en/development-tools/unico-gui.html) version **9.13.0.0** has to be installed.

The Python scripts interact with Unico GUI, which is run in the background to perform some tasks (e.g. *.arff* file generation and *.ucf*  file generation). However, the whole MLC configuration is managed by the script and no user interaction with the GUI is required.

The script performs all the MLC configuration steps, starting from the data logs to the device configuration (*.ucf* file generation). In the Jupyter notebook, after some general settings at the beginning, four main steps are available in four separate sections: 

1. Data pattern management and labeling
2. Filters/Features computation, *.arff* file generation
3. Decision tree generation
4. *.ucf* file generation

In the final part of the script, an additional section (optional) allows testing *.arff* files on decision trees.

------

**More information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2022 STMicroelectronics**

