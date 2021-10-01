## 1 - Introduction

This Machine Learning Core (MLC) example implements the detection of the *tilt angle*, i.e. the current inclination of the device, in the range of -20 to +20 degrees.

Two decision trees are configured:

1. It detects the angle between the x-axis and the horizontal plane
2. It detects the angle between the y-axis and the horizontal plane

The output can be read from the MLC0_SRC and MLC1_SRC registers and is expressed as a 8-bit value in two’s complement. The tilt angle in degrees is obtained by multiplying the output by a sensitivity of 0.15748 degrees/LSB.


## 2 - Sensor configuration and orientation

The accelerometer is configured with ±0.5 *g* full scale and 26 Hz output data rate.

The reference position, when both detected tilt angles are 0 degrees, is when the x-y plane of the sensor is orthogonal to the gravity vector.

*Note: the angle is measured between a sensing axis and a line formed by the intersection of the horizontal plane and the vertical plane where the sensing axis lies. Generally, the two vertical planes where the sensing axes lie are not orthogonal to each other, which is not in accordance to aeronautical nomenclature. Therefore, in applications that should meet the aeronautical definition of the roll angle, the tilt must always be applied to only one axis, while the other axis is maintained perpendicular to the gravity vector. Any tilt on the other axis reduces the magnitude of the acceleration (due to gravity) on the sensing axis, resulting in an error in the angle computation.*


## 3 - Machine Learning Core configuration

A 2<sup>nd</sup> order low-pass IIR filter with cutoff frequency of 5 Hz and gain = 1 (for ODR = 26 Hz) is configured to filter the accelerometer data.

Two features have been used (the mean of the x-axis and the mean of the y-axis of the filtered accelerometer data).
The MLC runs at 26 Hz, computing features on windows of 1 sample (corresponding to 38.5 milliseconds), in order to ensure maximum responsiveness.

Two decision trees with 255 nodes were configured to detect different classes. Each class represents a tilt angle in the given range.
Meta-classifiers are not used.  

*Decision tree 1*:

Output values correspond to the angle between the x-axis and the horizontal plane.

*Decision tree 2*:

Output values correspond to the angle between the y-axis and the horizontal plane.

The output value is expressed as an 8-bit value in two’s complement corresponding to the tilt angle in the range of -20 to +20 degrees. The output is saturated (on the maximum value), when the actual tilt angle is outside the given tilt range.
The tilt angle in degrees can be obtained by multiplying the output by a sensitivity of 0.15748 degrees/LSB.


## 4 - Interrupts

The configuration generates an interrupt (pulsed and active-high) on the INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. The duration of the interrupt pulse is 38.5 ms in this configuration.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2021 STMicroelectronics**

