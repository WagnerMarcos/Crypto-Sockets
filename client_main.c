#include "client_main.h"

int main(int argc, char* argv[]){
	char method[MAX_METHOD_LENGTH] = {0};
	char key[MAX_KEY_LENGTH] = {0};

	socket_t s;

	if(parse_method(argv[3], method) != 0)
		return ERROR;
	if(parse_key(argv[4], key) != 0)
		return ERROR;

	socket_init(&s);
    socket_connect(&s, argv[1], argv[2]);
	if (strcmp(method, "cesar") == 0){
		encrypt_with_caesar(&s, key);
	}
	if (strcmp(method, "vigenere") == 0){
		encrypt_with_vigenere(&s, key);
	}
	if (strcmp(method, "rc4") == 0){
		encrypt_with_rc4(&s, key);
	}
	socket_shutdown(&s, SHUT_RDWR);
    socket_destroy(&s);
	return 0;
}
