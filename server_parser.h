#ifndef CLIENT_PARSER__T
#define CLIENT_PARSER__T

#include <stdbool.h>
#include <stdio.h>

#define METHOD_ARG_LENGTH 9
#define METHOD_ARG "--method="
#define MAX_METHOD_LENGTH 10

#define KEY_ARG_LENGTH 6
#define KEY_ARG "--key="
#define MAX_KEY_LENGTH 64

int parse_key(char *arg, char *key);
int parse_method(char* arg, char* method);

#endif
