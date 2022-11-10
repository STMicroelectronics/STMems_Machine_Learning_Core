/*
 ******************************************************************************
 * @file    lsm6dsv16x_yoga_pose_recognition.h
 * @author  MEMS Software Solutions Team
 * @brief   This file contains the configuration for lsm6dsv16x_yoga_pose_recognition.
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
#ifndef LSM6DSV16X_YOGA_POSE_RECOGNITION_H
#define LSM6DSV16X_YOGA_POSE_RECOGNITION_H

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
const ucf_line_t lsm6dsv16x_yoga_pose_recognition[] = {
  {.address = 0x10, .data = 0x00,},
  {.address = 0x11, .data = 0x00,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x04, .data = 0x00,},
  {.address = 0x05, .data = 0x00,},
  {.address = 0x17, .data = 0x40,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xEA,},
  {.address = 0x09, .data = 0x24,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x2E,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x0A,},
  {.address = 0x09, .data = 0x01,},
  {.address = 0x09, .data = 0x3C,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xFA,},
  {.address = 0x09, .data = 0x14,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x34,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x40,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x02, .data = 0x21,},
  {.address = 0x08, .data = 0x14,},
  {.address = 0x09, .data = 0x3F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x04,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x08,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x0C,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x1F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x21,},
  {.address = 0x08, .data = 0x34,},
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
  {.address = 0x08, .data = 0x40,},
  {.address = 0x09, .data = 0xA1,},
  {.address = 0x09, .data = 0xB9,},
  {.address = 0x09, .data = 0x0D,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0x99,},
  {.address = 0x09, .data = 0xBA,},
  {.address = 0x09, .data = 0x0C,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0x31,},
  {.address = 0x09, .data = 0x30,},
  {.address = 0x09, .data = 0x20,},
  {.address = 0x09, .data = 0xA2,},
  {.address = 0x09, .data = 0xF2,},
  {.address = 0x09, .data = 0xBB,},
  {.address = 0x09, .data = 0x90,},
  {.address = 0x09, .data = 0xA0,},
  {.address = 0x09, .data = 0xFD,},
  {.address = 0x09, .data = 0x28,},
  {.address = 0x09, .data = 0x90,},
  {.address = 0x09, .data = 0xA1,},
  {.address = 0x09, .data = 0x27,},
  {.address = 0x09, .data = 0xB0,},
  {.address = 0x09, .data = 0x69,},
  {.address = 0x09, .data = 0xC1,},
  {.address = 0x09, .data = 0x17,},
  {.address = 0x09, .data = 0xBC,},
  {.address = 0x09, .data = 0x79,},
  {.address = 0x09, .data = 0xC0,},
  {.address = 0x09, .data = 0xE3,},
  {.address = 0x09, .data = 0xAF,},
  {.address = 0x09, .data = 0x0A,},
  {.address = 0x09, .data = 0x82,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xBC,},
  {.address = 0x09, .data = 0x99,},
  {.address = 0x09, .data = 0xC0,},
  {.address = 0x09, .data = 0x15,},
  {.address = 0x09, .data = 0x20,},
  {.address = 0x09, .data = 0xA9,},
  {.address = 0x09, .data = 0xE1,},
  {.address = 0x09, .data = 0x10,},
  {.address = 0x09, .data = 0xBC,},
  {.address = 0x09, .data = 0xA0,},
  {.address = 0x09, .data = 0xA0,},
  {.address = 0x09, .data = 0x12,},
  {.address = 0x09, .data = 0xBC,},
  {.address = 0x09, .data = 0x9A,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0x18,},
  {.address = 0x09, .data = 0xB9,},
  {.address = 0x09, .data = 0xB5,},
  {.address = 0x09, .data = 0xE2,},
  {.address = 0x09, .data = 0x72,},
  {.address = 0x09, .data = 0xBA,},
  {.address = 0x09, .data = 0x12,},
  {.address = 0x09, .data = 0x82,},
  {.address = 0x09, .data = 0x93,},
  {.address = 0x09, .data = 0xA3,},
  {.address = 0x09, .data = 0x11,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0xD5,},
  {.address = 0x09, .data = 0xAF,},
  {.address = 0x09, .data = 0x0C,},
  {.address = 0x09, .data = 0xC1,},
  {.address = 0x09, .data = 0xF4,},
  {.address = 0x09, .data = 0x26,},
  {.address = 0x09, .data = 0x47,},
  {.address = 0x09, .data = 0xE1,},
  {.address = 0x09, .data = 0xC8,},
  {.address = 0x09, .data = 0xAE,},
  {.address = 0x09, .data = 0x34,},
  {.address = 0x09, .data = 0xE1,},
  {.address = 0x09, .data = 0x06,},
  {.address = 0x09, .data = 0x39,},
  {.address = 0x09, .data = 0x14,},
  {.address = 0x09, .data = 0x82,},
  {.address = 0x09, .data = 0xEA,},
  {.address = 0x09, .data = 0xB4,},
  {.address = 0x09, .data = 0x16,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0xA6,},
  {.address = 0x09, .data = 0x3B,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0xA2,},
  {.address = 0x09, .data = 0x12,},
  {.address = 0x09, .data = 0xB5,},
  {.address = 0x09, .data = 0x0D,},
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
  {.address = 0x60, .data = 0x35,},
  {.address = 0x45, .data = 0x02,},
  {.address = 0x01, .data = 0x00,},
  {.address = 0x15, .data = 0x00,},
  {.address = 0x17, .data = 0x00,},
  {.address = 0x10, .data = 0x06,},
  {.address = 0x11, .data = 0x00,}
};

#ifdef __cplusplus
}
#endif

#endif /* LSM6DSV16X_YOGA_POSE_RECOGNITION_H */
