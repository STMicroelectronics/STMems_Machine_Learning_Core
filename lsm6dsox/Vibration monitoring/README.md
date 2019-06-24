## 1 - Introduction

Three different levels of vibrations are recognized (vibration1, vibration2, vibration3) using a simple decision tree with just one feature, the peak-to-peak feature in the accelerometer norm squared input (p2p_accNorm2).
The vibration monitoring example runs at 26 Hz, computing features in a window of 16 samples.


## 2 - Device orientation

Any orientation


## 3 - Decision Tree output values

- MLC0_SRC register values
  - 0 = vibration1 (no vibration)
  - 1 = vibration2 (low vibration)
  - 2 = vibration3 (high vibration)


## 4 - Interrupts

The configuration does not generate any interrupt. 
It is possible routing interrupt status bits to INT1 and INT2 pins through registers MLC_INT1 (0Dh) and MLC_INT2(11h).


------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright (C) 2019 STMicroelectronics**