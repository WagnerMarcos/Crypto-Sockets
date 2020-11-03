#ifndef SERVER__T
#define SERVER__T

#include <stdio.h>
#include <string.h>
#include "common_socket.h"
#include "server_receiver.h"

#define ERROR 1
#define METHOD_ARG_LENGTH 9
#define MAX_KEY_LENGTH 64
#define MAX_METHOD_LENGTH 10

int parse_method(char* arg, char* method);
int parse_key(char* arg, char* method);

#endif
