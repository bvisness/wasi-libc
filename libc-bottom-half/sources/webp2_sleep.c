// Sleeping is not a good fit for the web (until we can figure out how to
// integrate JSPI, or something.)

#include "wasi/report-error.h"
#include <common/time.h>
#include <unistd.h>

int clock_nanosleep(clockid_t clock_id, int flags, const struct timespec *rqtp,
                    struct timespec *rmtp) {
  WEBP2_UNSUPPORTED("clock_nanosleep");
}

weak_alias(clock_nanosleep, __clock_nanosleep);

int nanosleep(const struct timespec *rqtp, struct timespec *rem) {
  WEBP2_UNSUPPORTED("nanosleep");
}

unsigned int sleep(unsigned int seconds) { WEBP2_UNSUPPORTED("sleep"); }

int usleep(useconds_t useconds) { WEBP2_UNSUPPORTED("usleep"); }
