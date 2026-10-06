// There is no filesystem.

#include "__struct_stat.h"
#include <__typedef_DIR.h>
#include <wasi/libc.h>
#include "dirent.h"
#include "wasi/report-error.h"

int __wasilibc_open_nomode(const char *path, int oflag) {
    WEBP2_UNSUPPORTED("__wasilibc_open_nomode");
}

void __wasilibc_populate_preopens(void) {
    WEBP2_UNSUPPORTED("__wasilibc_populate_preopens");
}

void __wasilibc_reset_preopens(void) {
    WEBP2_UNSUPPORTED("__wasilibc_reset_preopens");
}

int closedir(DIR *dirp) {
    WEBP2_UNSUPPORTED("closedir");
}

int dirfd(DIR *dirp) {
    WEBP2_UNSUPPORTED("dirfd");
}

DIR *fdopendir(int fd) {
    WEBP2_UNSUPPORTED("fdopendir");
}

char *getcwd(char *buf, size_t size) {
    WEBP2_UNSUPPORTED("getcwd");
}

int lstat(const char *restrict path, struct stat *restrict buf) {
    WEBP2_UNSUPPORTED("lstat");
}

int open(const char *path, int oflag, ...) {
    WEBP2_UNSUPPORTED("open");
}

DIR *opendir(const char *dirname) {
    WEBP2_UNSUPPORTED("opendir");
}

ssize_t pread(int fildes, void *buf, size_t nbyte, off_t offset) {
    WEBP2_UNSUPPORTED("pread");
}

struct dirent *readdir(DIR *dirp) {
    WEBP2_UNSUPPORTED("readdir");
}

ssize_t readlink(const char *restrict path, char *restrict buf,
                 size_t bufsize) {
    WEBP2_UNSUPPORTED("readlink");
}

int stat(const char *restrict path, struct stat *restrict buf) {
    WEBP2_UNSUPPORTED("stat");
}

int utimensat(int dirfd, const char *pathname, const struct timespec times[2],
              int flags) {
    WEBP2_UNSUPPORTED("utimensat");
}
