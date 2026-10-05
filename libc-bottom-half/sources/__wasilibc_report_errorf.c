#include <stdarg.h>
#include <stdio.h>
#include <wasi/report-error.h>
#include <wasi/report-errorf.h>

#if defined(__webp2__)
// Ensure we have well-formed UTF-8 in case of truncation. Assumes valid UTF-8
// coming in.
static void fix_truncated_utf8(char *buf, size_t len) {
  if (len == 0) {
    return;
  }
  size_t last_codepoint_start = len - 1;
  for (size_t i = 0; i < 3; i++) {
    if (((unsigned char)buf[last_codepoint_start] & 0xC0) != 0x80) {
      break;
    }
    last_codepoint_start--;
  }
  unsigned char b1 = (unsigned char)buf[last_codepoint_start];
  size_t codepoint_len;
  if (b1 >= 0xF0) {
    codepoint_len = 4;
  } else if (b1 >= 0xE0) {
    codepoint_len = 3;
  } else if (b1 >= 0xC0) {
    codepoint_len = 2;
  } else {
    codepoint_len = 1;
  }
  if (len - last_codepoint_start < codepoint_len) {
    buf[last_codepoint_start] = '\0';
  }
}
#endif

void __wasilibc_report_errorf(const char *format, ...) {
  va_list ap;
  va_start(ap, format);
#if defined(__webp2__)
  char buf[512];
  int n = vsnprintf(buf, sizeof(buf), format, ap);
  if (n >= (int)sizeof(buf)) {
    fix_truncated_utf8(buf, sizeof(buf) - 1); // subtract 1 for vnsprintf's \0
  }
  __wasilibc_report_error(buf);
#else
  vfprintf(stderr, format, ap);
  fputc('\n', stderr);
#endif
  va_end(ap);
}
