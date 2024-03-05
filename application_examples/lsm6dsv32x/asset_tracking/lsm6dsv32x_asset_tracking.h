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

#ifndef LSM6DSV32X_ASSET_TRACKING_H
#define LSM6DSV32X_ASSET_TRACKING_H

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

/** Configuration array generated from Unico Tool **/
const ucf_line_t lsm6dsv32x_asset_tracking[] = {
  {.address = 0x10, .data = 0x00,},
  {.address = 0x11, .data = 0x00,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x04, .data = 0x00,},
  {.address = 0x05, .data = 0x00,},
  {.address = 0x5F, .data = 0x4B,},
  {.address = 0x46, .data = 0x03,},
  {.address = 0x47, .data = 0x00,},
  {.address = 0x0A, .data = 0x00,},
  {.address = 0x0B, .data = 0x00,},
  {.address = 0x0C, .data = 0x00,},
  {.address = 0x0E, .data = 0x00,},
  {.address = 0x0F, .data = 0x03,},
  {.address = 0x10, .data = 0x00,},
  {.address = 0x17, .data = 0x40,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0x7A,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x04,},
  {.address = 0x02, .data = 0x41,},
  {.address = 0x08, .data = 0x00,},
  {.address = 0x09, .data = 0x92,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x16,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x0F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x38,},
  {.address = 0x09, .data = 0x66,},
  {.address = 0x09, .data = 0x2E,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x05,},
  {.address = 0x09, .data = 0x04,},
  {.address = 0x09, .data = 0x23,},
  {.address = 0x09, .data = 0x05,},
  {.address = 0x09, .data = 0x12,},
  {.address = 0x09, .data = 0x05,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x64,},
  {.address = 0x09, .data = 0x22,},
  {.address = 0x09, .data = 0x51,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x14,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x0C,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xCD,},
  {.address = 0x09, .data = 0x34,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x12,},
  {.address = 0x09, .data = 0x53,},
  {.address = 0x09, .data = 0x99,},
  {.address = 0x09, .data = 0x41,},
  {.address = 0x09, .data = 0xA5,},
  {.address = 0x09, .data = 0x0E,},
  {.address = 0x09, .data = 0x0C,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x04, .data = 0x00,},
  {.address = 0x05, .data = 0x11,},
  {.address = 0x17, .data = 0x80,},
  {.address = 0x01, .data = 0x00,},
  {.address = 0x01, .data = 0x00,},
  {.address = 0x02, .data = 0x3F,},
  {.address = 0x07, .data = 0x00,},
  {.address = 0x08, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x0A, .data = 0x00,},
  {.address = 0x0B, .data = 0x00,},
  {.address = 0x0C, .data = 0x00,},
  {.address = 0x0D, .data = 0x00,},
  {.address = 0x0E, .data = 0x00,},
  {.address = 0x10, .data = 0x20,},
  {.address = 0x11, .data = 0x00,},
  {.address = 0x12, .data = 0x44,},
  {.address = 0x13, .data = 0x00,},
  {.address = 0x14, .data = 0x00,},
  {.address = 0x15, .data = 0x00,},
  {.address = 0x16, .data = 0x00,},
  {.address = 0x17, .data = 0x00,},
  {.address = 0x18, .data = 0xE0,},
  {.address = 0x19, .data = 0x00,},
  {.address = 0x56, .data = 0x00,},
  {.address = 0x57, .data = 0x00,},
  {.address = 0x58, .data = 0x00,},
  {.address = 0x59, .data = 0x00,},
  {.address = 0x5A, .data = 0x00,},
  {.address = 0x5B, .data = 0x00,},
  {.address = 0x5C, .data = 0x00,},
  {.address = 0x5D, .data = 0x00,},
  {.address = 0x5E, .data = 0x02,},
  {.address = 0x5F, .data = 0x02,},
  {.address = 0x6F, .data = 0x00,},
  {.address = 0x70, .data = 0x00,},
  {.address = 0x71, .data = 0x00,},
  {.address = 0x72, .data = 0x00,},
  {.address = 0x73, .data = 0x00,},
  {.address = 0x74, .data = 0x00,},
  {.address = 0x75, .data = 0x00,},
  {.address = 0x74, .data = 0x00,},
  {.address = 0x75, .data = 0x00,},
  {.address = 0x10, .data = 0x00,},
  {.address = 0x11, .data = 0x00,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x04, .data = 0x00,},
  {.address = 0x05, .data = 0x00,},
  {.address = 0x17, .data = 0x40,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xEA,},
  {.address = 0x09, .data = 0x32,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x44,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x0A,},
  {.address = 0x09, .data = 0x01,},
  {.address = 0x09, .data = 0x0F,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xFA,},
  {.address = 0x09, .data = 0x14,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x4A,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x56,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x02, .data = 0x21,},
  {.address = 0x08, .data = 0x14,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x01,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x3F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x0C,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x10,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x10,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xFC,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x7C,},
  {.address = 0x09, .data = 0x1F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x21,},
  {.address = 0x08, .data = 0x4A,},
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
  {.address = 0x08, .data = 0x56,},
  {.address = 0x09, .data = 0xAE,},
  {.address = 0x09, .data = 0x2B,},
  {.address = 0x09, .data = 0x02,},
  {.address = 0x09, .data = 0x82,},
  {.address = 0x09, .data = 0x33,},
  {.address = 0x09, .data = 0x3B,},
  {.address = 0x09, .data = 0x04,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0xF2,},
  {.address = 0x09, .data = 0x3C,},
  {.address = 0x09, .data = 0xC8,},
  {.address = 0x09, .data = 0xE1,},
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
  {.address = 0x15, .data = 0x00,},
  {.address = 0x17, .data = 0x07,},
  {.address = 0x10, .data = 0x44,},
  {.address = 0x11, .data = 0x00,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x17, .data = 0x80,},
  {.address = 0x04, .data = 0x00,},
  {.address = 0x05, .data = 0x11,},
  {.address = 0x02, .data = 0x01,},
  {.address = 0x01, .data = 0x00,}
};

#ifdef __cplusplus
}
#endif

#endif /* LSM6DSV32X_ASSET_TRACKING_H */

