## 1 - Introduction

The stationary detection algorithm described in this example is intended for vehicle applications, since all the data logs collected for this purpose have been acquired with the device inside a vehicle. 

The classes recognized in this example are: Motion and Stationary. 
A limited subset of data logs for this example is available [here](./datalogs/).

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README file of the [application_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/application_examples ) folder. 

For information on how to create similar algorithms, please follow the instructions provided in the [configuration_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/configuration_examples ) folder. 


## 2 - Sensor configuration and orientation

The accelerometer is configured with ±4 *g* full scale and 52 Hz output data rate. The gyroscope is configured with ±500 *dps* full scale and 52 Hz output data rate. 

Any sensor orientation is allowed for this algorithm.


## 3 - Machine Learning Core configuration

Six different features (mean, variance, energy, peak-to-peak, min, max) have been applied on the norm of the input signals (accelerometer and gyroscope). 

The MLC runs at 52 Hz, computing features on windows of 52 samples (corresponding to 1 second).
One decision tree with around 30 nodes has been configured to detect the two classes.
A meta-classifier has been used, setting the value 2 on the first counter (related to the class Motion).  

- MLC0_SRC (70h) register values
  - 0 = Motion
  - 4 = Stationary


## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. The duration of the interrupt pulse is 19.25 ms in this configuration.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2020 STMicroelectronics**