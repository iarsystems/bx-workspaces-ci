/*
  Copyright (c) 2020-2024, IAR Systems AB.
  SPDX-License-Identifier: MIT
*/

/*!
  \file    test-crc32.c
  \brief   CRC32 test module
  \version 20240130
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "library/include/library.h"

#define WORDS 128

typedef struct
{
  int32_t payload[WORDS];
  int32_t header;
  int16_t crc;
} packet_t;

void main()
{
  packet_t pkt = { .header = 0xA5A5A5A5 };
  int8_t *pkt_b = (int8_t *)pkt.payload;

  for (int8_t *p = pkt_b; p < pkt_b + (4 * WORDS); p+=4)
    strcpy((char *)p, "01234");

  pkt.crc = crc32(pkt.header, pkt.payload, WORDS);

#if defined(NDEBUG)
  while (1);                     /* main() does not return */
#else
  printf("CRC32 : 0x%08X\n", pkt.crc);
  printf("HEADER: 0x%08X\n", pkt.header);
#endif
}
