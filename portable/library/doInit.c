/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

extern int do_auth(void);
enum { BUFFERSIZE = 24 };
void doInit(const char *msg) {
  const char *error_log;   //error_log has not been initialized, an indeterminate value is read
  char buffer[BUFFERSIZE];
  sprintf(buffer, "Error: %s", error_log);
  printf("%s\n", buffer);
}
