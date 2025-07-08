#include "can_config.h"
#include "can_api.h"
#include "can_commands.h"

#include "esp_log.h"
#include "esp_err.h"

#include "driver/twai.h"
#include "Solenoid.h"
#include "solenoid_config.h"
#include "servo_config.h"

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

esp_err_t servo_open_callbak(uint8_t *data, uint8_t length) {
    if (!data || length == 0) {
        return ESP_ERR_INVALID_ARG;
    }
    ServoId_t servo = data[0];
    uint16_t time_ms = (uint16_t)(data[1] | (data[2] << 8));
    return open_servo(servo, time_ms);
}

esp_err_t servo_close_callbak(uint8_t *data, uint8_t length) {
    if (!data || length == 0) {
        return ESP_ERR_INVALID_ARG;
    }
    ServoId_t servo = data[0];
    return close_servo(servo);
}

can_command_t can_commands[] = {
    // Example command registration
    {CAN_TEMPLATE_MESSAGE_ID, new_command_handler},
    {CAN_OPEN_SOL_ID , sol_open_callback},
    {CAN_CLOSE_SOL_ID , sol_close_callback},
    {CAN_OPEN_SERVO_ID , servo_open_callbak},
    {CAN_CLOSE_SERVO_ID , servo_close_callbak}
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