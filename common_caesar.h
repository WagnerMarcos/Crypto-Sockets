#ifndef CAESAR__T
#define CAESAR__T

#include <stdio.h>

typedef struct caesar_cipher_t{
    int key;
}caesar_cipher_t;

void caesar_encrypt(caesar_cipher_t *c, char *msg, 
                    unsigned char *encrypted, size_t l);
void caesar_deencrypt(caesar_cipher_t *c, char *msg, 
                    unsigned char *encr_txt, size_t l);
void caesar_init(caesar_cipher_t *c, int key);

#endif
