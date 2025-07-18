#include "can_config.h"
#include "can_api.h"
#include "can_commands.h"

#include "esp_log.h"
#include "esp_err.h"
#include "esp_timer.h"

#include "driver/twai.h"
#include "Solenoid.h"
#include "solenoid_config.h"
#include "servo_config.h"
#include "BoardData.h"
#include <string.h>

#define TAG "CAN_CONFIG"

esp_err_t new_command_handler(uint8_t *data, uint8_t length) {
    // Example: just print received data
    printf("New command received with length %d\n", length);
    for (int i = 0; i < length; ++i) {
        printf("Byte %d: %02X\n", i, data[i]);
    }
    return ESP_OK;
}

void timer_callback(void *arg) {
    ValveName *valve_name = (ValveName *)arg;
    if (valve_name == NULL) {
        ESP_LOGE(TAG, "Timer callback received NULL argument");
        return;
    }
    // Close the solenoid after the timeout
    esp_err_t err = set_valve_state(*valve_name, VALVE_OFF);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to close solenoid %d: %s", *valve_name, esp_err_to_name(err));
    } else {
        ESP_LOGI(TAG, "Solenoid %d closed after timeout", *valve_name);
    }

    free(valve_name); // Free the allocated memory for the valve name
}


esp_err_t sol_open_callback(uint8_t *data, uint8_t length) {
    ESP_LOGI(TAG, "Solenoid open command received");
    if (!data || length == 0 || *data >= NUM_OF_SOLENOIDS) {
        return ESP_ERR_INVALID_ARG;
    }

    if(length == 1){
        return set_valve_state((ValveName)(*data), VALVE_ON);
    }
    else if(length == 3) {
        ValveName valve_name = (ValveName)(*data);
        uint16_t open_time_ms = (uint16_t)(data[1] | (data[2] << 8));
       // Przygotuj argument dla timera
        ValveName *timer_arg = malloc(sizeof(ValveName));
        if (!timer_arg) {
            return ESP_ERR_NO_MEM;
        }
        *timer_arg = valve_name;

        // Utwórz i uruchom jednorazowy timer
        const esp_timer_create_args_t timer_args = {
            .callback = timer_callback,
            .arg = timer_arg,
            .name = "sol_timer"
        };
        esp_timer_handle_t timer_handle;
        if (esp_timer_create(&timer_args, &timer_handle) != ESP_OK) {
            free(timer_arg);
            ESP_LOGE(TAG, "Failed to create timer");
            return ESP_ERR_NO_MEM;
        }
        esp_timer_start_once(timer_handle, open_time_ms * 1000); // czas w mikrosekundach

        return ESP_OK;
    } else {
        ESP_LOGE(TAG, "Invalid command length for solenoid open");
        return ESP_ERR_INVALID_ARG;
    }
}

