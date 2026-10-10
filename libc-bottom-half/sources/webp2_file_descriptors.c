// File descriptors are mostly stubbed out on the web, since there is no
// comparable model of files and streams. However, stdout and stderr are
// supported by routing to console.log, and stdin is supported by immediately
// returning EOF.

#include "features.h"
#include "sys/uio.h"
#include "wasi/report-error.h"
#include <__errno_values.h>
#include <errno.h>
#include <limits.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wasi/__generated_webp2.h>

// unistd.h defines an `lseek` macro that would mangle the definition below.
#undef lseek

// ============================================================================
// Basic stdio implementation

#define LINE_BUF_SIZE 4096

typedef struct line_buffer_t {
  size_t len;
  uint8_t buf[LINE_BUF_SIZE];
} line_buffer_t;

static line_buffer_t line_buffers[2];

static bool fd_closed[3];

static void flush_line_buffer(line_buffer_t* buf) {
  webp2_string_t out = (webp2_string_t){ .ptr = buf->buf, .len = buf->len };
  webp2_console_log(&out);
  buf->len = 0;
}

static bool is_readable(int fd) {
  return fd == STDIN_FILENO;
}

static bool is_writable(int fd) {
  return fd == STDOUT_FILENO || fd == STDERR_FILENO;
}

static bool iovecs_ok(const struct iovec *iov, int iovcnt, size_t *total_size) {
  // Check if the total size of all iovecs would overflow an ssize_t
  size_t _total_size = 0;
  if (total_size) {
    *total_size = 0;
  }
  for (int i = 0; i < iovcnt; i++) {
    const struct iovec* v = &iov[i];
    if (v->iov_len > SSIZE_MAX || _total_size > SSIZE_MAX - v->iov_len) {
      return false;
    }
    _total_size += v->iov_len;
  }
  if (total_size) {
    *total_size = _total_size;
  }
  return true;
}

int __isatty(int fd) {
  if (fd < STDIN_FILENO || STDERR_FILENO < fd || fd_closed[fd]) {
    errno = EBADF;
    return 0;
  }
  errno = ENOTTY;
  return 0;
}
weak_alias(__isatty, isatty);

int close(int fd) {
  if (fd < STDIN_FILENO || STDERR_FILENO < fd || fd_closed[fd]) {
    errno = EBADF;
    return -1;
  }
  fd_closed[fd] = true;
  if (is_writable(fd)) {
    line_buffer_t *buf = &line_buffers[fd-1];
    if (buf->len > 0) {
      flush_line_buffer(buf);
    }
  }
  return 0;
}

ssize_t read(int fildes, void *buf, size_t nbyte) {
  if (nbyte > SSIZE_MAX) {
    errno = EINVAL;
    return -1;
  }
  if (!is_readable(fildes) || fd_closed[fildes]) {
    errno = EBADF;
    return -1;
  }
  return 0; // immediate EOF;
}

ssize_t readv(int fildes, const struct iovec *iov, int iovcnt) {
  if (iovcnt < 0 || IOV_MAX < iovcnt) {
    errno = EINVAL;
    return -1;
  }
  if (!iovecs_ok(iov, iovcnt, NULL)) {
    errno = EINVAL;
    return -1;
  }
  if (!is_readable(fildes) || fd_closed[fildes]) {
    errno = EBADF;
    return -1;
  }

  size_t bytes_read = 0;
  for (int i = 0; i < iovcnt; i++) {
    const struct iovec *v = &iov[i];
    ssize_t res = read(fildes, v->iov_base, v->iov_len);
    if (res < 0) {
      // errno already set
      return res;
    }
    bytes_read += res;
    if ((size_t)res < v->iov_len) {
      break;
    }
  }
  return bytes_read;
}

ssize_t write(int fildes, const void *buf, size_t nbyte) {
  if (nbyte > SSIZE_MAX) {
    errno = EINVAL;
    return -1;
  }
  if (!is_writable(fildes) || fd_closed[fildes]) {
    errno = EBADF;
    return -1;
  }

  line_buffer_t* line_buffer = &line_buffers[fildes-1];
  for (size_t i = 0; i < nbyte; i++) {
    // TODO(webp2): UTF-8
    uint8_t c = ((uint8_t*)buf)[i];
    // TODO(webp2): Handle \r
    if (c == '\n' || line_buffer->len >= LINE_BUF_SIZE) {
      flush_line_buffer(line_buffer);
    }
    if (c != '\n') {
      line_buffer->buf[line_buffer->len] = c;
      line_buffer->len++;
    }
  }
  return nbyte;
}

ssize_t writev(int fildes, const struct iovec *iov, int iovcnt) {
  if (iovcnt < 0 || IOV_MAX < iovcnt) {
    errno = EINVAL;
    return -1;
  }
  if (!is_writable(fildes) || fd_closed[fildes]) {
    errno = EBADF;
    return -1;
  }

  size_t total_size;
  if (!iovecs_ok(iov, iovcnt, &total_size)) {
    errno = EINVAL;
    return -1;
  }
  for (int i = 0; i < iovcnt; i++) {
    const struct iovec *v = &iov[i];
    int res = write(fildes, v->iov_base, v->iov_len);
    if (res < 0) {
      // errno already set
      return res;
    }
  }
  return total_size;
}

// ============================================================================
// Stubs

int __dup3(int fd, int newfd, int flags) { WEBP2_UNSUPPORTED("__dup3"); }

off_t __lseek(int fildes, off_t offset, int whence) {
  WEBP2_UNSUPPORTED("__lseek");
}

off_t __wasilibc_tell(int fd) { WEBP2_UNSUPPORTED("__wasilibc_tell"); }

int dup(int fd) { WEBP2_UNSUPPORTED("dup"); }

int dup2(int fd, int newfd) { WEBP2_UNSUPPORTED("dup2"); }

int dup3(int fd, int newfd, int flags) { WEBP2_UNSUPPORTED("dup3"); }

int fcntl(int fildes, int cmd, ...) { WEBP2_UNSUPPORTED("fcntl"); }

int fstat(int fildes, struct stat *buf) { WEBP2_UNSUPPORTED("fstat"); }

int ioctl(int fildes, int request, ...) { WEBP2_UNSUPPORTED("ioctl"); }

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

int select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds,
           fd_set *restrict errorfds, struct timeval *restrict timeout) {
  WEBP2_UNSUPPORTED("select");
}
