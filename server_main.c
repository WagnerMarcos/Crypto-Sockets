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

	deencrypt(&p, key, stdout, method);

    socket_shutdown(&s, SHUT_RDWR);
    socket_shutdown(&p, SHUT_RDWR);
    socket_destroy(&s);
    socket_destroy(&p);
	return 0;
}
