#include "common_caesar.h"

void caesar_encrypt(caesar_cipher_t *c, char *msg, 
					unsigned char *encrypted, size_t l){
	int i = 0;

	for(i = 0; i < l; i++){
		encrypted[i] = (unsigned char) msg[i] + (c->key);
	}
}

void caesar_deencrypt(caesar_cipher_t *c, char *msg, 
						unsigned char *encr_txt, size_t l){
	int i = 0;

	for(i = 0; i < l; i++){
		msg[i] = (encr_txt[i] - (c->key)) % 255;
	}
}

void caesar_init(caesar_cipher_t *c, int key){
	c->key = key;
}
