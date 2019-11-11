## 1 - Introduction

Gym activity recognition is intended as a fitness example for a wearable device, like a smartwatch or a wristband.
To implement this algorithm with a decision tree, all the data logs have been acquired using the device (LSM6DSOX) mounted on a wristband.
Accelerometer data has been used at 26 Hz data rate (ultra-low power mode, 8 g full scale), and four different features computed in a window of 78 samples (mean, peak-to-peak, min, max) and using a low-pass filter (IIR1).
The decision tree allows recognizing three different gym activities including bicep curls, lateral raises, squats.
The configuration runs at 26 Hz, computing features in a window of 78 samples.


## 2 - Device orientation

- ENU
  - X parallel to the arm
  - Y perpendicular to the arm
  - Z pointing up


## 3 - Decision Tree output values

- MLC0_SRC register values
  - 0 = No activity
  - 4 = Bicep curls
  - 8 = Lateral raises
  - 12 = Squats


## 4 - Interrupts

The configuration generates an interrupt (pulsed) on INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. 

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2019 STMicroelectronics**