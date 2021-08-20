/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1000

typedef struct RECORD {
  int recordID;
  char* setting1;
  char* setting2;
  int internalSetting;
  
} RECORD;

RECORD* cache[CACHE_SIZE];

int clip(int n, int l, int h)
{
  return (n > h) ? h : ((n < l) ? l : n);
}

void clearCache(int from_id, int to_id)
{
  int i;
  for (i = from_id; i <= to_id; i++) {
    if (cache[i] != 0) {
      free(cache[i]);
      cache[i] = 0;
    }
  }
}

void clearAllCache()
{
  //clearCache(0, CACHE_SIZE /* -1 */ ); /* Uncomment to fix accessing out of bounds */
}
