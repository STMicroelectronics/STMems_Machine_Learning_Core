# Machine Learning Core

This repository provides information, examples and configurations of the **Machine Learning Core** (MLC), a hardware processing engine dedicated to the most extreme real-time edge computing available in the latest  products in the [**ST sensors portfolio**](https://www.st.com/en/mems-and-sensors.html?sc=MEMS). Products that offer the MLC end in "X".

Machine Learning processing allows moving some algorithms from the application processor to the *STMicroelectronics* sensor, enabling consistent reduction of power consumption.

Machine Learning processing is obtained through *decision-tree logic*. A decision tree is a mathematical tool composed of a series of configurable *nodes*. Each *node* is characterized by an *“if-then-else”* condition, where an input signal (represented by statistical parameters calculated from the sensor data) is evaluated against a threshold.

The results of the decision tree can be read from the application processor at any time. Furthermore, there is the possibility to **generate an interrupt** for every change in the result in the decision tree.

For more information about MLC, please explore the dedicated page available on the ST website:  [Explore Machine Learning Core in MEMS sensors](https://www.st.com/content/st_com/en/campaigns/machine-learning-core.html).


## Repository overview

This repository is structured as follows:  

- An [application_examples](./application_examples/) folder, containing examples of applications ready to be used with the sensor.
- A [configuration_examples](./configuration_examples/) folder, containing examples of configurations using different ST hardware and software tools.
- A [tools](./tools/) folder, containing some additional scripts for decision tree generation.

------

**More information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2020 STMicroelectronics**