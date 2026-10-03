#ifndef __WASI_REPORT_ERROR_H
#define __WASI_REPORT_ERROR_H

#include <features.h>

hidden void __wasilibc_report_error(const char* message);

#endif
