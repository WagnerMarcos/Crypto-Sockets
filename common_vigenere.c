#include "common_vigenere.h"

void vigenere_encrypt(vigenere_cipher_t *c, char *msg, 
						unsigned char *encrypted, unsigned int l){
	for(c->i=0; c->i<l; c->i++){
		encrypted[c->i] = (msg[c->i]+(c->key)[c->i%c->key_l]);		// Encripto
	}
}

void vigenere_deencrypt(vigenere_cipher_t *c, char *deencrypted, 
						unsigned char *msg, unsigned int l){
	for(c->i = 0; c->i < l; c->i++){
		deencrypted[c->i] = (char) msg[c->i] - (c->key)[c->i%c->key_l] % 255;
	}
}

void vigenere_init(vigenere_cipher_t *c, char *key){
    int i = 0;
	c->i = 0;

    while (key[i] != 0){
        c->key[i] = key[i];
        i++;
    }
	c->key_l = i;
}
