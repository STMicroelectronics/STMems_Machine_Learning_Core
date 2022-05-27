## 1 - Introduction

A tow-detection solution has been developed for automotive applications to detect two different vehicle towing styles:
- Front/back wheel lift
- Forward/backward lift with flatbed

The solution is expected to be enabled after vehicle ignition off. 
A limited subset of data logs for this example is available [here](./datalogs/).

For information on how to integrate this algorithm in the target platform, follow the instructions available in the README file of the [application_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/application_examples) folder. 

For information on how to create similar algorithms, follow the instructions provided in the [configuration_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/configuration_examples) folder. 

## 2 - Sensor configuration and orientation

The accelerometer is configured with ±4 *g* full scale and 12.5 Hz output data rate for low-power consumption. The additional current consumption of the MLC is just 3.1 µA.

The IMU can be placed anywhere on the vehicle with sensor X-Y axes parallel to the vehicle frame, see figure below.

![SensorOrientation](./images/SensorOrientation.png)

## 3 - Machine learning core configuration

The **machine learning core (MLC)** is configured to run at 12.5 Hz, computing features on windows of 13 samples, therefore the decision tree classifier outputs are updated almost every second.

There are three different decision trees running in parallel to detect the tow event along each axis. Each decision tree has three different features which are computed:

- Mean on bandpass accelerometer individual axis 
- Peak-to-peak on accelerometer individual axis 
- Zero-crossing on accelerometer individual axis 

One decision tree with 8 nodes has been configured to detect the different classes with a meta-classifier.  

The decision tree classifiers detect three different classes corresponding to different tow events (see picture below). The output of the decision tree classifier is stored in the MLC0_SRC (address 70h), MLC1_SRC (address 71h), MLC2_SRC (address 72h) registers.  

- MLC0_SRC (70h), MLC1_SRC (address 71h), MLC2_SRC (address 72h) register values
  - 0 = No event
  - 4 = Front/back wheel lift 
  - 8 = Forward and backward lift with flatbed
  

![TowingType](./images/TowingType.png)

Note that since the tow lift is detected by at least 2 axes, the MLC can raise 2 interrupts along a different axis. Additional filtering can be applied to remove interrupts belonging to the same event.

## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the MLC0_SRC (70h), MLC1_SRC (address 71h), MLC2_SRC (address 72h) registers are updated with a new value. The duration of the interrupt pulse is 80 ms in this configuration.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2022 STMicroelectronics**
