/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

/*!
  \file    componentA.c
  \brief   Component A
  \version 20211112 
*/

#include "library.h"

int main()
{
  const uint16_t x = 101;
  const uint16_t y = 202;
  const uint16_t z = 303;
        uint16_t sum;
        uint16_t mul;
        float    log;

  debug_log("Component A!\r\n");

  sum = math_sum(x, y);
  debug_log("Sum = %d\r\n", sum);

  mul = math_mul(sum, z);
  debug_log("Mul = %d\r\n", mul);

  log = math_log(2, 16);
  debug_log("log2(%d) = %f\r\n", 16, log);

  debug_log("Finished execution!\r\n");

  return 0;
}

