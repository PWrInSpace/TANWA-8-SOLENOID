#include "data_board_task.h"
#include "servo_config.h"
#include "solenoid_config.h"

#define TAG "DATA_BOARD_TASK"

void data_board_task(void *arg) {
    // Take semaphore with timeout
    if (xSemaphoreTake(BoardDataSemaphore, pdMS_TO_TICKS(1000)) == pdTRUE) {
        // Copy solenoid states
        for (int i = 0; i < NUM_OF_SOLENOIDS; i++) 
        {
                BoardData.solenoid_states[i] = valves[i].state;
        }

        // Copy servo states and angles
        for (int i = 0; i < SERVO_COUNT; i++) {
            BoardData.servo_states[i].state = servos[i].state.state;
            BoardData.servo_states[i].angle= servos[i].state.angle;
        }

        // Release semaphore
        xSemaphoreGive(BoardDataSemaphore);
    } else {
        ESP_LOGE(TAG, "Failed to take BoardDataSemaphore");
    }

    vTaskDelete(NULL); // Delete task when done, if intended to run once
}