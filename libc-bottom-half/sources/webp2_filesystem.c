// There is no filesystem.

#include "__struct_stat.h"
#include <__typedef_DIR.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <utime.h>
#include <wasi/libc.h>
#include "dirent.h"
#include "wasi/report-error.h"

int __wasilibc_access(const char *pathname, int mode, int flags) {
    WEBP2_UNSUPPORTED("__wasilibc_access");
}

int __wasilibc_link(const char *oldpath, const char *newpath, int flags) {
    WEBP2_UNSUPPORTED("__wasilibc_link");
}

int __wasilibc_link_newat(const char *oldpath, int newdirfd,
                          const char *newpath, int flags) {
    WEBP2_UNSUPPORTED("__wasilibc_link_newat");
}

int __wasilibc_link_oldat(int olddirfd, const char *oldpath,
                          const char *newpath, int flags) {
    WEBP2_UNSUPPORTED("__wasilibc_link_oldat");
}

int __wasilibc_open_nomode(const char *path, int oflag) {
    WEBP2_UNSUPPORTED("__wasilibc_open_nomode");
}

void __wasilibc_populate_preopens(void) {
    WEBP2_UNSUPPORTED("__wasilibc_populate_preopens");
}

int __wasilibc_rename_newat(const char *oldpath, int newdirfd,
                            const char *newpath) {
    WEBP2_UNSUPPORTED("__wasilibc_rename_newat");
}

int __wasilibc_rename_oldat(int olddirfd, const char *oldpath,
                            const char *newpath) {
    WEBP2_UNSUPPORTED("__wasilibc_rename_oldat");
}

void __wasilibc_reset_preopens(void) {
    WEBP2_UNSUPPORTED("__wasilibc_reset_preopens");
}

int __wasilibc_rmdirat(int fd, const char *path) {
    WEBP2_UNSUPPORTED("__wasilibc_rmdirat");
}

int __wasilibc_stat(const char *restrict pathname, struct stat *restrict statbuf,
                    int flags) {
    WEBP2_UNSUPPORTED("__wasilibc_stat");
}

int __wasilibc_unlinkat(int fd, const char *path) {
    WEBP2_UNSUPPORTED("__wasilibc_unlinkat");
}

int __wasilibc_utimens(const char *pathname, const struct timespec times[2],
                       int flags) {
    WEBP2_UNSUPPORTED("__wasilibc_utimens");
}

int access(const char *path, int amode) {
    WEBP2_UNSUPPORTED("access");
}

int chdir(const char *path) {
    WEBP2_UNSUPPORTED("chdir");
}

int chmod(const char *path, mode_t mode) {
    WEBP2_UNSUPPORTED("chmod");
}

int closedir(DIR *dirp) {
    WEBP2_UNSUPPORTED("closedir");
}

int dirfd(DIR *dirp) {
    WEBP2_UNSUPPORTED("dirfd");
}

int faccessat(int fd, const char *path, int amode, int flag) {
    WEBP2_UNSUPPORTED("faccessat");
}

int fchmod(int fildes, mode_t mode) {
    WEBP2_UNSUPPORTED("fchmod");
}

int fchmodat(int fd, const char *path, mode_t mode, int flag) {
    WEBP2_UNSUPPORTED("fchmodat");
}

int fdatasync(int fildes) {
    WEBP2_UNSUPPORTED("fdatasync");
}

int fdclosedir(DIR *dirp) {
    WEBP2_UNSUPPORTED("fdclosedir");
}

DIR *fdopendir(int fd) {
    WEBP2_UNSUPPORTED("fdopendir");
}

int fstatat(int fd, const char *restrict path, struct stat *restrict buf,
            int flag) {
    WEBP2_UNSUPPORTED("fstatat");
}

int fstatvfs(int fildes, struct statvfs *buf) {
    WEBP2_UNSUPPORTED("fstatvfs");
}

int fsync(int fildes) {
    WEBP2_UNSUPPORTED("fsync");
}

int ftruncate(int fildes, off_t length) {
    WEBP2_UNSUPPORTED("ftruncate");
}

int futimens(int fd, const struct timespec times[2]) {
    WEBP2_UNSUPPORTED("futimens");
}

char *getcwd(char *buf, size_t size) {
    WEBP2_UNSUPPORTED("getcwd");
}

int link(const char *path1, const char *path2) {
    WEBP2_UNSUPPORTED("link");
}

int linkat(int fd1, const char *path1, int fd2, const char *path2, int flag) {
    WEBP2_UNSUPPORTED("linkat");
}

