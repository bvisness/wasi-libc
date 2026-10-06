// All things file-descriptory are stubbed out on the web, since there is no
// comparable model of files and streams.

#include "sys/uio.h"
#include "wasi/report-error.h"

int __dup3(int fd, int newfd, int flags) {
    WEBP2_UNSUPPORTED("dup3");
}

int __isatty(int fd) {
    WEBP2_UNSUPPORTED("isatty");
}

off_t __lseek(int fildes, off_t offset, int whence) {
    WEBP2_UNSUPPORTED("lseek");
}

int close(int fd) {
    WEBP2_UNSUPPORTED("close");
}

int dup3(int fd, int newfd, int flags) {
    WEBP2_UNSUPPORTED("dup3");
}

int fcntl(int fildes, int cmd, ...) {
    WEBP2_UNSUPPORTED("fcntl");
}

int isatty(int fd) {
    WEBP2_UNSUPPORTED("isatty");
}

off_t lseek(int fildes, off_t offset, int whence) {
    WEBP2_UNSUPPORTED("lseek");
}

ssize_t read(int fildes, void *buf, size_t nbyte) {
    WEBP2_UNSUPPORTED("read");
}

ssize_t readv(int fildes, const struct iovec *iov, int iovcnt) {
    WEBP2_UNSUPPORTED("readv");
}

ssize_t writev(int fildes, const struct iovec *iov, int iovcnt) {
    WEBP2_UNSUPPORTED("writev");
}
