## 1 - Introduction

This example combines Machine Learning Core (MLC) and Finite State Machine (FSM) capabilities to implement a Smart Asset Tracking algorithm able to detect and track the various states of a package (Stationary - Upright, Stationary - Not upright, In motion, Shaken) and detect some possible events (Impact, Free-fall).

A limited subset of data logs for this example is available [here](./datalogs/).

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README files of [MLC application_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/application_examples ) and [FSM application_examples]( https://github.com/STMicroelectronics/STMems_Finite_State_Machine/tree/master/application_examples ) folders. 

For information on how to create similar algorithms, please follow the instructions provided in the [MLC configuration_examples]( https://github.com/STMicroelectronics/STMems_Machine_Learning_Core/tree/master/configuration_examples ) and [FSM configuration_examples]( https://github.com/STMicroelectronics/STMems_Finite_State_Machine/tree/master/configuration_examples ) folders. 

## 2 - Sensor configuration and orientation

The accelerometer is configured with ±16 *g* full-scale and 26 Hz output data rate in low-power mode.

Sensor orientation is set as for the ENU convention (with Z-axis pointing up) in order to properly work.

## 3 - Machine Learning Core and Finite State Machine configuration

Both the MLC and FSM are configured to process the accelerometer data at 26 Hz in low-power mode:

* The MLC processes the accelerometer data in order to detect the package state by using three features (peak-to-peak and mean on the accelerometer norm, mean on the accelerometer Z-axis), computed every 13 samples (corresponding to 0.5 seconds). 

  One decision tree with three nodes has been configured to detect the different classes. 

  A meta-classifier has been set to reduce false positives.

  The output of the MLC can be read from the MLC0_SRC (70h) register:
  * 00h = Stationary - Upright
  * 04h = Stationary - Not upright
  * 08h = In motion
  * 0Ch = Shaken

  The MLC also applies a high-pass filter on the accelerometer data which is used by the FSM.

* The FSMs process both the raw and filtered accelerometer data in order to detect the following states:
  * Impact, detected by FSM #1
  * Free-fall, detected by FSM #2

In this example, the threshold for impact detection is set to 0.5 *g*, and the angle for upright is set to 26°.

The overall current consumption is about 22 µA.

## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC0_SRC (70h) is updated with a new value (when the state detected by the MLC changes). The duration of the interrupt pulse is 38.5 ms in this configuration.

The configuration generates an interrupt (pulsed and active high) on the INT2 pin when either a free-fall or an impact event is detected by the FSM. The free-fall interrupt remains active as long as the package is airborne. The FSM_STATUS_A (13h) register allows determining which FSM has generated the interrupt in order to distinguish between impact and free-fall events.

------

**Copyright © 2021 STMicroelectronics**

