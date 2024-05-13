## 1 - Introduction

Simple example of motion intensity detection implemented using the variance feature on the accelerometer norm. 
The classes recognized in this example are eight different levels of intensity, from 0 to 7.

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README file of the [application_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/application_examples ) folder. 

For information on how to create similar algorithms, please follow the instructions provided in the [configuration_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/configuration_examples ) folder.   

## 2 - Sensor configuration and orientation

The accelerometer is configured with ±2 *g* full scale and 15 Hz output data rate.

Any sensor orientation is allowed for this algorithm.

## 3 - Machine Learning Core configuration

Just one feature (variance), has been applied to the norm of the accelerometer data.
The MLC runs at 15 Hz, computing features on windows of 45 samples (corresponding to almost 3 seconds).
One decision tree with 7 nodes has been configured to detect the different classes.
A meta-classifier has not been used.  

- MLC0_SRC (70h) register values
  - 0 = Intensity_0
  - 1 = Intensity_1
  - 2 = Intensity_2
  - 3 = Intensity_3
  - 4 = Intensity_4
  - 5 = Intensity_5
  - 6 = Intensity_6
  - 7 = Intensity_7


## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. The duration of the interrupt pulse is 77 ms in this configuration.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2020 STMicroelectronics**