esp_err_t sol_close_callback(uint8_t *data, uint8_t length) {
    ESP_LOGI(TAG, "Solenoid close command received");
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

esp_err_t reset_callback(uint8_t *data, uint8_t length) {
    esp_restart();
    return ESP_OK;
}

esp_err_t parse_bool_to_uint8_t(const bool *states, uint8_t num_states, uint8_t *result)
{
    if (states == NULL || result == NULL || num_states > 8) {
        ESP_LOGE(TAG, "Invalid input or too many states for uint8_t");
        return ESP_ERR_INVALID_ARG;
    }

    *result = 0; // Initialize result
    for (int i = 0; i < num_states; i++) {
        if (states[i]) {
            *result |= (1 << i); // Set i-th bit if state is true
        }
    }
    return ESP_OK;
}

// Modified callback function to match can_command_t handler signature
esp_err_t send_board_data_callback(uint8_t *data, uint8_t len)
{
    //printf("SEND BOARD DATA\n");
    twai_message_t tx_msg = {
        .identifier = CAN_SEND_BOARD_DATA,
        .data_length_code = 8,
        .data = {0},
        .extd = 1
    };

    uint8_t sol_status = 0;
    uint8_t servo_status = 0;
    esp_err_t ret = ESP_OK;

    if (xSemaphoreTake(BoardDataSemaphore, pdMS_TO_TICKS(1000)) == pdTRUE) 
    {
        // Parse solenoid states
        bool solenoid_state_values[NUM_OF_SOLENOIDS];
        for (int i = 0; i < NUM_OF_SOLENOIDS; i++) {
            solenoid_state_values[i] = (BoardData.solenoid_states[i] != VALVE_OFF); // Convert ValveState to bool
        }
        ret = parse_bool_to_uint8_t(solenoid_state_values, NUM_OF_SOLENOIDS, &sol_status);
        if (ret != ESP_OK) {
            xSemaphoreGive(BoardDataSemaphore);
            ESP_LOGE(TAG, "Failed to parse solenoid states");
            return ret;
        }

        //ESP_LOGI(TAG, "Solenoid status: %02X", sol_status);

        // Parse servo states
        bool servo_state_values[SERVO_COUNT];
        for (int i = 0; i < SERVO_COUNT; i++) {
            servo_state_values[i] = (BoardData.servo_states[i].state != SERVO_CLOSED); // Convert Servo_state_t to bool
        }
        ret = parse_bool_to_uint8_t(servo_state_values, SERVO_COUNT, &servo_status);
        if (ret != ESP_OK) {
            xSemaphoreGive(BoardDataSemaphore);
            ESP_LOGE(TAG, "Failed to parse servo states");
            return ret;
        }

        //ESP_LOGI(TAG, "Servo status: %02X", servo_status);

        tx_msg.data[0] = sol_status;
        tx_msg.data[1] = servo_status;
        tx_msg.data[2] = BoardData.servo_states[0].angle;
        tx_msg.data[3] = BoardData.servo_states[1].angle;
        // Use temperature data from BoardData
        tx_msg.data[6] = 1;
        tx_msg.data[7] = 1;
        xSemaphoreGive(BoardDataSemaphore);
    }
    else 
    {
        ESP_LOGE(TAG, "Failed to take BoardDataSemaphore");
        return ESP_ERR_TIMEOUT;
    }

    ret = twai_transmit(&tx_msg, pdMS_TO_TICKS(100));
    // Transmit CAN message
    if (ret != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to transmit CAN message %s", esp_err_to_name(ret));
        return ESP_FAIL;
    }

    return ESP_OK;
}

esp_err_t send_status_callback(uint8_t *data, uint8_t length) {
    //printf("SEND BOARD STATUS\n");
    twai_message_t tx_msg;
    tx_msg.identifier = CAN_SEND_STATUS;

    uint8_t temperature_celsius[1] = {55};
    uint8_t data_send[8] = {0};

    // Insert the int16_t value into the data array starting at index x

    tx_msg.data_length_code = 8;
    tx_msg.extd = 1;
    data_send[0] = temperature_celsius[0];
    data_send[1] = temperature_celsius[0];

    //ESP_LOGI(TAG, "Sending status with temperature: %d", temperature_celsius[0]);

    esp_err_t ret = can_send_message(tx_msg.identifier, data_send, tx_msg.data_length_code);
    //ESP_LOGI(TAG, "Status sent with temperature: %d", temperature_celsius[0]);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to send CAN message: %s", esp_err_to_name(ret));
        return ret;
    }

    return ESP_OK;
}

can_command_t can_commands[] = {
    // Example command registration,
    {CAN_GET_BOARD_DATA, send_board_data_callback},
    {CAN_GET_STATUS, send_status_callback},
    {CAN_OPEN_SOLENOID , sol_open_callback},
    {CAN_CLOSE_SOLENOID , sol_close_callback},
    {CAN_OPEN_SERVO , servo_open_callbak},
    {CAN_CLOSE_SERVO , servo_close_callbak},
    {CAN_MOVE_SERVO , servo_close_callbak},
    {RESET, reset_callback},
};

esp_err_t can_config_init(void) {

    esp_err_t err;

    // Register CAN commands
    err = can_register_commands(can_commands, sizeof(can_commands) / sizeof(can_commands[0]));
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "CAN command registration failed");
        return err;
    }


    // Start CAN driver
    err = can_start();
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "CAN driver start failed");
        return err;
    }

    // Initialize CAN driver
    err = can_task_init();
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "CAN driver initialization failed");
        return err;
    }


    return ESP_OK;
}