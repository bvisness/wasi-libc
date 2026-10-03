#ifndef __WASI_REPORT_ERRORF_H
#define __WASI_REPORT_ERRORF_H

#include <features.h>

hidden void __wasilibc_report_errorf(const char *format, ...)
    __attribute__((__format__(__printf__, 1, 2)));

#endif
