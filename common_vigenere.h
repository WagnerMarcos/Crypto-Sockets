#ifndef VIGENERE__T
#define VIGENERE__T

#include "string.h"
#include <stdio.h>

typedef struct vigenere_cipher_t{
    char key[64];
    unsigned int key_l;
    unsigned int i;
}vigenere_cipher_t;

void vigenere_encrypt(vigenere_cipher_t *c, char *msg, 
                        unsigned char *encrypted, unsigned int l);
void vigenere_deencrypt(vigenere_cipher_t *c, char *deencrypted, 
                        unsigned char *msg, unsigned int l);
void vigenere_init(vigenere_cipher_t *c, char *key);

#endif
