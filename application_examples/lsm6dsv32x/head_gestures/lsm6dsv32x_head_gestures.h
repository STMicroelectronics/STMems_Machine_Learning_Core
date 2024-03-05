/*
 ******************************************************************************
 * @file    lsm6dsv16x_head_gestures.h
 * @author  MEMS Software Solutions Team
 * @brief   This file contains the configuration for lsm6dsv16x_head_gestures.
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
#ifndef LSM6DSV16X_HEAD_GESTURES_H
#define LSM6DSV16X_HEAD_GESTURES_H

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
const ucf_line_t lsm6dsv16x_head_gestures[] = {
  {.address = 0x10, .data = 0x00,},
  {.address = 0x11, .data = 0x00,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x04, .data = 0x00,},
  {.address = 0x05, .data = 0x00,},
  {.address = 0x17, .data = 0x40,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xEA,},
  {.address = 0x09, .data = 0x48,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x5C,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x01,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x14,},
  {.address = 0x09, .data = 0x01,},
  {.address = 0x09, .data = 0x1E,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xFA,},
  {.address = 0x09, .data = 0x14,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x68,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x74,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x02, .data = 0x21,},
  {.address = 0x08, .data = 0x14,},
  {.address = 0x09, .data = 0x3F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x11,},
  {.address = 0x09, .data = 0x18,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xFC,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x7C,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x1C,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xFC,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x7C,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x20,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xFC,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x7C,},
  {.address = 0x09, .data = 0x04,},
  {.address = 0x09, .data = 0x20,},
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
  {.address = 0x09, .data = 0x01,},
  {.address = 0x09, .data = 0x1C,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x04,},
  {.address = 0x09, .data = 0x1C,},
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
  {.address = 0x09, .data = 0x1F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x21,},
  {.address = 0x08, .data = 0x68,},
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
  {.address = 0x08, .data = 0x74,},
  {.address = 0x09, .data = 0xCD,},
  {.address = 0x09, .data = 0x3C,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xA0,},
  {.address = 0x09, .data = 0x38,},
  {.address = 0x09, .data = 0x42,},
  {.address = 0x09, .data = 0x05,},
  {.address = 0x09, .data = 0x81,},
  {.address = 0x09, .data = 0x66,},
  {.address = 0x09, .data = 0x41,},
  {.address = 0x09, .data = 0x30,},
  {.address = 0x09, .data = 0xC2,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x40,},
  {.address = 0x09, .data = 0x40,},
  {.address = 0x09, .data = 0xC3,},
  {.address = 0x09, .data = 0x33,},
  {.address = 0x09, .data = 0x4C,},
  {.address = 0x09, .data = 0x04,},
  {.address = 0x09, .data = 0xE4,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x40,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0xE5,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x17, .data = 0x00,},
  {.address = 0x04, .data = 0x00,},
  {.address = 0x05, .data = 0x10,},
  {.address = 0x02, .data = 0x01,},
  {.address = 0x01, .data = 0x00,},
  {.address = 0x5E, .data = 0x02,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x0D, .data = 0x01,},
  {.address = 0x60, .data = 0x15,},
  {.address = 0x45, .data = 0x02,},
  {.address = 0x01, .data = 0x00,},
  {.address = 0x15, .data = 0x04,},
  {.address = 0x17, .data = 0x07,},
  {.address = 0x10, .data = 0x04,},
  {.address = 0x11, .data = 0x04,}
};

#ifdef __cplusplus
}
#endif

#endif /* LSM6DSV16X_HEAD_GESTURES_H */

