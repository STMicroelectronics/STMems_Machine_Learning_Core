## 1 - Introduction

The activity recognition algorithm described in this example is intended for wrist applications since all the data logs collected for this purpose have been acquired with a smartwatch carried at the user's wrist. 
The activities recognized in this example are: Stationary/Other, Walking/FastWalking and Jogging/Running. 
A limited subset of data logs for this example is available [here](./datalogs/).

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README file of the [application_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/application_examples ) folder. 

For information on how to create similar algorithms, please follow the instructions provided in the [configuration_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/configuration_examples ) folder. 


## 2 - Sensor configuration and orientation

The accelerometer is configured with ±8 *g* full scale and 26 Hz output data rate.

Sensor orientation is set as for the ENU convention (X toward fingers, Y front, Z up) in order to properly work.




## 3 - Machine Learning Core configuration

Seven features have been computed (mean, variance, energy, peak-to-peak, zero-crossing, min, max) and applied to the accelerometer input data.
The MLC runs at 26 Hz, computing features on windows of 52 samples (corresponding to 2 seconds).
One decision tree with around 70 nodes has been configured to detect the different classes.
A meta-classifier has been set to reduce false positives. 

- MLC0_SRC (70h) register values
  - 1 = Stationary/Other
  - 4 = Walking/FastWalking
  - 8 = Jogging/Running


## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. The duration of the interrupt pulse is 38.5 ms in this configuration.

------

**More information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2021 STMicroelectronics**