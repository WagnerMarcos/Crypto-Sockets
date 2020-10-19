#ifndef SOCKET__H
#define SOCKET__H
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdbool.h>

typedef struct socket_t{
    int socket;
}socket_t;

int socket_init(socket_t *self);
void socket_shutdown(socket_t *self, int channel);
int socket_destroy(socket_t *self);
int socket_bind_and_listen(socket_t *self, const char *service);
int socket_accept(socket_t *self, socket_t *accepted_socket);
int socket_connect(socket_t *self, const char *host_name, 
                    const char *service);
int socket_send(socket_t *self, const char *buffer, size_t buffer_l);
int socket_recv(socket_t *self, char *buffer, size_t buf_l, 
                size_t *bytes_recv, bool *sckt_valid);

#endif
