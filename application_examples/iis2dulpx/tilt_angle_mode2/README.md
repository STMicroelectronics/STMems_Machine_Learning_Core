## 1 - Introduction

This Machine Learning Core (MLC) example implements detection of the *tilt angle*, i.e. the current inclination of the device, on an x-z plane parallel to gravity.

One decision tree is configured to detect angles from -135 to 135 degrees. The tilt angle can be obtained by applying a simple formula on the output of the decision tree.
The decision tree has been designed using a dedicated [tool](./../../../tools/mlc_tilt_angle_tool).


## 2 - Sensor configuration and orientation

The accelerometer is configured with ±2 *g* full scale and 50 Hz output data rate.

The device must be placed with the x-z plane parallel to gravity. The detected tilt angle is 0 degrees when the z-axis is pointing up, +90 degrees when the x-axis is pointing up, and -90 degrees when the x-axis is pointing down.


## 3 - Machine Learning Core configuration

Two features have been used (the mean of the x-axis and the mean of the z-axis of the accelerometer data). 
The MLC runs at 50 Hz, computing features on windows of 1 sample (corresponding to 20 milliseconds), in order to ensure maximum responsiveness.

Meta-classifiers have not been used.

The tilt angle is obtained by applying the following formula:

**angle = MLC1_SRC * 18.000000 + (-135.000000) deg**


## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC1_SRC (34h) is updated with a new value. The duration of the interrupt pulse is 20 ms in this configuration.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2023 STMicroelectronics**