#include "client_main.h"

//./client <server-host> <server-port> --method=<method> --key=<key>
int main(int argc, char* argv[]){
	socket_t s;
	socket_init(&s);
    socket_connect(&s, argv[1], argv[2]);
	if (strcmp(argv[3], "--method=cesar") == 0){
		encrypt_with_caesar(&s, argv[4]+6);
	}
	if (strcmp(argv[3], "--method=vigenere") == 0){
		encrypt_with_vigenere(&s, argv[4]+6);
	}
	if (strcmp(argv[3], "--method=rc4") == 0){
		encrypt_with_rc4(&s, argv[4]+6);
	}
	socket_shutdown(&s, SHUT_RDWR);
    socket_destroy(&s);
	return 0;
}
void encrypt_with_caesar(socket_t* s, char *key){
	bool there_is_text=true;
	unsigned int buf_l = 64;
	char buffer[64];
	unsigned char encrypted_text[64];
	size_t read_bytes = 0;
	caesar_cipher_t c;
	caesar_init(&c, 5);

	while(there_is_text){
		read_bytes = reader_get_text(&there_is_text, buffer, buf_l);
		caesar_encrypt(&c, buffer, encrypted_text, read_bytes);
		socket_send(s, (char*)encrypted_text, read_bytes);
	}
}
void encrypt_with_vigenere(socket_t* s, char *key){
	bool there_is_text=true;
	unsigned int buf_l = 64;
	char buffer[64];
	unsigned char encrypted_text[64];
	size_t read_bytes = 0;
	vigenere_cipher_t c;
	vigenere_init(&c, key);

	while(there_is_text){
		read_bytes = reader_get_text(&there_is_text, buffer, buf_l);
		vigenere_encrypt(&c, buffer, encrypted_text, read_bytes);
		socket_send(s, (char*)encrypted_text, read_bytes);
	}
}
void encrypt_with_rc4(socket_t* s, char *key){
	bool there_is_text=true;
	unsigned int buf_l = 64;
	char buffer[64];
	unsigned char encrypted_text[64];
	size_t read_bytes = 0;
	rc4_cipher_t c;
	rc4_init(&c, key);
	while(there_is_text){
		read_bytes = reader_get_text(&there_is_text, buffer, buf_l);
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
