/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

#include <stdio.h>

enum figures_e {
  SPHERE,
  CIRCLE,
  CUBE,
  SQUARE,
  HEMISPHERE
};

static void guessFigure(int round, int volumetric) {
  int figure;
  if (round && volumetric) {
    figure = SPHERE;
  } 
  else if (round && !volumetric) {
    figure = CIRCLE; 
  } 
  else if (!round && volumetric) {
    figure = CUBE;
  } 
  else {
    figure = SQUARE;
  }
  
  switch (figure) {
    case SQUARE:
      printf("This is a sphere");
      break;
    /* remove the case below to fix the violation */
    case HEMISPHERE:
      printf("This is a hemispere");
      break;
    case CIRCLE:
      printf("This is a circle");
      break;
    case CUBE:
      printf("This is a cube");
      break;
    default:
      printf("This is a square");
      break;
  }
}

static void checkRange(char* cur) {
  if ((*cur < '0') || (*cur > '9')) {
    printf("Error: only digits are permitted");
    return;
  }
  /* obviously dead code */
  if ((*cur >= 'a') && (*cur <= 'f')) {
    /* process hex value */
  }
}

static void checkSequence(char cur[]) {
  if (cur[0] == '-') {
    printf("Error: only positive values are permitted");
    return;
  }
  /* misplaced null check */
  if (cur == 0) {
    printf("Error: null argument provided");
    return;
  }
}
