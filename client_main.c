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

	encrypt(&s, key, method);

	socket_shutdown(&s, SHUT_RDWR);
    socket_destroy(&s);
	return 0;
}
