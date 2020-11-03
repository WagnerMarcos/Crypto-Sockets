#include "server_receiver.h"

void deencrypt(socket_t* p, char *key, FILE* fp, char* method){
	if (strcmp(method, "cesar") == 0){
		deencrypt_with_caesar(p, key, fp);
	}
	if (strcmp(method, "vigenere") == 0){
		deencrypt_with_vigenere(p, key, fp);
	}
	if (strcmp(method, "rc4") == 0){
		deencrypt_with_rc4(p, key, fp);
	}
}

void deencrypt_with_caesar(socket_t* s, char *key, FILE* fp){
	bool there_is_text=true;
	unsigned int buf_l = 64;
	char buffer[64];
	unsigned char encrypted_text[64];
	size_t read_bytes = 0;
	caesar_cipher_t c;
	caesar_init(&c, 5);

	while (there_is_text){
		socket_recv(s, (char*)encrypted_text, buf_l, &read_bytes, 
					&there_is_text);
		caesar_deencrypt(&c, buffer, encrypted_text, read_bytes);		
		print_data(fp, buffer, read_bytes);
	}
}

void deencrypt_with_vigenere(socket_t* s, char *key, FILE* fp){
	bool there_is_text=true;
	unsigned int buf_l = 64;
	char buffer[64];
	unsigned char encrypted_text[64];
	size_t read_bytes = 0;
	vigenere_cipher_t c;
	vigenere_init(&c, key);

	while(there_is_text){
		socket_recv(s, (char*)encrypted_text, buf_l, &read_bytes, 
					&there_is_text);
		vigenere_deencrypt(&c, buffer, encrypted_text, read_bytes);
		print_data(fp, buffer, read_bytes);
	}
}

void deencrypt_with_rc4(socket_t* s, char *key, FILE* fp){
	bool there_is_text=true;
	unsigned int buf_l = 64;
	char buffer[64];
	unsigned char encrypted_text[64];
	size_t read_bytes = 0;
	rc4_cipher_t c;
	rc4_init(&c, key);

	while(there_is_text){
		socket_recv(s, buffer, buf_l, &read_bytes, 
					&there_is_text);
		rc4_output(&c, encrypted_text, buffer, read_bytes);
		print_data(fp, (char*)encrypted_text, read_bytes);
	}
}

void print_data(FILE* fp, char* buffer,unsigned int data_size){
	fwrite(buffer, 1, data_size, fp);
}
