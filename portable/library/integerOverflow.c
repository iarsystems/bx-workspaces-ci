/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MSG_NOSIGNAL
#define MSG_NOSIGNAL 1
#endif

#define BUFFER_SIZE 64

char buffer_c[BUFFER_SIZE];

unsigned int recv(int s, void *buf, unsigned int len, int flags) {
  return 0;
}

char decode(char c) {
  /* Decode character */
  return c;
}

char* readMessage(int socket, char *header, int len) {
  int i, header_len;
  long msg_len;
  size_t total_len;
  char *msg;

  recv(socket, buffer_c, BUFFER_SIZE, MSG_NOSIGNAL);
  msg_len = atol(buffer_c);
  header_len = strlen(header);
  total_len = header_len;
  total_len += msg_len; /* POSSIBLE INTEGER OVERFLOW HERE */

  msg = (char*)malloc(total_len); /* VIOLATION, USAGE OF OVERFLOWED VALUE */
  if (!msg) {
    return 0;
  }

  strcpy(msg, header);

  recv(socket, msg + msg_len, msg_len, MSG_NOSIGNAL);

  for (i = header_len; i < total_len; i++) { /* VIOLATION, USAGE OF OVERFLOWED VALUE */
    msg[i] = decode(msg[i]);
  }
  return msg;
}
