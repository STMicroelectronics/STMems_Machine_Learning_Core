## 1 - Introduction

Head gestures configuration is intended as an example for headphone applications.
To implement this algorithm with a decision tree, all the data logs have been acquired using the device (LSM6DSRX) mounted on the headphone.

The decision tree allows recognizing five different gestures including nod, shake, stationary, swing, walk.

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README file of the [application_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/application_examples ) folder. 

For information on how to create similar algorithms, please follow the instructions provided in the [configuration_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/configuration_examples ) folder. 


## 2 - Sensor configuration and orientation

The accelerometer is configured with ±2 *g* full scale and 26 Hz output data rate.
The gyroscope is configured with ±250 *dps* full scale and 26 Hz output data rate.

When wearing the headphone:

- X pointing back
- Y pointing up 
- Z pointing left


## 3 - Machine Learning Core configuration

The inputs of two sensors have been used (accelerometer and gyroscope at 26 Hz data rate) and the following features have used: 

- Peak to peak on the accelerometer Y axis
- Peak to peak on the gyroscope Y axis
- Minimum on the accelerometer X axis
- Maximum on the accelerometer Y axis
- Maximum on the gyroscope Y axis
- Energy on the gyroscope X axis
- Mean on the gyroscope Z axis
- Variance on the accelerometer Y axis
- Variance on the gyroscope Y axis
- Variance on the gyroscope Z axis
- Energy on the gyroscope Y axis

The MLC runs at 26 Hz, computing features on windows of 26 samples (corresponding to 1 second).
One decision tree with around 7 nodes has been configured to detect the different classes.
A meta-classifier has not been used.  

- MLC0_SRC (70h) register values
  - 0 = Nod
  - 1 = Shake
  - 2 = Stationary
  - 3 = Swing
  - 4 = Walk


## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. The duration of the interrupt pulse is 38.5 ms in this configuration.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2020 STMicroelectronics**