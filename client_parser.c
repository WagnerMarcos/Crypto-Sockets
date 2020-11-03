#include "client_parser.h"

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
