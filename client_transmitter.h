#ifndef TRANSMITTER__T
#define TRANSMITTER__T

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "common_socket.h"
#include "common_caesar.h"
#include "common_vigenere.h"
#include "common_rc4.h"

size_t reader_get_text(bool *there_is_text, char buffer[], size_t buffer_size);
void encrypt_with_caesar(socket_t* s, char *key);
void encrypt_with_vigenere(socket_t* s, char *key);
void encrypt_with_rc4(socket_t* s, char *key);

#endif
