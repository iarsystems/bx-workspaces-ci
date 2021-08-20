/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/
#include <stdio.h>
#include <stdlib.h>

void evalOrder(int i, int *b) {   
  int a = i + b[++i];   // Do not depend on the order of evaluation for side effects
  printf("%d, %d", a, i); // CERT C
}
