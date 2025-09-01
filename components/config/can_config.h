#ifndef PWRINSPACE_CAN_CONFIG_H
#define PWRINSPACE_CAN_CONFIG_H

#include "can_api.h"
#include "can_commands.h"

#include "esp_log.h"
#include "esp_err.h"

esp_err_t can_config_init(void);

esp_err_t send_board_data_callback(uint8_t *data, uint8_t len);

#endif /* PWRINSPACE_CAN_CONFIG_H */