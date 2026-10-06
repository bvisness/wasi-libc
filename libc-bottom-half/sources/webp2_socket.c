// There are no sockets.

#include <sys/socket.h>
#include "wasi/report-error.h"

int accept(int socket, struct sockaddr *restrict address,
           socklen_t *restrict address_len) {
    WEBP2_UNSUPPORTED("accept");
}

int accept4(int socket, struct sockaddr *restrict address,
            socklen_t *restrict address_len, int flags) {
    WEBP2_UNSUPPORTED("accept4");
}

int bind(int socket, const struct sockaddr *address, socklen_t address_len) {
    WEBP2_UNSUPPORTED("bind");
}

int connect(int socket, const struct sockaddr *address,
            socklen_t address_len) {
    WEBP2_UNSUPPORTED("connect");
}

int getpeername(int socket, struct sockaddr *restrict address,
                socklen_t *restrict address_len) {
    WEBP2_UNSUPPORTED("getpeername");
}

int getsockname(int socket, struct sockaddr *restrict address,
                socklen_t *restrict address_len) {
    WEBP2_UNSUPPORTED("getsockname");
}

int getsockopt(int socket, int level, int option_name,
               void *restrict option_value, socklen_t *restrict option_len) {
    WEBP2_UNSUPPORTED("getsockopt");
}

int listen(int socket, int backlog) {
    WEBP2_UNSUPPORTED("listen");
}

ssize_t recv(int socket, void *buffer, size_t length, int flags) {
    WEBP2_UNSUPPORTED("recv");
}

ssize_t recvfrom(int socket, void *restrict buffer, size_t length, int flags,
                 struct sockaddr *restrict address,
                 socklen_t *restrict address_len) {
    WEBP2_UNSUPPORTED("recvfrom");
}

ssize_t send(int socket, const void *buffer, size_t length, int flags) {
    WEBP2_UNSUPPORTED("send");
}

ssize_t sendto(int socket, const void *message, size_t length, int flags,
               const struct sockaddr *dest_addr, socklen_t dest_len) {
    WEBP2_UNSUPPORTED("sendto");
}

int setsockopt(int socket, int level, int option_name,
               const void *option_value, socklen_t option_len) {
    WEBP2_UNSUPPORTED("setsockopt");
}

int shutdown(int socket, int how) {
    WEBP2_UNSUPPORTED("shutdown");
}

int socket(int domain, int type, int protocol) {
    WEBP2_UNSUPPORTED("socket");
}
