///===-----------------------------------------------------------------------------------------===//
///
/// Copyright (c) PWr in Space. All rights reserved.
/// Created: 27.01.2024 by Szymon Rzewuski
///
///===-----------------------------------------------------------------------------------------===//
///
/// \file
/// This file contains declaration of the system console configuration, including initialization
/// and available commands for debugging/testing purposes.
///===-----------------------------------------------------------------------------------------===//

#include "board_config.h"

#include "driver/gpio.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"

#include "mcu_gpio_config.h"
#include "mcu_twai_config.h"
#include "can_config.h"
#include "console_config.h"
#include "solenoid_config.h"
#include "servo_config.h"

#define TAG "BOARD_CONFIG"

void _led_delay(uint32_t _ms) {
    vTaskDelay(_ms / portTICK_PERIOD_MS);
}

board_config_t config = {
    .board_name = "TANWA_SOLENOID", //CHANGE TO REAL BOARD NAME
    .status_led = {
        ._gpio_set_level = _mcu_gpio_set_level,
        ._delay = _led_delay,
        .gpio_num = CONFIG_GPIO_LED,
        .drive = LED_DRIVE_POSITIVE,
        .state = LED_STATE_OFF, 
    },
};

esp_err_t board_config_init(void) {

    esp_err_t err;
    
    err = mcu_gpio_init();
    
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "GPIO initialization failed");
        return err;
    }

    err = mcu_twai_init();

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "TWAI initialization failed");
        return err;
    }

    err = can_config_init();

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "CAN initialization failed");
        return err;
    }

    err = console_config_init();
    
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Console initialization failed");
        return err;
    }

    //*********** ADD HARDWARE CONFIGURATION HERE ***********//

    err = valves_init();
    if (err!=ESP_OK)
    {
        ESP_LOGE(TAG, "Valves initialization failed");
        return err;
    }

    err = init_multiple_servos();
    if(err!=ESP_OK)
    {
        ESP_LOGE(TAG, "Servo configuration failed");
        vTaskDelete(NULL);
    }
    return ESP_OK;
}