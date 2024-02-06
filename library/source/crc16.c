/*
  Copyright (c) 2020-2024, IAR Systems AB.
  SPDX-License-Identifier: MIT
*/

/*!
  \file    crc16.c
  \brief   Software implementation for CRC16
  \version 20240130
*/

#include <stdint.h>
#include <stdlib.h>

int16_t crc16(int16_t crc, int8_t * data, size_t bytes) 
{
  while (bytes--) 
  {
    int32_t i;
    int8_t byte = *(data++);
    
    for (i = 0; i < 8; ++i)
    {
      long ocrc = crc;
      crc <<= 1;
      if (byte & 0x80)
        crc |= 1;
      if (ocrc & 0x8000)
        crc ^= 0x1021;
      byte <<= 1;
    }
  }
  return crc;
}