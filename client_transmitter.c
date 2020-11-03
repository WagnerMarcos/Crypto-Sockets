#include "client_transmitter.h"

void encrypt(socket_t* s, char *key, char* method){
	if (strcmp(method, "cesar") == 0){
		encrypt_with_caesar(s, key);
	}
	if (strcmp(method, "vigenere") == 0){
		encrypt_with_vigenere(s, key);
	}
	if (strcmp(method, "rc4") == 0){
		encrypt_with_rc4(s, key);
	}
}

void encrypt_with_caesar(socket_t* s, char *key){
	bool there_is_text=true;
	unsigned int buf_l = 64;
	char buffer[64];
	unsigned char encrypted_text[64];
	caesar_cipher_t c;
	caesar_init(&c, 5);

	while (there_is_text){
		size_t read_bytes = reader_get_text(&there_is_text, buffer, buf_l);
		caesar_encrypt(&c, buffer, encrypted_text, read_bytes);
		socket_send(s, (char*)encrypted_text, read_bytes);
	}
}
void encrypt_with_vigenere(socket_t* s, char *key){
	bool there_is_text=true;
	unsigned int buf_l = 64;
	char buffer[64];
	unsigned char encrypted_text[64];
	vigenere_cipher_t c;
	vigenere_init(&c, key);

	while (there_is_text){
		size_t read_bytes = reader_get_text(&there_is_text, buffer, buf_l);
		vigenere_encrypt(&c, buffer, encrypted_text, read_bytes);
		socket_send(s, (char*)encrypted_text, read_bytes);
	}
}
void encrypt_with_rc4(socket_t* s, char *key){
	bool there_is_text=true;
	unsigned int buf_l = 64;
	char buffer[64];
	unsigned char encrypted_text[64];
	rc4_cipher_t c;
	rc4_init(&c, key);

	while (there_is_text){
		size_t read_bytes = reader_get_text(&there_is_text, buffer, buf_l);
		rc4_output(&c, encrypted_text, buffer, read_bytes);
		socket_send(s, (char*)encrypted_text, read_bytes);
	}
}
size_t reader_get_text(bool *there_is_text, char buffer[], 
						size_t buffer_size){
	size_t result = 0;
	if((result = fread(buffer, 1, buffer_size, stdin)) != buffer_size)
		if(feof(stdin))	
			*there_is_text = false;
	return result;
}
