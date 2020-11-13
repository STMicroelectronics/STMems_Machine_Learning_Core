## 1 - Introduction

In this example, a simple vibration monitoring algorithm is provided.

The classes recognized by this example are: vibration1 (no vibration), vibration2 (low vibration), vibration3 (high vibration). 

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README file of the [application_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/application_examples ) folder. 

For information on how to create similar algorithms, please follow the instructions provided in the [configuration_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/configuration_examples ) folder. 


## 2 - Sensor configuration and orientation

The accelerometer is configured with ±4 *g* full scale and 26 Hz output data rate.

Any sensor orientation is allowed for this algorithm.


## 3 - Machine Learning Core configuration

Just one feature has been used (peak-to-peak) and applied to the accelerometer norm squared input. 

The MLC runs at 26 Hz, computing features on windows of 16 samples (around 0.6 seconds). 

One decision tree with just 2 nodes has been configured to detect the different classes.
A meta-classifier has not been used.  

- MLC0_SRC (70h) register values
  - 0 = vibration1 (no vibration)
  - 1 = vibration2 (low vibration)
  - 2 = vibration3 (high vibration)


## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. The duration of the interrupt pulse is 38.5 ms in this configuration.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2020 STMicroelectronics**