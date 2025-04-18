/*
 ******************************************************************************
 * @file    lsm6dsv320x_tilt_angle_mode1.h
 * @author  MEMS Software Solutions Team
 * @brief   This file contains the configuration for lsm6dsv320x_tilt_angle_mode1.
 *
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef LSM6DSV320X_TILT_ANGLE_MODE1_H
#define LSM6DSV320X_TILT_ANGLE_MODE1_H

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
const ucf_line_t lsm6dsv320x_tilt_angle_mode1[] = {
  {.address = 0x10, .data = 0x00,},
  {.address = 0x11, .data = 0x00,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x04, .data = 0x00,},
  {.address = 0x05, .data = 0x00,},
  {.address = 0x17, .data = 0x40,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xEA,},
  {.address = 0x09, .data = 0x1C,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x26,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x0A,},
  {.address = 0x09, .data = 0x01,},
  {.address = 0x09, .data = 0x01,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xFA,},
  {.address = 0x09, .data = 0x14,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x28,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x34,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x02, .data = 0x21,},
  {.address = 0x08, .data = 0x14,},
  {.address = 0x09, .data = 0x3F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x0C,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x1F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x21,},
  {.address = 0x08, .data = 0x28,},
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
  {.address = 0x02, .data = 0x21,},
  {.address = 0x08, .data = 0x34,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x08,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0xB6,},
  {.address = 0x09, .data = 0x05,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0xB2,},
  {.address = 0x09, .data = 0xB8,},
  {.address = 0x09, .data = 0x04,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0x59,},
  {.address = 0x09, .data = 0xB9,},
  {.address = 0x09, .data = 0xEF,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0xFD,},
  {.address = 0x09, .data = 0xB7,},
  {.address = 0x09, .data = 0xCD,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0xA5,},
  {.address = 0x09, .data = 0xB2,},
  {.address = 0x09, .data = 0x07,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0xF0,},
  {.address = 0x09, .data = 0xB4,},
  {.address = 0x09, .data = 0xAB,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0xAE,},
  {.address = 0x09, .data = 0xAE,},
  {.address = 0x09, .data = 0x89,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0x36,},
  {.address = 0x09, .data = 0x0C,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0xA5,},
  {.address = 0x09, .data = 0x32,},
  {.address = 0x09, .data = 0x0B,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0xAE,},
  {.address = 0x09, .data = 0x2E,},
  {.address = 0x09, .data = 0x67,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0xF0,},
  {.address = 0x09, .data = 0x34,},
  {.address = 0x09, .data = 0x45,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0xB2,},
  {.address = 0x09, .data = 0x38,},
  {.address = 0x09, .data = 0x0E,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0xFD,},
  {.address = 0x09, .data = 0x37,},
  {.address = 0x09, .data = 0x23,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0x59,},
  {.address = 0x09, .data = 0x39,},
  {.address = 0x09, .data = 0x01,},
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
  {.address = 0x45, .data = 0x02,},
  {.address = 0x01, .data = 0x00,},
  {.address = 0x15, .data = 0x00,},
  {.address = 0x17, .data = 0x00,},
  {.address = 0x10, .data = 0x05,},
  {.address = 0x11, .data = 0x00,}
};

#ifdef __cplusplus
}
#endif

#endif /* LSM6DSV320X_TILT_ANGLE_MODE1_H */

