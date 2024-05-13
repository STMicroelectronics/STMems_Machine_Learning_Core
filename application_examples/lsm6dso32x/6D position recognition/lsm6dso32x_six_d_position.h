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

#ifndef LSM6DSO32X_SIX_D_POSITION_H
#define LSM6DSO32X_SIX_D_POSITION_H

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
const ucf_line_t lsm6dso32x_six_d_position[] = {
  {.address = 0x10, .data = 0x00,},
  {.address = 0x11, .data = 0x00,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x04, .data = 0x00,},
  {.address = 0x05, .data = 0x00,},
  {.address = 0x17, .data = 0x40,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xEA,},
  {.address = 0x09, .data = 0x58,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x62,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x0A,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xF2,},
  {.address = 0x09, .data = 0x10,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xFA,},
  {.address = 0x09, .data = 0x3C,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x6E,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x7A,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x3C,},
  {.address = 0x09, .data = 0x3F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x84,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x88,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x8C,},
  {.address = 0x09, .data = 0x00,},
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
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x6E,},
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
  {.address = 0x08, .data = 0x7A,},
  {.address = 0x09, .data = 0xCD,},
  {.address = 0x09, .data = 0x34,},
  {.address = 0x09, .data = 0x05,},
  {.address = 0x09, .data = 0x80,},
  {.address = 0x09, .data = 0xCD,},
  {.address = 0x09, .data = 0x34,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x81,},
  {.address = 0x09, .data = 0xCD,},
  {.address = 0x09, .data = 0x34,},
  {.address = 0x09, .data = 0x56,},
  {.address = 0x09, .data = 0xE5,},
  {.address = 0x09, .data = 0xCD,},
  {.address = 0x09, .data = 0x34,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xA2,},
  {.address = 0x09, .data = 0xCD,},
  {.address = 0x09, .data = 0x34,},
  {.address = 0x09, .data = 0x34,},
  {.address = 0x09, .data = 0xE4,},
  {.address = 0x09, .data = 0xCD,},
  {.address = 0x09, .data = 0x34,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xA2,},
  {.address = 0x09, .data = 0xCD,},
  {.address = 0x09, .data = 0x34,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xA1,},
  {.address = 0x09, .data = 0xCD,},
  {.address = 0x09, .data = 0x34,},
  {.address = 0x09, .data = 0x12,},
  {.address = 0x09, .data = 0xE3,},
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
  {.address = 0x01, .data = 0x00,},
  {.address = 0x10, .data = 0x20,},
  {.address = 0x11, .data = 0x00,}
};

#ifdef __cplusplus
}
#endif

#endif /* LSM6DSO32X_SIX_D_POSITION_H */

