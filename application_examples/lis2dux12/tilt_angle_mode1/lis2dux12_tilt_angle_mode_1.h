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

#ifndef LIS2DUX12_TILT_ANGLE_MODE_1_H
#define LIS2DUX12_TILT_ANGLE_MODE_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifndef MEMS_UCF_EXT_SHARED_TYPES
#define MEMS_UCF_EXT_SHARED_TYPES

/*
 * UCF extended format supports the following commands:
 * - MEMS_UCF_OP_READ: read the register at the location specified by the
 *   "address" field ("data" field is ignored
 * - MEMS_UCF_OP_WRITE: write the value specified by the "data" field at the
 *   location specified by the "address" field
 * - MEMS_UCF_OP_DELAY: wait the number of milliseconds specified by the "data"
 *   field ("address" field is ignored)
 * - MEMS_UCF_OP_POLL_SET: poll the register at the location specified by the
 *   "address" field until all the bits identified by the mask specified by the
 *   "data" field are set to 1
 * - MEMS_UCF_OP_POLL_RESET: poll the register at the location specified by the
 *   "address" field until all the bits identified by the mask specified by the
 *   "data" field are reset to 0
 */

#define MEMS_UCF_OP_READ       0
#define MEMS_UCF_OP_WRITE      1
#define MEMS_UCF_OP_DELAY      2
#define MEMS_UCF_OP_POLL_SET   3
#define MEMS_UCF_OP_POLL_RESET 4

typedef struct {
  uint8_t op;
  uint8_t address;
  uint8_t data;
} ucf_line_ext_t;

#endif /* MEMS_UCF_EXT_SHARED_TYPES */

/** Configuration array generated from Unico Tool **/
static const ucf_line_ext_t lis2dux12_tilt_angle_mode_1[] = {
  { .op = MEMS_UCF_OP_WRITE, .address = 0x13, .data = 0x10 },
  { .op = MEMS_UCF_OP_DELAY, .address = 0, .data = 5 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x14, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x3F, .data = 0x80 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x04, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x05, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x17, .data = 0x40 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x02, .data = 0x01 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x08, .data = 0xB8 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xE4 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xEE },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x0A },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x01 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x01 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x02, .data = 0x01 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x08, .data = 0xC8 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xDC },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xF0 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xFC },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x02, .data = 0x01 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x08, .data = 0xDC },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x3F },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x0C },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x1F },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x02, .data = 0x01 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x08, .data = 0xF0 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x3F, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x3F, .data = 0x80 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x17, .data = 0x40 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x02, .data = 0x01 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x08, .data = 0xFC },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x08 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x80 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x02, .data = 0x11 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x08, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x80 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xB6 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x05 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x80 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xB2 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xB8 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x04 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x80 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x59 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xB9 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xEF },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xE0 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xFD },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xB7 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xCD },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xE0 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xA5 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xB2 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x07 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x80 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xF0 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xB4 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xAB },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xE0 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xAE },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xAE },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x89 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xE0 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x80 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x36 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x0C },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x80 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xA5 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x32 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x0B },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x80 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xAE },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x2E },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x67 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xE0 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xF0 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x34 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x45 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xE0 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xB2 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x38 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x0E },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x80 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xFD },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x37 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x23 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xE0 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x59 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x39 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0x01 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x09, .data = 0xE0 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x3F, .data = 0x80 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x17, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x04, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x05, .data = 0x10 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x02, .data = 0x01 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x3F, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x1F, .data = 0x01 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x3F, .data = 0x80 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x0D, .data = 0x01 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x3A, .data = 0x21 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x3F, .data = 0x00 },
  { .op = MEMS_UCF_OP_WRITE, .address = 0x14, .data = 0x70 }
};

#ifdef __cplusplus
}
#endif

#endif /* LIS2DUX12_TILT_ANGLE_MODE_1_H */

