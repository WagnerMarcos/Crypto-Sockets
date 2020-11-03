#ifndef CLIENT__T
#define CLIENT__T

#include <stdio.h>
#include <string.h>
#include "client_parser.h"
#include "client_transmitter.h"
#include "common_socket.h"

#define ERROR 1
#define MAX_KEY_LENGTH 64
#define MAX_METHOD_LENGTH 10

int parse_method(char* arg, char* method);
int parse_key(char* arg, char* method);

#endif
