#include "common_vigenere.h"

void vigenere_encrypt(vigenere_cipher_t *c, char *msg, 
						unsigned char *encrypted, unsigned int l){
	for(int i=0; i<l; c->i++){
		encrypted[i] = (msg[i] + (c->key)[c->i%c->key_l]);		// Encripto
		i++;
	}
}

void vigenere_deencrypt(vigenere_cipher_t *c, char *deencrypted, 
						unsigned char *msg, unsigned int l){
	for(int i = 0; i < l; c->i++){
		deencrypted[i] = (char) msg[i] - (c->key)[c->i%c->key_l];
		i++;
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

