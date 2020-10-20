#include "server_main.h"

int main(int argc, char* argv[]){
	char method[MAX_METHOD_LENGTH] = {0};
	char key[MAX_KEY_LENGTH] = {0};
	socket_t s;
    socket_t p;

	if(parse_method(argv[2], method) != 0)
		return ERROR;
	if(parse_key(argv[3], key) != 0)
		return ERROR;

	socket_init(&s);
	socket_bind_and_listen(&s, argv[1]);
    socket_accept(&s, &p); 

	if (strcmp(method, "cesar") == 0){
		deencrypt_with_caesar(&p, key, stdout);
	}
	if (strcmp(method, "vigenere") == 0){
		deencrypt_with_vigenere(&p, key, stdout);
	}
	if (strcmp(method, "rc4") == 0){
		deencrypt_with_rc4(&p, key, stdout);
	}
    socket_shutdown(&s, SHUT_RDWR);
    socket_shutdown(&p, SHUT_RDWR);
    socket_destroy(&s);
    socket_destroy(&p);
	return 0;
}

int parse_method(char* arg, char* method){
	int i;
	int j = 0;
	bool equals = true;
	for(i = 0; i < METHOD_ARG_LENGTH && equals; i++){
		if(arg[i] != METHOD_ARG[i]){
			return 1;
		}
	}

	while (arg[i] != '\0' && j < MAX_METHOD_LENGTH){
		method[j] = arg[i];
		i++;
		j++;
	}
	return 0;
}

int parse_key(char *arg, char *key){
	int i;
	int j = 0;
	bool equals = true;
	for(i = 0; i < KEY_ARG_LENGTH && equals; i++){
		if(arg[i] != KEY_ARG[i]){
			return 1;
		}
	}

	while (arg[i] != '\0' && j < MAX_KEY_LENGTH){
		key[j] = arg[i];
		i++;
		j++;
	}
	return 0;
}
