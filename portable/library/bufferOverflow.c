/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 999

char buffer[BUFFER_SIZE];

void fillBuffer()
{
    int size, character;
    printf("Please enter filling parameters: \n");
    scanf("%d%d", &size, &character);
   
    /* Uncomment to fix possible buffer overflow */
    /* if (size < 0 || size > BUFFER_SIZE) { */
    /*    printf("Wrong size"); */
    /*    return; */
    /* } */  
   
    memset(buffer, character, size); /* POSSIBLE BUFFER OVERFLOW HERE */
}

void resetBuffer(int size)
{
    int i;
    memset(buffer, 0, size);
}

void resetAll()
{
    /* Uncomment to fix possible buffer overflow */
    //resetBuffer(1000 /* BUFFER_SIZE */); /* POSSIBLE BUFFER OVERFLOW HERE */
}
