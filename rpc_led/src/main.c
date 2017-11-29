#include "mgos.h"
#include "mgos_app.h"
#include "mgos_wifi.h"
#include "mgos_rpc.h"
#include "mgos_gpio.h"
#include "frozen/frozen.h"

int led = 2;

static void cb (struct mg_rpc_request_info *ri, void *cb_arg,
                struct mg_rpc_frame_info *fi, struct mg_str args) {
  int state;
  if(json_scanf(args.p, args.len, ri->args_fmt, &state) == 1) {
    mgos_gpio_write(led, state);
  }
  mg_rpc_send_responsef(ri, "true");
  (void) cb_arg;
  (void) fi;
}

enum mgos_app_init_result mgos_app_init(void) {
  struct mg_rpc *c = mgos_rpc_get_global();
  mgos_gpio_set_mode(led, MGOS_GPIO_MODE_OUTPUT);
  mg_rpc_add_handler(c, "Control", "{state: %d}", cb, NULL);
  
  return MGOS_APP_INIT_SUCCESS;
}
