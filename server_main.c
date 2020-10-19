#include "server_main.h"
//./server <server-port> --method=<method> --key=<key>
int main(int argc, char* argv[]){
	socket_t s;
    socket_t p;
	socket_init(&s);
	socket_bind_and_listen(&s, argv[1]);
    socket_accept(&s, &p); 
	FILE* output = fopen("output", "wb");
	if (strcmp(argv[2], "--method=cesar") == 0){
		deencrypt_with_caesar(&p, argv[3]+6, output);
	}
	if (strcmp(argv[2], "--method=vigenere") == 0){
		deencrypt_with_vigenere(&p, argv[3]+6, output);
	}
	if (strcmp(argv[2], "--method=rc4") == 0){
		deencrypt_with_rc4(&p, argv[3]+6, output);
	}
	fclose(output);
    socket_shutdown(&s, SHUT_RDWR);
    socket_shutdown(&p, SHUT_RDWR);
    socket_destroy(&s);
    socket_destroy(&p);
	return 0;
}
    
void deencrypt_with_caesar(socket_t* s, char *key, FILE* fp){
	bool there_is_text=true;
	unsigned int buf_l = 64;
	char buffer[buf_l];
	unsigned char encrypted_text[buf_l];
	size_t read_bytes = 0;
	caesar_cipher_t c;
	caesar_init(&c, 5);

	while(there_is_text){
		read_bytes = 0;
		socket_recv(s, (char*)encrypted_text, buf_l, &read_bytes, &there_is_text);
		caesar_deencrypt(&c, buffer, encrypted_text, read_bytes);		
		print_data(fp, buffer, read_bytes);
	}
}
void deencrypt_with_vigenere(socket_t* s, char *key, FILE* fp){
	bool there_is_text=true;
	unsigned int buf_l = 64;
	char buffer[buf_l];
	unsigned char encrypted_text[buf_l];
	size_t read_bytes = 0;
	vigenere_cipher_t c;
	vigenere_init(&c, key);

	while(there_is_text){
		read_bytes = 0;
		socket_recv(s, (char*)encrypted_text, buf_l, &read_bytes, &there_is_text);
		vigenere_deencrypt(&c, buffer, encrypted_text, read_bytes);
		print_data(fp, buffer, read_bytes);
	}
}
void deencrypt_with_rc4(socket_t* s, char *key, FILE* fp){
	bool there_is_text=true;
	unsigned int buf_l = 64;
	char buffer[buf_l];
	unsigned char encrypted_text[buf_l];
	size_t read_bytes = 0;
	rc4_cipher_t c;
	rc4_init(&c, key);
	int i = 0;
	while(there_is_text && i<10){
		read_bytes = 0;
		socket_recv(s, buffer, buf_l, &read_bytes, &there_is_text);
		rc4_output(&c, encrypted_text, buffer, read_bytes);
		print_data(fp, (char*)encrypted_text, read_bytes);
		i++;
	}
}

void print_data(FILE* fp, char* buffer,unsigned int data_size){
	fwrite(buffer, 1, data_size, fp);
}