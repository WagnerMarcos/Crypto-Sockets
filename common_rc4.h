#ifndef RC4__T
#define RC4__T

#include <string.h>

typedef struct rc4_cipher_t{
    unsigned int i;
    unsigned int j;
    unsigned char key[64];
    unsigned int key_l;
    unsigned char S[256];
}rc4_cipher_t;

int rc4_string_to_uchar_arr(unsigned char uchar_arr[], 
                            char string[], unsigned int l);
void rc4_swap(unsigned char *s, unsigned int i, unsigned int j);
void rc4_init(rc4_cipher_t *c, char *key);
void rc4_output(rc4_cipher_t *c, unsigned char *new_str, 
                char *message, unsigned int l);

#endif
