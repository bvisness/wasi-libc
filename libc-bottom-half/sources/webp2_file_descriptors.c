// All things file-descriptory are stubbed out on the web, since there is no
// comparable model of files and streams.

#include "sys/uio.h"
#include "wasi/report-error.h"
#include <poll.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <unistd.h>

// unistd.h defines an `lseek` macro that would mangle the definition below.
#undef lseek

int __dup3(int fd, int newfd, int flags) { WEBP2_UNSUPPORTED("dup3"); }

int __isatty(int fd) { WEBP2_UNSUPPORTED("isatty"); }

off_t __lseek(int fildes, off_t offset, int whence) {
  WEBP2_UNSUPPORTED("lseek");
}

off_t __wasilibc_tell(int fd) { WEBP2_UNSUPPORTED("__wasilibc_tell"); }

int close(int fd) { WEBP2_UNSUPPORTED("close"); }

int dup(int fd) { WEBP2_UNSUPPORTED("dup"); }

int dup2(int fd, int newfd) { WEBP2_UNSUPPORTED("dup2"); }

int dup3(int fd, int newfd, int flags) { WEBP2_UNSUPPORTED("dup3"); }

int fcntl(int fildes, int cmd, ...) { WEBP2_UNSUPPORTED("fcntl"); }

int fstat(int fildes, struct stat *buf) { WEBP2_UNSUPPORTED("fstat"); }

int ioctl(int fildes, int request, ...) { WEBP2_UNSUPPORTED("ioctl"); }

int isatty(int fd) { WEBP2_UNSUPPORTED("isatty"); }

off_t lseek(int fildes, off_t offset, int whence) {
  WEBP2_UNSUPPORTED("lseek");
}

int pipe(int fd[2]) { WEBP2_UNSUPPORTED("pipe"); }

int pipe2(int fd[2], int flags) { WEBP2_UNSUPPORTED("pipe2"); }

int poll(struct pollfd *fds, nfds_t nfds, int timeout) {
  WEBP2_UNSUPPORTED("poll");
}

int ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *timeout,
          const sigset_t *sigmask) {
  WEBP2_UNSUPPORTED("ppoll");
}

int pselect(int nfds, fd_set *restrict readfds, fd_set *restrict writefds,
            fd_set *restrict errorfds, const struct timespec *restrict timeout,
            const sigset_t *restrict sigmask) {
  WEBP2_UNSUPPORTED("pselect");
}

ssize_t read(int fildes, void *buf, size_t nbyte) { WEBP2_UNSUPPORTED("read"); }

ssize_t readv(int fildes, const struct iovec *iov, int iovcnt) {
  WEBP2_UNSUPPORTED("readv");
}

int select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds,
           fd_set *restrict errorfds, struct timeval *restrict timeout) {
  WEBP2_UNSUPPORTED("select");
}

ssize_t write(int fildes, const void *buf, size_t nbyte) {
  WEBP2_UNSUPPORTED("write");
}

ssize_t writev(int fildes, const struct iovec *iov, int iovcnt) {
  WEBP2_UNSUPPORTED("writev");
}
