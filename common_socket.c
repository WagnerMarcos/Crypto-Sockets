#define _POSIX_C_SOURCE 200112L
#define ERROR 1
#include "common_socket.h"
int socket_init(socket_t *self){
    self->socket = socket(AF_INET, SOCK_STREAM, 0);
    int val = 1;
    int s = 0;
    s = setsockopt(self->socket, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    if (s == -1) {
      close(self->socket);
      return 1;
   }
    if (self->socket < 0){
        return ERROR;
    }
    return 0;
}

void socket_shutdown(socket_t *self, int channel){
    shutdown(self->socket, channel);
}

int socket_destroy(socket_t *self){
    close(self->socket);
    return 0;
}

int socket_bind_and_listen(socket_t *self, const char *service){
    struct addrinfo hints, *results, *rp;
    int status = 0;
    hints.ai_family = AF_INET;    
    hints.ai_socktype = SOCK_STREAM; 
    hints.ai_protocol = 0;
    hints.ai_flags = AI_PASSIVE;

    status = getaddrinfo(0, service, &hints, &results);  
    if (status != 0) { 
        return ERROR;
    }
    for (rp = results; rp != NULL; rp = rp->ai_next){
        if (bind(self->socket, rp->ai_addr, rp->ai_addrlen) == 0){
            break;               
        }
        close(self->socket);
        socket_init(self);
        if (rp == NULL) {              
            close(self->socket);
            return ERROR;
        }
    }
    freeaddrinfo(results); /* libero lista de direcciones. */
    if (listen(self->socket, 10) == -1){ 
        close(self->socket);
        return ERROR;
    }
    return 0;
}


int socket_accept(socket_t *self, socket_t *accepted_socket){
    int acepted = 0;
    acepted = accept(self->socket, NULL, NULL);
    if (acepted != -1){
        accepted_socket->socket = acepted;
    }
    if (acepted == -1){
        return ERROR;
    }
    return 0;
}

int socket_connect(socket_t *self, const char *host_name, const char *service){
    struct addrinfo hints, *result, *rp;
    int skt = 0;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;    
    hints.ai_socktype = SOCK_STREAM; 
    hints.ai_protocol = 0;
    hints.ai_flags = 0;
    skt = getaddrinfo(host_name, service, &hints, &result);      
    if (skt != 0) {
        close(self->socket);
        return ERROR;
    }
    for (rp = result; rp != NULL; rp = rp->ai_next){
        if (connect(self->socket, rp->ai_addr, rp->ai_addrlen) == 0){      
            break; 
        }  
        close(self->socket);
        socket_init(self);        
    }
    if (rp == NULL){              
        return ERROR;
    }
    freeaddrinfo(result); 
    return 0;          
}

int socket_send(socket_t *self, const char *buffer, size_t buf_l){
    size_t bytes_sent, s;
    bytes_sent = 0;
    int sckt = self->socket;
    while (bytes_sent < buf_l){
        s = 0;
        s = send(sckt, &buffer[bytes_sent], buf_l - bytes_sent, 0);
        if (s <= 0){ 
            return ERROR;
        }
        bytes_sent += s;
    }
    return 0;
}
 
int socket_recv(socket_t *self, char *buffer, size_t buf_l, size_t *bytes_recv, bool *sckt_valid){
    int r;
    *bytes_recv = 0;
    int sckt = self->socket;
    while (*bytes_recv < buf_l && *sckt_valid == true){
        r = 0;
        r = recv(sckt, &buffer[*bytes_recv], buf_l - *bytes_recv, 0);
        if (r < 0){
            *sckt_valid = false;
            return ERROR;
        }else if (r == 0){
            *sckt_valid = false;
        }else{
            *bytes_recv += r;
        }
    }
    return 0;
}