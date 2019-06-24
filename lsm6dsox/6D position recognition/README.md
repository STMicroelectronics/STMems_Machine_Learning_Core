## 1 - Introduction

Simple example of 6D position recognition implemented using the Mean features (singned/unsigned) on different axes of the accelerometer data. 
The configuration runs at 26 Hz, computing features in a window of 16 samples.


## 2 - Device orientation

Any orientation


## 3 - Decision Tree output values

- MLC0_SRC register values
  - 0 = None
  - 1 = X-axis pointing up
  - 2 = X-axis pointing down
  - 3 = Y-axis pointing up
  - 4 = Y-axis pointing down
  - 5 = Z-axis pointing up
  - 6 = Z-axis pointing down


## 4 - Interrupts

The configuration does not generate any interrupt. 
It is possible routing interrupt status bits to INT1 and INT2 pins through registers MLC_INT1 (0Dh) and MLC_INT2(11h).


------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright (C) 2019 STMicroelectronics**