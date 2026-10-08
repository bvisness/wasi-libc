#include "wasi/report-error.h"

#if defined(_REENTRANT)
#include <stdatomic.h>
#endif

extern void __wasm_call_ctors(void);

#ifdef __webp2__
extern int __main_void(void);
#endif

#include "wasip3_symbol_references.h"

__attribute__((export_name("_initialize"))) void _initialize(void) {
#if defined(_REENTRANT)
  static volatile atomic_int initialized = 0;
  int expected = 0;
  if (!atomic_compare_exchange_strong(&initialized, &expected, 1)) {
    __builtin_trap();
  }
#else
  static volatile int initialized = 0;
  if (initialized != 0) {
    __builtin_trap();
  }
  initialized = 1;
#endif

  // The linker synthesizes this to call constructors.
  __wasm_call_ctors();

#ifdef __webp2__
  // The webp2 target gets a slightly modified reactor model where the main
  // function is executed automatically but nothing is torn down on exit,
  // mimicking Emscripten's EXIT_RUNTIME=0 behavior.
  //
  // This not only provides a natural way for web modules to provide
  // initialization and module side effects, but also ensures that a user-
  // provided main is never inadvertently dropped during linking, which tends
  // to break various cmake checks when reactor is the default.
  int main_status = __main_void();
  if (main_status != 0) {
    __wasilibc_webp2_report_error("main exited with nonzero status");
    __builtin_trap();
  }
#endif
}
