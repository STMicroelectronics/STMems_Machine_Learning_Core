## 1 - Introduction

This Machine Learning Core (MLC) example implements detection of the *tilt angle*, i.e. the current inclination of the device, on an x-y plane parallel to gravity.

The MLC processes data coming from the accelerometer, configured at 26 Hz and 2 g.

The features used are the mean of the x-axis and the mean of the y-axis. The window used is 1 sample in order to ensure maximum responsiveness.

Two decision trees are configured:

1. Detects angles from 0 to 180 degrees
2. Detects angles from 181 to 359 degrees

The tilt angle is the sum of the outputs of the two decision trees.


## 2 - Device orientation

The device must be placed with the x-y plane parallel to gravity. The detected tilt angle is 0 degrees when the y-axis is pointing up. 

Note: the angle is correctly detected only with the x-y plane parallel to gravity since a two-axis accelerometer is used.


## 3 - Decision Trees output values

*Decision tree 1*:

Output values from 0 to 180 in the corresponding tilt angle range, outputs 180 when the angle is more than 180 degrees

*Decision tree 2*:

Output values from 0 to 179 starting from a tilt angle of 180 degrees and increases together with the angle, outputs 0 when the tilt angle is less than 180 degrees


## 4 - Interrupts

The configuration generates an interrupt on INT1 when the *tilt angle* changes by at least 1 degree.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2020 STMicroelectronics**

