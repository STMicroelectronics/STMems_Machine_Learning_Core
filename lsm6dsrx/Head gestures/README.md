## 1 - Introduction

Head gestures configuration is intended as an example for headphone applications.
To implement this algorithm with a decision tree, all the data logs have been acquired using the device (LSM6DSRX) mounted on the headphone.
The inputs of two sensors have been used (accelerometer and gyroscope at 26 Hz data rate) and the following features have been computed in a window of 26 samples: 
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

The decision tree allows recognizing five different gestures including nod, shake, stationary, swing, walk.
The configuration runs at 26 Hz, computing features in a window of 26 samples.


## 2 - Device orientation

- When wearing the headphone:
  - X pointing back
  - Y pointing up 
  - Z pointing left


## 3 - Decision Tree output values

- MLC0_SRC register values
  - 0 = Nod
  - 1 = Shake
  - 2 = Stationary
  - 3 = Swing
  - 4 = Walk


## 4 - Interrupts

The configuration generates an interrupt (pulsed) on INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. 

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2019 STMicroelectronics**