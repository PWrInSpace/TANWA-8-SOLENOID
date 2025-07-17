#include "servo_config.h"
#include "esp_log.h"

#define TAG "servo_config.c"
Servo_t servos[SERVO_COUNT] = {
    [N20_FILL_SERVO] = SERVO_INIT(15),
    [N2_FILL_SERVO] = SERVO_INIT(7)
};

esp_err_t init_multiple_servos()
{
  esp_err_t ret = ESP_OK;
  for (int i = 0; i < SERVO_COUNT; i++)
  {
    if (servo_init((ServoId_t)i) != EXIT_SUCCESS)
    {
      ESP_LOGE(TAG, "Failed to initialize servo %d", i);
      ret = ESP_LOG_ERROR;
    }
  }
  return ret;
}