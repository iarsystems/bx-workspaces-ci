/*
  Copyright (c) 2020-2024, IAR Systems AB.
  SPDX-License-Identifier: MIT
*/

/*!
  \file    library.h
  \brief   Library header
  \version 20240130
*/

#include <stdint.h>
#include <stdlib.h>

/* Library functions */
extern int32_t crc32(int32_t crc, int32_t * data, size_t words);
extern int16_t crc16(int16_t crc, int8_t  * data, size_t bytes);
