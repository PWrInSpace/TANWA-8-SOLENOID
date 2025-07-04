#include "can_config.h"
#include "can_api.h"
#include "can_commands.h"

#include "esp_log.h"
#include "esp_err.h"

#include "driver/twai.h"
#include "Solenoid.h"

#define TAG "CAN_CONFIG"

esp_err_t new_command_handler(uint8_t *data, uint8_t length) {
    // Example: just print received data
    printf("New command received with length %d\n", length);
    for (int i = 0; i < length; ++i) {
        printf("Byte %d: %02X\n", i, data[i]);
    }

    // Return success
    return ESP_OK;
}

esp_err_t sol_open_callback(uint8_t *data, uint8_t length) {
    if (!data || length == 0 || *data >= NUM_OF_SOLENOIDS) {
        return ESP_ERR_INVALID_ARG;
    }

    return set_valve_state((ValveName)(*data), VALVE_ON);
}

esp_err_t sol_close_callback(uint8_t *data, uint8_t length) {
    if (!data || length == 0 || *data >= NUM_OF_SOLENOIDS) {
        return ESP_ERR_INVALID_ARG;
    }

    return set_valve_state((ValveName)(*data), VALVE_OFF);
}

esp_err_t servo_1_callbak(uint8_t *data, uint8_t length) {
    if (!data || length == 0) {
        return ESP_ERR_INVALID_ARG;
    }

    return ESP_OK;
}

esp_err_t servo_2_callbak(uint8_t *data, uint8_t length) {
    if (!data || length == 0) {
        return ESP_ERR_INVALID_ARG;
    }
return ESP_OK;
}

can_command_t can_commands[] = {
    // Example command registration
    {CAN_TEMPLATE_MESSAGE_ID, new_command_handler},
    {CAN_OPEN_SOL_ID , sol_open_callback},
    {CAN_CLOSE_SOL_ID , sol_close_callback},
    {CAN_SERVO_1 , servo_1_callbak},
    {CAN_SERVO_2 , servo_2_callbak}
};

esp_err_t can_config_init(void) {
    esp_err_t err;

    // Register CAN commands
    err = can_register_commands(can_commands, sizeof(can_commands) / sizeof(can_commands[0]));
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "CAN command registration failed");
        return err;
    }

    // Initialize CAN driver
    err = can_task_init();
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "CAN driver initialization failed");
        return err;
    }

    // Start CAN driver
    err = can_start();
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "CAN driver start failed");
        return err;
    }

    return ESP_OK;
}