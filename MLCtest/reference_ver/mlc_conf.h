/**
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef MLC_CONF_H
#define MLC_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define MLC_CONF_SENSORS_NUM 1

#ifndef MEMS_CONF_SHARED_TYPES
#define MEMS_CONF_SHARED_TYPES

#define MEMS_CONF_ARRAY_LEN(x) (sizeof(x) / sizeof(x[0]))

/*
 * MEMS_CONF_SHARED_TYPES format supports the following operations:
 * - MEMS_CONF_OP_TYPE_TYPE_READ: read the register at the location specified
 *   by the "address" field ("data" field is ignored)
 * - MEMS_CONF_OP_TYPE_TYPE_WRITE: write the value specified by the "data"
 *   field at the location specified by the "address" field
 * - MEMS_CONF_OP_TYPE_TYPE_DELAY: wait the number of milliseconds specified by
 *   the "data" field ("address" field is ignored)
 * - MEMS_CONF_OP_TYPE_TYPE_POLL_SET: poll the register at the location
 *   specified by the "address" field until all the bits identified by the mask
 *   specified by the "data" field are set to 1
 * - MEMS_CONF_OP_TYPE_TYPE_POLL_RESET: poll the register at the location
 *   specified by the "address" field until all the bits identified by the mask
 *   specified by the "data" field are reset to 0
 */

struct mems_conf_name_list {
	const char *const *list;
	uint16_t len;
};

enum {
	MEMS_CONF_OP_TYPE_READ = 1,
	MEMS_CONF_OP_TYPE_WRITE = 2,
	MEMS_CONF_OP_TYPE_DELAY = 3,
	MEMS_CONF_OP_TYPE_POLL_SET = 4,
	MEMS_CONF_OP_TYPE_POLL_RESET = 5
};

struct mems_conf_op {
	uint8_t type;
	uint8_t address;
	uint8_t data;
};

struct mems_conf_op_list {
	const struct mems_conf_op *list;
	uint32_t len;
};

#endif /* MEMS_CONF_SHARED_TYPES */

#ifndef MEMS_CONF_METADATA_SHARED_TYPES
#define MEMS_CONF_METADATA_SHARED_TYPES

struct mems_conf_application {
	char *name;
	char *version;
};

struct mems_conf_result {
	uint8_t code;
	char *label;
};

enum {
	MEMS_CONF_OUTPUT_CORE_HW = 1,
	MEMS_CONF_OUTPUT_CORE_EMB = 2,
	MEMS_CONF_OUTPUT_CORE_FSM = 3,
	MEMS_CONF_OUTPUT_CORE_MLC = 4,
	MEMS_CONF_OUTPUT_CORE_ISPU = 5
};

enum {
	MEMS_CONF_OUTPUT_TYPE_UINT8_T = 1,
	MEMS_CONF_OUTPUT_TYPE_INT8_T = 2,
	MEMS_CONF_OUTPUT_TYPE_CHAR = 3,
	MEMS_CONF_OUTPUT_TYPE_UINT16_T = 4,
	MEMS_CONF_OUTPUT_TYPE_INT16_T = 5,
	MEMS_CONF_OUTPUT_TYPE_UINT32_T = 6,
	MEMS_CONF_OUTPUT_TYPE_INT32_T = 7,
	MEMS_CONF_OUTPUT_TYPE_UINT64_T = 8,
	MEMS_CONF_OUTPUT_TYPE_INT64_T = 9,
	MEMS_CONF_OUTPUT_TYPE_HALF = 10,
	MEMS_CONF_OUTPUT_TYPE_FLOAT = 11,
	MEMS_CONF_OUTPUT_TYPE_DOUBLE = 12
};

struct mems_conf_output {
	char *name;
	uint8_t core;
	uint8_t type;
	uint16_t len;
	uint8_t reg_addr;
	char *reg_name;
	uint8_t num_results;
	const struct mems_conf_result *results;
};

struct mems_conf_output_list {
	const struct mems_conf_output *list;
	uint16_t len;
};

