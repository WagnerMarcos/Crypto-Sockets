#ifndef RECEIVER__T
#define RECEIVER__T

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "common_socket.h"
#include "common_caesar.h"
#include "common_vigenere.h"
#include "common_rc4.h"

void deencrypt_with_caesar(socket_t* s, char *key, FILE* fp);
void deencrypt_with_vigenere(socket_t* s, char *key, FILE* fp);
void deencrypt_with_rc4(socket_t* s, char *key, FILE* fp);
void print_data(FILE* fp, char* buffer,unsigned int size);

#endif
