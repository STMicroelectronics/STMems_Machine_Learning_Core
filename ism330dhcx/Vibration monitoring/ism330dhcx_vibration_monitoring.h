/*
 ******************************************************************************
 * @file    ism330dhcx_vibration_monitoring.h
 * @author  Sensors Software Solution Team
 * @brief   This file contains the configuration for ism330dhcx_vibration_monitoring.
 *
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef ISM330DHCX_VIBRATION_MONITORING_H
#define ISM330DHCX_VIBRATION_MONITORING_H

#ifdef __cplusplus
  extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#ifndef MEMS_UCF_SHARED_TYPES
#define MEMS_UCF_SHARED_TYPES

/** Common data block definition **/
typedef struct {
  uint8_t address;
  uint8_t data;
} ucf_line_t;

#endif /* MEMS_UCF_SHARED_TYPES */

/** Configuration array generated from Unico Tool **/
const ucf_line_t ism330dhcx_vibration_monitoring[] = {
  {.address = 0x10, .data = 0x00,},
  {.address = 0x11, .data = 0x00,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x05, .data = 0x00,},
  {.address = 0x17, .data = 0x40,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xEA,},
  {.address = 0x09, .data = 0x46,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xEB,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xEC,},
  {.address = 0x09, .data = 0x50,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xED,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xEE,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xEF,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xF0,},
  {.address = 0x09, .data = 0x0A,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xF2,},
  {.address = 0x09, .data = 0x10,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xFA,},
  {.address = 0x09, .data = 0x3C,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xFB,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xFC,},
  {.address = 0x09, .data = 0x52,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xFD,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xFE,},
  {.address = 0x09, .data = 0x5E,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xFF,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x3C,},
  {.address = 0x09, .data = 0x3F,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x3D,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x3E,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x3F,},
  {.address = 0x09, .data = 0x94,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x40,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x41,},
  {.address = 0x09, .data = 0xFC,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x42,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x43,},
  {.address = 0x09, .data = 0x7C,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x44,},
  {.address = 0x09, .data = 0x1F,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x45,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x52,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x53,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x54,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x55,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x56,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x57,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x58,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x59,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x5A,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x5B,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x01, .data = 0x00,},
  {.address = 0x12, .data = 0x00,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x17, .data = 0x40,},
  {.address = 0x02, .data = 0x0D,},
  {.address = 0x08, .data = 0x00,},
  {.address = 0x09, .data = 0xAE,},
  {.address = 0x09, .data = 0x27,},
  {.address = 0x09, .data = 0x01,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x0A,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x3E,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x0B,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x17, .data = 0x00,},
  {.address = 0x04, .data = 0x00,},
  {.address = 0x05, .data = 0x10,},
  {.address = 0x02, .data = 0x01,},
  {.address = 0x01, .data = 0x00,},
  {.address = 0x12, .data = 0x44,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x60, .data = 0x15,},
  {.address = 0x01, .data = 0x00,},
  {.address = 0x10, .data = 0x28,},
  {.address = 0x11, .data = 0x00,},
  {.address = 0x5E, .data = 0x02,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x0D, .data = 0x01,},
  {.address = 0x01, .data = 0x00,}
};

#ifdef __cplusplus
}
#endif

#endif /* ISM330DHCX_VIBRATION_MONITORING_H */