int lstat(const char *restrict path, struct stat *restrict buf) {
    WEBP2_UNSUPPORTED("lstat");
}

int mkdir(const char *path, mode_t mode) {
    WEBP2_UNSUPPORTED("mkdir");
}

int mkdirat(int fd, const char *path, mode_t mode) {
    WEBP2_UNSUPPORTED("mkdirat");
}

int open(const char *path, int oflag, ...) {
    WEBP2_UNSUPPORTED("open");
}

int openat(int fd, const char *path, int oflag, ...) {
    WEBP2_UNSUPPORTED("openat");
}

DIR *opendir(const char *dirname) {
    WEBP2_UNSUPPORTED("opendir");
}

DIR *opendirat(int dir, const char *dirname) {
    WEBP2_UNSUPPORTED("opendirat");
}

int posix_fadvise(int fd, off_t offset, off_t len, int advice) {
    WEBP2_UNSUPPORTED("posix_fadvise");
}

int posix_fallocate(int fd, off_t offset, off_t len) {
    WEBP2_UNSUPPORTED("posix_fallocate");
}

ssize_t pread(int fildes, void *buf, size_t nbyte, off_t offset) {
    WEBP2_UNSUPPORTED("pread");
}

ssize_t preadv(int fildes, const struct iovec *iov, int iovcnt, off_t offset) {
    WEBP2_UNSUPPORTED("preadv");
}

ssize_t pwrite(int fildes, const void *buf, size_t nbyte, off_t offset) {
    WEBP2_UNSUPPORTED("pwrite");
}

ssize_t pwritev(int fildes, const struct iovec *iov, int iovcnt,
                off_t offset) {
    WEBP2_UNSUPPORTED("pwritev");
}

struct dirent *readdir(DIR *dirp) {
    WEBP2_UNSUPPORTED("readdir");
}

ssize_t readlink(const char *restrict path, char *restrict buf,
                 size_t bufsize) {
    WEBP2_UNSUPPORTED("readlink");
}

ssize_t readlinkat(int fd, const char *restrict path, char *restrict buf,
                   size_t bufsize) {
    WEBP2_UNSUPPORTED("readlinkat");
}

int remove(const char *path) {
    WEBP2_UNSUPPORTED("remove");
}

int rename(const char *old, const char *new) {
    WEBP2_UNSUPPORTED("rename");
}

int renameat(int oldfd, const char *old, int newfd, const char *new) {
    WEBP2_UNSUPPORTED("renameat");
}

void rewinddir(DIR *dirp) {
    WEBP2_UNSUPPORTED("rewinddir");
}

int rmdir(const char *path) {
    WEBP2_UNSUPPORTED("rmdir");
}

int scandir(const char *dir, struct dirent ***namelist,
            int (*sel)(const struct dirent *),
            int (*compar)(const struct dirent **, const struct dirent **)) {
    WEBP2_UNSUPPORTED("scandir");
}

int scandirat(int dirfd, const char *dir, struct dirent ***namelist,
              int (*sel)(const struct dirent *),
              int (*compar)(const struct dirent **, const struct dirent **)) {
    WEBP2_UNSUPPORTED("scandirat");
}

void seekdir(DIR *dirp, long loc) {
    WEBP2_UNSUPPORTED("seekdir");
}

int stat(const char *restrict path, struct stat *restrict buf) {
    WEBP2_UNSUPPORTED("stat");
}

int statvfs(const char *restrict path, struct statvfs *restrict buf) {
    WEBP2_UNSUPPORTED("statvfs");
}

int symlink(const char *path1, const char *path2) {
    WEBP2_UNSUPPORTED("symlink");
}

int symlinkat(const char *path1, int fd, const char *path2) {
    WEBP2_UNSUPPORTED("symlinkat");
}

long telldir(DIR *dirp) {
    WEBP2_UNSUPPORTED("telldir");
}

int truncate(const char *path, off_t length) {
    WEBP2_UNSUPPORTED("truncate");
}

int unlink(const char *path) {
    WEBP2_UNSUPPORTED("unlink");
}

int unlinkat(int fd, const char *path, int flag) {
    WEBP2_UNSUPPORTED("unlinkat");
}

int utime(const char *path, const struct utimbuf *times) {
    WEBP2_UNSUPPORTED("utime");
}

int utimensat(int dirfd, const char *pathname, const struct timespec times[2],
              int flags) {
    WEBP2_UNSUPPORTED("utimensat");
}

int utimes(const char *path, const struct timeval times[2]) {
    WEBP2_UNSUPPORTED("utimes");
}
