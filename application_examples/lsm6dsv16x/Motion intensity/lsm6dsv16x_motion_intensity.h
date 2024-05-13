/**
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef LSM6DSV16X_MOTION_INTENSITY_H
#define LSM6DSV16X_MOTION_INTENSITY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifndef MEMS_UCF_SHARED_TYPES
#define MEMS_UCF_SHARED_TYPES

/** Common data block definition **/
typedef struct {
  uint8_t address;
  uint8_t data;
} ucf_line_t;

#endif /* MEMS_UCF_SHARED_TYPES */

/** Configuration array generated from MLC Tool **/
const ucf_line_t lsm6dsv16x_motion_intensity[] = {
  {.address = 0x10, .data = 0x00,},
  {.address = 0x11, .data = 0x00,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x04, .data = 0x00,},
  {.address = 0x05, .data = 0x00,},
  {.address = 0x17, .data = 0x40,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xEA,},
  {.address = 0x09, .data = 0x66,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x70,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x0A,},
  {.address = 0x09, .data = 0x01,},
  {.address = 0x09, .data = 0x2D,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xFA,},
  {.address = 0x09, .data = 0x5C,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x72,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x7E,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x5C,},
  {.address = 0x09, .data = 0x3F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x01,},
  {.address = 0x09, .data = 0x10,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x1F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x72,},
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
  {.address = 0x08, .data = 0x7E,},
  {.address = 0x09, .data = 0x9C,},
  {.address = 0x09, .data = 0x20,},
  {.address = 0x09, .data = 0x10,},
  {.address = 0x09, .data = 0xC0,},
  {.address = 0x09, .data = 0x04,},
  {.address = 0x09, .data = 0x23,},
  {.address = 0x09, .data = 0x21,},
  {.address = 0x09, .data = 0xC0,},
  {.address = 0x09, .data = 0xFE,},
  {.address = 0x09, .data = 0x25,},
  {.address = 0x09, .data = 0x32,},
  {.address = 0x09, .data = 0xC0,},
  {.address = 0x09, .data = 0x40,},
  {.address = 0x09, .data = 0x28,},
  {.address = 0x09, .data = 0x43,},
  {.address = 0x09, .data = 0xC0,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x2D,},
  {.address = 0x09, .data = 0x54,},
  {.address = 0x09, .data = 0xC0,},
  {.address = 0x09, .data = 0x40,},
  {.address = 0x09, .data = 0x31,},
  {.address = 0x09, .data = 0x65,},
  {.address = 0x09, .data = 0xC0,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x35,},
  {.address = 0x09, .data = 0x76,},
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
  {.address = 0x60, .data = 0x05,},
  {.address = 0x45, .data = 0x02,},
  {.address = 0x01, .data = 0x00,},
  {.address = 0x15, .data = 0x00,},
  {.address = 0x17, .data = 0x00,},
  {.address = 0x10, .data = 0x03,},
  {.address = 0x11, .data = 0x00,}
};

#ifdef __cplusplus
}
#endif

#endif /* LSM6DSV16X_MOTION_INTENSITY_H */

