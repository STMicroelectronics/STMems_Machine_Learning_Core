## 1 - Introduction

Gym activity recognition is intended as a fitness example for a wearable device, like a smartwatch or a wristband.
To implement this algorithm with a decision tree, all the data logs have been acquired using the device (LSM6DSV32X) mounted on a wristband on the left hand (or right hand).  A limited subset of data logs for the case "left hand" is available [here](./datalogs/). 

Two different configuration files are provided for the two cases: *left* and *right* . 

The activities recognized in this example are: no activity, bicep curls, lateral raises, squats. 

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README file of the [application_examples](https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/application_examples) folder. 

For information on how to create similar algorithms, please follow the instructions provided in the [configuration_examples](https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/configuration_examples) folder. 


## 2 - Sensor configuration and orientation

The accelerometer is configured with ±16 g full scale, 30 Hz output data rate, low-power mode 1.

The sensor orientation for this algorithm is ENU

- X parallel to the arm (directed towards the hand for left wrist, directed away from the hand for right wrist)
- Y perpendicular to the arm (directed away from the user when looking at the device)
- Z pointing up


## 3 - Machine Learning Core configuration

Four features have been used (mean, peak-to-peak, min, max), and  one low-pass filter (IIR1) has been applied to the accelerometer input data.

The MLC runs at 30 Hz, computing features on windows of 90 samples (corresponding to 3 seconds).

One decision tree with around 30 nodes has been configured to detect the different classes. 

A meta-classifier has not been used.

- MLC1_SRC (70h) register values
  - 0 = No activity
  - 4 = Bicep curls
  - 8 = Lateral raises
  - 12 = Squats


## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC1_SRC (70h) is updated with a new value. The duration of the interrupt pulse is 33.3 ms in this configuration.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2022 STMicroelectronics**