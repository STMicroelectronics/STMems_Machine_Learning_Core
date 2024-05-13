## 1 - Introduction

Simple example of 6D position recognition implemented using the Mean features (signed/unsigned) on different axes of the accelerometer data. 

The positions recognized with this example are: None, X-axis pointing up, X-axis pointing down, Y-axis pointing up, Y-axis pointing down, Z-axis pointing up, Z-axis pointing down.

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README file of the [application_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/application_examples ) folder. 

For information on how to create similar algorithms, please follow the instructions provided in the [configuration_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/configuration_examples ) folder. 


## 2 - Sensor configuration and orientation

The accelerometer is configured with ±4 *g* full scale and 30 Hz output data rate.

Any sensor orientation is allowed for this algorithm.


## 3 - Machine Learning Core configuration

Two features have been used (mean signed and mean unsigned), and applied to all the accelerometer axes.
The MLC runs at 30 Hz, computing features on windows of 18 samples (corresponding to 0.6 seconds).
One decision tree with around 8 nodes has been configured to detect the different classes.
A meta-classifier has not been used.  

- MLC0_SRC (70h) register values
  - 0 = None
  - 1 = X-axis pointing up
  - 2 = X-axis pointing down
  - 3 = Y-axis pointing up
  - 4 = Y-axis pointing down
  - 5 = Z-axis pointing up
  - 6 = Z-axis pointing down


## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. The duration of the interrupt pulse is 38.5 ms in this configuration.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2020 STMicroelectronics**