#include "mgos.h"

static void button_cb(int pin, void *arg) {
  LOG(LL_INFO, ("Click on pin %d, arg %p.", pin, arg));
}

static void wifi_cb(enum mgos_net_event ev,
                    const struct mgos_net_event_data *ev_data, void *arg) {
  if (ev_data->if_type != MGOS_NET_IF_TYPE_WIFI) return;
  LOG(LL_INFO, ("WiFi change event: %d, arg %p", (int) ev, arg));
}

enum mgos_app_init_result mgos_app_init(void) {
  int pin = mgos_sys_config_get_my_app_button_pin();
  mgos_gpio_set_button_handler(pin, MGOS_GPIO_PULL_UP, MGOS_GPIO_INT_EDGE_POS,
                               200, button_cb, NULL);
  mgos_net_add_event_handler(wifi_cb, NULL);
  LOG(LL_INFO, ("Button is configured on GPIO %d.", pin));
\  return MGOS_APP_INIT_SUCCESS;
}
