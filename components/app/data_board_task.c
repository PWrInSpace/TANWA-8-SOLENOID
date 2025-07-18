#include "data_board_task.h"
#include "servo_config.h"
#include "solenoid_config.h"

#define TAG "DATA_BOARD_TASK"

void data_board_task(void *arg) {
    // Take semaphore with timeout
    while (1)
    {
    
        if (xSemaphoreTake(BoardDataSemaphore, pdMS_TO_TICKS(1000)) == pdTRUE) {
            // Copy solenoid states
            for (int i = 0; i < NUM_OF_SOLENOIDS; i++) 
            {
                    BoardData.solenoid_states[i] = valves[i].state;
                    //ESP_LOGI(TAG, "Solenoid %d state: %d", i, BoardData.solenoid_states[i]);
            }

            // Copy servo states and angles
            for (int i = 0; i < SERVO_COUNT; i++) {
                BoardData.servo_states[i].state = servos[i].state.state;
                BoardData.servo_states[i].angle= servos[i].state.angle;
                //ESP_LOGI(TAG, "Servo %d state: %d, angle: %d", i, BoardData.servo_states[i].state, BoardData.servo_states[i].angle);
            }

            // Release semaphore
            xSemaphoreGive(BoardDataSemaphore);
        } else {
            ESP_LOGE(TAG, "Failed to take BoardDataSemaphore");
        }
        vTaskDelay(pdMS_TO_TICKS(50)); // Delay to avoid busy-waiting
    }

    vTaskDelete(NULL); // Delete task when done, if intended to run once
}

esp_err_t board_data_task_init(void) {

    if(xTaskCreatePinnedToCore(data_board_task, "Board Data Task", 4096, NULL, 4, NULL, 1) != pdPASS) {
        ESP_LOGE(TAG, "Failed to create CAN task");
        return ESP_FAIL;
    }

    return ESP_OK;
}