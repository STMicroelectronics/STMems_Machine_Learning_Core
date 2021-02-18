## 1 - Introduction

This Machine Learning Core (MLC) example implements detection of the *tilt angle*, i.e. the current inclination of the device, on an x-y plane parallel to gravity.

Two decision trees are configured:

1. Detects angles from 0 to 180 degrees
2. Detects angles from 181 to 359 degrees

The tilt angle is the sum of the outputs of the two decision trees.


## 2 - Sensor configuration and orientation

The accelerometer is configured with ±2 *g* full scale and 26 Hz output data rate.

The device must be placed with the x-y plane parallel to gravity. The detected tilt angle is 0 degrees when the y-axis is pointing up. 

Note: the angle is correctly detected only with the x-y plane parallel to gravity since a two-axis accelerometer is used.


## 3 - Machine Learning Core configuration

Two features have been used (the mean of the x-axis and the mean of the y-axis of the accelerometer data).
The MLC runs at 26 Hz, computing features on windows of 1 sample (corresponding to 38.5 milliseconds), in order to ensure maximum responsiveness.

Two decision trees with around 180 nodes have been configured to detect the different classes.
Meta-classifiers have not been used.  

*Decision tree 1*:

Output values from 0 to 180 in the corresponding tilt angle range, output value 180 when the angle is more than 180 degrees

*Decision tree 2*:

Output values from 0 to 179 starting from a tilt angle of 180 degrees and increases together with the angle, output value 0 when the tilt angle is less than 180 degrees;.

The tilt angle is the sum of the outputs of the two decision trees.


## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. The duration of the interrupt pulse is 38.5 ms in this configuration.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2021 STMicroelectronics**

