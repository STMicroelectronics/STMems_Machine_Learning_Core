## 1 - Introduction

Simple example of motion intensity detection implemented using the variance feature on the accelerometer norm. 
The configuration runs at 12.5 Hz, computing features in a window of 39 samples.


## 2 - Device orientation

Any orientation


## 3 - Decision Tree output values

- MLC0_SRC register values
  - 0 = Intensity_0
  - 1 = Intensity_1
  - 2 = Intensity_2
  - 3 = Intensity_3
  - 4 = Intensity_4
  - 5 = Intensity_5
  - 6 = Intensity_6
  - 7 = Intensity_7


## 4 - Interrupts

The configuration generates an interrupt (pulsed) on INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. 

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2019 STMicroelectronics**