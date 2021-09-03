## 1 - Introduction

Gym activity recognition is intended as a fitness example for a wearable device, like a smartwatch or a wristband.
To implement this algorithm with a decision tree, all the data logs have been acquired using the device (LSM6DSO32X) mounted on a wristband on the left hand (or right hand).  A limited subset of data logs for the case "left hand" is available [here](./datalogs/). 

Two different configuration files are provided for the two cases: *left* and *right* . 

The activities recognized in this example are: No activity, Bicep curls, Lateral raises, Squats. 

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README file of the [application_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/application_examples ) folder. 

For information on how to create similar algorithms, please follow the instructions provided in the [configuration_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/configuration_examples ) folder. 


## 2 - Sensor configuration and orientation

The accelerometer is configured with ±8 *g* full scale, 26 Hz output data rate, ultra-low power mode.

The sensor orientation for this algorithm is ENU

- X parallel to the arm
- Y perpendicular to the arm
- Z pointing up


## 3 - Machine Learning Core configuration

Four features have been used (mean, peak-to-peak, min, max), and  one low-pass filter (IIR1) has been applied to the accelerometer input data.

The MLC runs at 26 Hz, computing features on windows of 78 samples (corresponding to 3 seconds).

One decision tree with around 30 nodes has been configured to detect the different classes. 

A meta-classifier has not been used.  

- MLC0_SRC (70h) register values
  - 0 = No activity
  - 4 = Bicep curls
  - 8 = Lateral raises
  - 12 = Squats


## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. The duration of the interrupt pulse is 38.5 ms in this configuration.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2021 STMicroelectronics**