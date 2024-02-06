/*
  Copyright (c) 2020-2024, IAR Systems AB.
  SPDX-License-Identifier: MIT
*/

/*!
  \file    test-crc16.c
  \brief   CRC16 test module
  \version 20240130
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "library/include/library.h"

#define BYTES 16

typedef struct 
{
  int8_t  payload[BYTES];
  int32_t header;
  int16_t crc;
} packet_t;

void main()
{
  packet_t pkt = { .header = 0xA5A5A5A5 };
  
  strcpy((char *)pkt.payload, "0123456789abcefgh");
  pkt.crc = crc16(0xFF, (int8_t *)pkt.payload, BYTES); 

#if defined(NDEBUG)
  while (1);             /* main() does not return */
#else  
  printf("CRC16 : 0x%04X\n", pkt.crc);
  printf("HEADER: 0x%04X\n", (unsigned int)pkt.header);
#endif
}
