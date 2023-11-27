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

#ifndef TENNIS_ACTIVITY_H
#define TENNIS_ACTIVITY_H

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
const ucf_line_t tennis_activity[] = {
  {.address = 0x10, .data = 0x00,},
  {.address = 0x11, .data = 0x00,},
  {.address = 0x01, .data = 0x80,},
  {.address = 0x04, .data = 0x00,},
  {.address = 0x05, .data = 0x00,},
  {.address = 0x17, .data = 0x40,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xEA,},
  {.address = 0x09, .data = 0x7E,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x92,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0x01,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x14,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xF2,},
  {.address = 0x09, .data = 0xD0,},
  {.address = 0x02, .data = 0x11,},
  {.address = 0x08, .data = 0xFA,},
  {.address = 0x09, .data = 0x3C,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0xAA,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x09, .data = 0xB6,},
  {.address = 0x09, .data = 0x03,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0x3C,},
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
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x1C,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x20,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x01,},
  {.address = 0x09, .data = 0x1C,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x10,},
  {.address = 0x09, .data = 0x04,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xFC,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x7C,},
  {.address = 0x09, .data = 0x10,},
  {.address = 0x09, .data = 0x08,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xFC,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x7C,},
  {.address = 0x09, .data = 0x10,},
  {.address = 0x09, .data = 0x1C,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xFC,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x7C,},
  {.address = 0x09, .data = 0x11,},
  {.address = 0x09, .data = 0x04,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xFC,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x7C,},
  {.address = 0x09, .data = 0x11,},
  {.address = 0x09, .data = 0x08,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xFC,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x7C,},
  {.address = 0x09, .data = 0x11,},
  {.address = 0x09, .data = 0x18,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xFC,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0x7C,},
  {.address = 0x09, .data = 0x1F,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x02, .data = 0x31,},
  {.address = 0x08, .data = 0xAA,},
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
  {.address = 0x08, .data = 0xB6,},
  {.address = 0x09, .data = 0x65,},
  {.address = 0x09, .data = 0xB8,},
  {.address = 0x09, .data = 0x05,},
  {.address = 0x09, .data = 0x84,},
  {.address = 0x09, .data = 0x9D,},
  {.address = 0x09, .data = 0x4E,},
  {.address = 0x09, .data = 0x40,},
  {.address = 0x09, .data = 0xA5,},
  {.address = 0x09, .data = 0x57,},
  {.address = 0x09, .data = 0xB0,},
  {.address = 0x09, .data = 0x38,},
  {.address = 0x09, .data = 0xC2,},
  {.address = 0x09, .data = 0xA8,},
  {.address = 0x09, .data = 0x38,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0xA0,},
  {.address = 0x09, .data = 0xF4,},
  {.address = 0x09, .data = 0x3A,},
  {.address = 0x09, .data = 0x48,},
  {.address = 0x09, .data = 0xE1,},
  {.address = 0x09, .data = 0x3F,},
  {.address = 0x09, .data = 0x3C,},
  {.address = 0x09, .data = 0xC0,},
  {.address = 0x09, .data = 0xA0,},
  {.address = 0x09, .data = 0xFA,},
  {.address = 0x09, .data = 0x3E,},
  {.address = 0x09, .data = 0x0C,},
  {.address = 0x09, .data = 0x89,},
  {.address = 0x09, .data = 0x89,},
  {.address = 0x09, .data = 0xAF,},
  {.address = 0x09, .data = 0x09,},
  {.address = 0x09, .data = 0x82,},
  {.address = 0x09, .data = 0x16,},
  {.address = 0x09, .data = 0x3B,},
  {.address = 0x09, .data = 0xC8,},
  {.address = 0x09, .data = 0xE1,},
  {.address = 0x09, .data = 0xBE,},
  {.address = 0x09, .data = 0x27,},
  {.address = 0x09, .data = 0xAC,},
  {.address = 0x09, .data = 0xC7,},
  {.address = 0x09, .data = 0x9D,},
  {.address = 0x09, .data = 0x3B,},
  {.address = 0x09, .data = 0xB4,},
  {.address = 0x09, .data = 0xC5,},
  {.address = 0x09, .data = 0xC7,},
  {.address = 0x09, .data = 0xBB,},
  {.address = 0x09, .data = 0x8C,},
  {.address = 0x09, .data = 0xE0,},
  {.address = 0x09, .data = 0xA7,},
  {.address = 0x09, .data = 0xA9,},
  {.address = 0x09, .data = 0x00,},
  {.address = 0x09, .data = 0xA4,},
  {.address = 0x09, .data = 0x5D,},
  {.address = 0x09, .data = 0x39,},
  {.address = 0x09, .data = 0x40,},
  {.address = 0x09, .data = 0xA1,},
  {.address = 0x09, .data = 0x4B,},
  {.address = 0x09, .data = 0x38,},
  {.address = 0x09, .data = 0x08,},
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
  {.address = 0x01, .data = 0x00,},
  {.address = 0x10, .data = 0x44,},
  {.address = 0x11, .data = 0x4C,}
};

#ifdef __cplusplus
}
#endif

#endif /* TENNIS_ACTIVITY_H */

