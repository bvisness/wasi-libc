#ifndef __WASI_REPORT_ERROR_H
#define __WASI_REPORT_ERROR_H

#include <features.h>
#include <wasi/api.h>

hidden void __wasilibc_report_error(const char* message);

#ifdef __webp2__
#define WEBP2_UNSUPPORTED(name)                                    \
  do {                                                             \
    __wasilibc_report_error(name " is not supported on the web");  \
    __builtin_trap();                                              \
  } while (0)
#endif

#endif
