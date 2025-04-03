## 1 - Introduction

The activity recognition algorithm described in this example is intended for smartphone applications since all the data logs collected for this purpose have been acquired with a smartphone carried in the user's pocket.
The activities recognized in this example are: Stationary, Walking, Jogging, Biking and Driving.
A limited subset of data logs for this example is available [here](./datalogs/).

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README file of the [application_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/application_examples ) folder.

For information on how to create similar algorithms, please follow the instructions provided in the [configuration_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/configuration_examples ) folder.


## 2 - Sensor configuration and orientation

The accelerometer is configured with ±4 *g* full scale and 25 Hz output data rate.

Any sensor orientation is allowed for this algorithm.


## 3 - Machine Learning Core configuration

Four features have been used (mean, variance, peak-to-peak, zero-crossing), and two different filters have been applied to the accelerometer input data.
The MLC runs at 25 Hz, computing features on windows of 75 samples (corresponding to 3 seconds).
One decision tree with around 120 nodes has been configured to detect the different classes.
A meta-classifier has not been used.

- MLC1_SRC (34h) register values
  - 0 = Stationary
  - 1 = Walking
  - 4 = Jogging
  - 8 = Biking
  - 12 = Driving


## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC1_SRC (34h) is updated with a new value. The duration of the interrupt pulse is 40 ms in this configuration.

------

**More information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2023 STMicroelectronics**
