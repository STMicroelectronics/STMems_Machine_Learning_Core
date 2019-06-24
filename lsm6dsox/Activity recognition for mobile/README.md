## 1 - Introduction

The activity recognition algorithm described in this example is intended for smartphone applications, since all the data logs collected for this purpose have been acquired with a smartphone carried in the user pocket. 
The activities recognized in this example are: Stationary, Walking, Jogging and Biking.
Four features have been used (mean, variance, peak-to-peak, zero-crossing), and two different filters have been applied to the accelerometer input data.
The configuration runs at 26 Hz, with a window of 75 samples.


## 2 - Device orientation

Any orientation


## 3 - Decision Tree output values

- MLC0_SRC register values
  - 0 = Stationary
  - 1 = Walking
  - 4 = Jogging
  - 8 = Biking


## 4 - Interrupts

The configuration does not generate any interrupt. 
It is possible routing interrupt status bits to INT1 and INT2 pins through registers MLC_INT1 (0Dh) and MLC_INT2(11h).


------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright (C) 2019 STMicroelectronics**