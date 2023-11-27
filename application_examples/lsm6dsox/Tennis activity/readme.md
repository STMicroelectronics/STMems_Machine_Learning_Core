## 1 - Introduction

This Machine Learning Core (MLC) example implements Tennis activity algorithm which is able to detect and classify different tennis shots(forehand, backhand, slice-forehand, slice-backhand, serve).

A limited subset of data logs for this example is available [here](./datalogs/).

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README files of [MLC application_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/application_examples ) folders. 

For information on how to create similar algorithms, please follow the instructions provided in the [MLC configuration_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/configuration_examples ) folders. 

## 2 - Sensor configuration and orientation

The accelerometer is configured with ±16 *g* full-scale and 104 Hz output data rate.

The gyroscope is configured with 2000 *dps* full-scale and 104 Hz output data rate.

In order for the application to work properly, the sensor placement is at the bottom of the tennis racket. The orientation of the axes are as follows:
  * X & Y axes are perpendicular to the face of the tennis racket
  * Z axis is parallel to the face of the tennis racket pointing away from the racket

## 3 - Machine Learning Core and Finite State Machine configuration

The MLC procsses the accelerometer and gyroscope data at 104 Hz:

* The MLC processes the accelerometer and gyroscope data in order to detect the tennis shot by using multiple features like (mean, minimum, variance, etc. on both accelerometer and gyroscope data of all 3 axes), computed every 208 samples (corresponding to 2 seconds). 

  One decision tree with Fifteen nodes has been configured to detect the different classes. 

  The output of the MLC can be read from the MLC0_SRC (70h) register:
  * 00h = Backhand
  * 04h = Forehand
  * 08h = Serve
  * 0Ch = Slice-backhand
  * 0Eh = Slice-forehand

The overall current consumption is about 592 µA.

## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC0_SRC (70h) is updated with a new value (when the state detected by the MLC changes). The duration of the interrupt pulse is 9.6 ms in this configuration.

------

**Copyright © 2022 STMicroelectronics**

