## 1 - Introduction

This Machine Learning Core (MLC) example implements detection of the *tilt angle*, i.e. the current inclination of the device.

One decision tree is configured to detect angles from 45 to 135 degrees. The tilt angle can be obtained by applying a simple formula on the output of the decision tree.
The decision tree has been designed using a dedicated [tool](./../../../tools/mlc_tilt_angle_tool).


## 2 - Sensor configuration and orientation

The accelerometer is configured with ±2 *g* full scale and 52 Hz output data rate.

The detected tilt angle is 90 degrees when the z-axis is perpendicular to the gravity.


## 3 - Machine Learning Core configuration

One feature has been used (the mean of the z-axis of the accelerometer data).
The MLC runs at 52 Hz, computing features on windows of 1 sample (corresponding to 19.2 milliseconds), in order to ensure maximum responsiveness.

Meta-classifiers have not been used.

The tilt angle is obtained by applying the following formula:

**angle = MLC0_SRC * 0.354331 + (45.000000) deg**


## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. The duration of the interrupt pulse is 19.2 ms in this configuration.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2022 STMicroelectronics**

