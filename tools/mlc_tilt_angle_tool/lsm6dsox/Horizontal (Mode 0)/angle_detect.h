/*
 ******************************************************************************
 * @file    angle_detect.h
 * @author  Sensors Software Solution Team
 * @brief   This file contains the configuration for angle_detect.
 *
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef ANGLE_DETECT_H
#define ANGLE_DETECT_H

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
const ucf_line_t angle_detect[] = {
  {.address = 0x10, .data = 0x00,},
  {.address = 0x11, .data = 0x00,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x04, .data = 0x00,},
  {.address = 0x05, .data = 0x00,},
  {.address = 0x17, .data = 0x40,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xEA,},
  {.address = 0x09, .data = 0x44,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x4E,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x0A,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xF2,},
  {.address = 0x09, .data = 0x01,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xFA,},
  {.address = 0x09, .data = 0x3C,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x50,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x5C,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x3C,},
  {.address = 0x09, .data = 0x3F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x04,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x1F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x50,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x01, .data = 0x00,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x17, .data = 0x40,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x5C,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x08,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0x25,},
  {.address = 0x09, .data = 0xAB,},
  {.address = 0x09, .data = 0x05,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0x5B,},
  {.address = 0x09, .data = 0xAD,},
  {.address = 0x09, .data = 0x04,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0x3F,},
  {.address = 0x09, .data = 0xAE,},
  {.address = 0x09, .data = 0x10,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0x77,},
  {.address = 0x09, .data = 0xAC,},
  {.address = 0x09, .data = 0x32,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0x26,},
  {.address = 0x09, .data = 0xA7,},
  {.address = 0x09, .data = 0x07,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0x5C,},
  {.address = 0x09, .data = 0xA9,},
  {.address = 0x09, .data = 0x54,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0x26,},
  {.address = 0x09, .data = 0xA3,},
  {.address = 0x09, .data = 0x76,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0x25,},
  {.address = 0x09, .data = 0x2B,},
  {.address = 0x09, .data = 0x0C,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0x26,},
  {.address = 0x09, .data = 0x27,},
  {.address = 0x09, .data = 0x0B,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0x26,},
  {.address = 0x09, .data = 0x23,},
  {.address = 0x09, .data = 0x98,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0x5C,},
  {.address = 0x09, .data = 0x29,},
  {.address = 0x09, .data = 0xBA,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0x5B,},
  {.address = 0x09, .data = 0x2D,},
  {.address = 0x09, .data = 0x0E,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0x77,},
  {.address = 0x09, .data = 0x2C,},
  {.address = 0x09, .data = 0xDC,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0x3F,},
  {.address = 0x09, .data = 0x2E,},
  {.address = 0x09, .data = 0xFE,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x17, .data = 0x00,},
  {.address = 0x04, .data = 0x00,},
  {.address = 0x05, .data = 0x10,},
  {.address = 0x02, .data = 0x01,},
  {.address = 0x01, .data = 0x00,},
  {.address = 0x5E, .data = 0x02,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x0D, .data = 0x01,},
  {.address = 0x60, .data = 0x25,},
  {.address = 0x01, .data = 0x00,},
  {.address = 0x10, .data = 0x30,},
  {.address = 0x11, .data = 0x00,}
};

#ifdef __cplusplus
}
#endif

#endif /* ANGLE_DETECT_H */

