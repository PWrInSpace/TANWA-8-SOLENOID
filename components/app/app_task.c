#include "app_task.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"

#include "can_api.h"
#include "tmp1075.h"
#include "board_config.h"
#include "BoardData.h"

#include "can_commands.h"


#define APP_TASK_STACK_SIZE CONFIG_APP_TASK_STACK_SIZE
#define APP_TASK_PRIORITY CONFIG_APP_TASK_PRIORITY
#define APP_TASK_CORE_ID CONFIG_APP_TASK_CORE_ID
#define TAG "APP_TASK"

static TaskHandle_t app_task_handle = NULL;

esp_err_t app_task_init(void) {
    
    if(xTaskCreatePinnedToCore(app_task, "app_task", APP_TASK_STACK_SIZE, NULL, APP_TASK_PRIORITY, &app_task_handle, APP_TASK_CORE_ID) == pdPASS) {
        ESP_LOGI("APP_TASK", "App task created successfully");
    } else {
        ESP_LOGE("APP_TASK", "Failed to create app task");
        return ESP_FAIL;
    }

    return ESP_OK;
}

esp_err_t app_task_deinit(void) {
    if (app_task_handle != NULL) {
        vTaskDelete(app_task_handle);
        app_task_handle = NULL;
    }
    
    return ESP_OK;
}


void app_task(void *arg) {

    // YOUR IMAGINATION IS THE ONLY LIMITATION
    while(1) {
        //ESP_LOGI("APP_TASK", "App task working");
        tmp1075_get_temp_celsius(&config.tmp1075[0], &BoardData.temperature[0]);
        tmp1075_get_temp_celsius(&config.tmp1075[1], &BoardData.temperature[1]);
        // printf("TEMP 1 is = %f\n", BoardData.temperature[0]);
        // printf("TEMP 1 is = %f\n", BoardData.temperature[1]);

        // uint8_t data[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
        // can_send_message(CAN_SEND_STATUS, data, 8);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        
    }
}