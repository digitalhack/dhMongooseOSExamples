#include "mgos.h"

static void timer_cb(void *i) {
  printf("Hello World %d...\n", (int) i);
}

enum mgos_app_init_result mgos_app_init(void) {
  int i = 0;
  mgos_set_timer(1000, true, timer_cb, (void *) i);
  return MGOS_APP_INIT_SUCCESS;
}