## 1 - Introduction

Head gestures configuration is intended as an example for headphone applications.
To implement this algorithm with a decision tree, all the data logs have been acquired using the device (LSM6DSV16BX) mounted on the headphone.
The decision tree allows recognizing three different gestures including nod, shake, other. 


A limited subset of data logs for this example is available [here](./datalogs/).

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README file of the [application_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/application_examples ) folder. 

For information on how to create similar algorithms, please follow the instructions provided in the [configuration_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/configuration_examples ) folder. 


## 2 - Sensor configuration and orientation

The accelerometer is configured with ±16g full-scale and 30 Hz output data rate in low-power mode. 
The gyroscope is configured with 4000dps full-scale and 30 Hz output data rate in low-power mode. 

When wearing the headphone:

- X pointing back
- Y pointing up 
- Z pointing left


## 3 - Machine Learning Core configuration


The inputs of two sensors have been used (accelerometer and gyroscope at 30 Hz data rate) and the following features have used: 
- peak-to-peak, zero-crossing, maximum on the X, Y and Z axis gyroscope data

The MLC runs at 30 Hz, computing features on windows of 30 samples (corresponding to 1 second).
One decision tree with six nodes has been configured to detect the different classes.
A meta-classifier has not been used.  

- MLC1_SRC (70h) register values
  - 0 = Other
  - 4 = Nod
  - 8 = Shake





## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC1_SRC (70h) is updated with a new value. The duration of the interrupt pulse is 33.3 ms in this configuration.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2022 STMicroelectronics**
