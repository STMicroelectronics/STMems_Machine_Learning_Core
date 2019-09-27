## 1 - Introduction

The stationary detection algorithm described in this example is intended for vehicle applications, since all the data logs collected for this purpose have been acquired with the device inside a vehicle. 
The inputs of two sensors have been used (accelerometer and gyroscope at 52 Hz data rate) and different features computed in a window of 52 samples (mean, variance, energy, peak-to-peak, min, max) using the norm of the input signals.
The decision tree allows recognizing two different classes: Motion, Stationary.


## 2 - Device orientation

Any orientation


## 3 - Decision Tree output values

- MLC0_SRC register values
  - 0 = Motion
  - 4 = Stationary


## 4 - Interrupts

The configuration generates an interrupt (pulsed) on INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. 

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2019 STMicroelectronics**