#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_err.h"
#include "driver/gpio.h"
#include "board_config.h"
#include "setup_task.h"

#include "servo_control.h"
#define TAG "APP"

extern board_config_t config;

void app_main(void) {
    
    // CONFIGURE THE MESSAGE

    ESP_LOGI(TAG, "%s TANWA board starting", config.board_name);


if (setup_task_init() != ESP_OK) {
    ESP_LOGE(TAG, "Failed to initialize setup task");
    return;
}
//servo_init(N20_FILL_SERVO);
//    while(1) {
//        vTaskDelay(250 / portTICK_PERIOD_MS);
//        move_servo(N20_FILL_SERVO, 0);
//       vTaskDelay(250 / portTICK_PERIOD_MS);
//        move_servo(N20_FILL_SERVO, 180);
        led_toggle(&(config.status_led));
        vTaskDelay(1000 / portTICK_PERIOD_MS);
//    }
}