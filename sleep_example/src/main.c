#include "mgos.h"
#include "user_interface.h"

enum mgos_app_init_result mgos_app_init(void) {
  
  printf("Going to sleep...\n");
  system_deep_sleep(0);
  printf("Waking up...\n");
  return MGOS_APP_INIT_SUCCESS;
}