struct mems_conf_mlc_identifier {
	uint8_t fifo_tag;
	uint16_t id;
	char *label;
};

struct mems_conf_mlc_identifier_list {
	const struct mems_conf_mlc_identifier *list;
	uint16_t len;
};

#endif /* MEMS_CONF_METADATA_SHARED_TYPES */

static const char *const mlc_conf_format_version = "2.0";

static const char *const mlc_conf_description = "Generated sensor configuration for MLC core";

static const struct mems_conf_application mlc_conf_application = {
	.name = "MLC Tool",
	.version = "2.3.4"
};

static const char *const mlc_conf_date = "2025-06-20 10:57:03";

/* Sensor names */

static const char *const mlc_conf_names_0[] = {
	"LSM6DSV16X"
};

static const struct mems_conf_name_list mlc_conf_name_lists[MLC_CONF_SENSORS_NUM] = {
	{ .list = mlc_conf_names_0, .len = (uint16_t)MEMS_CONF_ARRAY_LEN(mlc_conf_names_0) }
};

/* Configurations */

static const struct mems_conf_op mlc_conf_conf_0[] = {
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x10, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x11, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x01, .data = 0x80 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x04, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x05, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x17, .data = 0x40 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x11 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xE8 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x3C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x11 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xF1 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x01 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x21 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x11 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xEA },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x66 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x70 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x0A },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x11 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xF2 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xF0 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x11 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xFA },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x5C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x72 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x7E },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x31 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0x5C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x3F },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x14 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xFC },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x7C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x1F },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x31 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0x72 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x01, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x01, .data = 0x80 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x17, .data = 0x40 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x31 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0x7E },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x72 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x4E },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x80 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xA0 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xB8 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x3E },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x40 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xE0 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x01, .data = 0x80 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x17, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x04, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x05, .data = 0x10 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x01 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x01, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x5E, .data = 0x02 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x01, .data = 0x80 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x0D, .data = 0x01 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x60, .data = 0x35 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x45, .data = 0x02 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x01, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x10, .data = 0x06 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x11, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x15, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x17, .data = 0x03 }
};

static const struct mems_conf_op_list mlc_conf_confs[MLC_CONF_SENSORS_NUM] = {
	{ .list = mlc_conf_conf_0, .len = (uint32_t)MEMS_CONF_ARRAY_LEN(mlc_conf_conf_0) }
};

/* Outputs */

static const struct mems_conf_result mlc_conf_results_0_0[] = {
	{ .code = 0x00, .label = "static" },
	{ .code = 0x04, .label = "medium" },
	{ .code = 0x08, .label = "high" }
};

static const struct mems_conf_output mlc_conf_outputs_0[] = {
	{
		.name = "Categorical output",
		.core = MEMS_CONF_OUTPUT_CORE_MLC,
		.type = MEMS_CONF_OUTPUT_TYPE_UINT8_T,
		.len = 1,
		.reg_addr = 0x70,
		.reg_name = "MLC1_SRC",
		.num_results = (uint8_t)MEMS_CONF_ARRAY_LEN(mlc_conf_results_0_0),
		.results = mlc_conf_results_0_0
	}
};

static const struct mems_conf_output_list mlc_conf_output_lists[MLC_CONF_SENSORS_NUM] = {
	{ .list = mlc_conf_outputs_0, .len = (uint16_t)MEMS_CONF_ARRAY_LEN(mlc_conf_outputs_0) }
};

/* MLC identifiers */

static const struct mems_conf_mlc_identifier mlc_conf_mlc_identifiers_0[] = {
	{ .fifo_tag = 0x1C, .id = 0x0370, .label = "F1_PEAK_TO_PEAK_ACC_V2" }
};

static const struct mems_conf_mlc_identifier_list mlc_conf_mlc_identifier_lists[MLC_CONF_SENSORS_NUM] = {
	{ .list = mlc_conf_mlc_identifiers_0, .len = (uint16_t)MEMS_CONF_ARRAY_LEN(mlc_conf_mlc_identifiers_0) }
};

#ifdef __cplusplus
}
#endif

#endif /* MLC_CONF_H */
