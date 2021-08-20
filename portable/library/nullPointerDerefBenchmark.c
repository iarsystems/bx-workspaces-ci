/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

#include <stdio.h>

static int i = 10;
static int* x;

static int helper1(char b) {
  if (b) {
     return 0;
  }
  return *x;
}

static int helper2() {
  return *x;
}

static int noFalseViolation1(int level) {
  x = 0;
  if (level > 0) {
     x = &i;
  }
  if (level > 4) {
     return *x;
  }
  return 0;
}

static int noFalseViolation2(char b) {
  x = 0;
  if (b) {
    x = &i;
  }
  if (b) {
    return *x;
  }
  return 0;
}

static int noFalseViolation3(char b) {
  int* y = 0;
  if (x != 0) {
    y = &i;
  }
  if (y != 0) {
    return *x + *y;
  }
  else {
    return 0;
  }
}

static int trueViolation(char b) {
  int* y = 0;
  if (x != 0) {
    y = &i;
  }
  if (y != 0) {
    return *x + *y;
  }
  else {
    return *x;
  }
}

static int functionCall_noFalseViolation1(char b) {
  x = 0;
  if (!b) {
    x = &i;
  }
  return helper1(b);
}

static int functionCall_noFalseViolation2(int* x) {
  if (x == 0) { /* checking parameter (not the global variable) for null */
    printf("x is null");
  }
  return helper2();
}

static int functionCall_trueViolation1(char b) {
  x = 0;
  if (b) {
    x = &i;
  }
  return helper1(b);
}

static int functionCall_trueViolation2() {
  x = 0;
  return helper2();
}
