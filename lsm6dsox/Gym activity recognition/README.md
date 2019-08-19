## 1 - Introduction

Gym activity recognition is intended as a fitness example for a wearable device, like a smartwatch or a wristband.
To implement this algorithm with a decision tree, all the data logs have been acquired using the device (LSM6DSOX) mounted on a wristband.
The inputs of two sensors have been used (accelerometer and gyroscope at 104 Hz data rate) and six different features computed in a window of 208 samples (mean, variance, peak-to-peak, min, max, zero-crossing).
The decision tree allows recognizing five different gym activities including bicep curls, jumping jacks, lateral raises, push-ups, squats.
The configuration runs at 104 Hz, computing features in a window of 208 samples.


## 2 - Device orientation

- ENU
  - X parallel to the arm
  - Y perpendicular to the arm
  - Z pointing up


## 3 - Decision Tree output values

- MLC0_SRC register values
  - 0 = No activity
  - 4 = Bicep curls
  - 5 = Jumping jacks
  - 6 = Lateral raises
  - 7 = Push-ups
  - 8 = Squats


## 4 - Interrupts

The configuration generates an interrupt (pulsed) on INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. 

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2019 STMicroelectronics**