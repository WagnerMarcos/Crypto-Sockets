#ifndef CLIENT__T
#define CLIENT__T

#include <stdio.h>
#include <string.h>

#include "client_transmitter.h"
#include "common_socket.h"
#define ERROR 1
#define METHOD_ARG_LENGTH 9
#define METHOD_ARG "--method="
#define MAX_METHOD_LENGTH 10

#define KEY_ARG_LENGTH 6
#define KEY_ARG "--key="
#define MAX_KEY_LENGTH 64
#define ERROR 1

int parse_method(char* arg, char* method);
int parse_key(char* arg, char* method);

#endif
