#include "common_rc4.h"
#include <stdio.h>

int rc4_string_to_uchar_arr(unsigned char uchar_arr[], 
                            char string[], unsigned int l){
    int i = 0;
    for (i = 0; i < l; i++){
        uchar_arr[i]=(unsigned char) string[i];
    }
    return 0;
}

void rc4_swap(unsigned char *s, unsigned int i, unsigned int j){
    unsigned char aux = s[i];
    s[i] = s[j];
    s[j] = aux;
}

/* KSA */
void rc4_init(rc4_cipher_t *c, char *key){
    c->i = 0;
    c->j = 0;
    int i = 0;          // Uso un par i,j distinto solo para que sea mas legible
    int j = 0;
    rc4_string_to_uchar_arr(c->key,key, strlen(key));
    c->key_l = strlen(key);
    for (i = 0; i < 256; i++)
        c->S[i] = i;
    for (i = j = 0; i < 256; i++){
        j = (j + c->key[i % c->key_l] + c->S[i]) % (256);
        rc4_swap(c->S, i, j);  
    }
}

/* PRGA */
void rc4_output(rc4_cipher_t *c, unsigned char *new_str, 
                char *message, unsigned int l){
    unsigned char ch = 0;
    int k = 0;
    unsigned char aux_buf[64];
    rc4_string_to_uchar_arr(aux_buf, message, l);
    for (k = 0; k < l; k++){ 
        c->i = (c->i + 1) % (256);
        c->j = (c->j + c->S[c->i]) % (256);
        rc4_swap(c->S, c->i, c->j);
        ch = c->S[(c->S[c->i] + c->S[c->j]) % (256)];
        new_str[k] = message[k] ^ ch;
    }
}
