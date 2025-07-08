/**
 * @file servo_control.c
 * @author Michal Kos
 * @brief Servo control interface for multiple servos
 * @version 0.2
 * @date 2025-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "servo_control.h"
#include "servo_config.h"
/************************** PRIVATE INCLUDES ********************************/

#include "esp_log.h"
#include "BoardData.h"

/************************** PRIVATE VARIABLES *******************************/

static const char *TAG = "SERVO CONTROL";

// Servo configurations

/************************** PRIVATE FUNCTIONS *******************************/

static inline uint32_t angle_to_duty_us(uint8_t angle) {
  return (angle - SERVO_MIN_ANGLE) *
             (SERVO_MAX_PULSEWIDTH_US - SERVO_MIN_PULSEWIDTH_US) /
             (SERVO_MAX_ANGLE - SERVO_MIN_ANGLE) +
         SERVO_MIN_PULSEWIDTH_US;
}

/************************** CODE *********************************************/

uint16_t servo_init(ServoId_t servo_id) {
  if (servo_id >= SERVO_COUNT) {
    ESP_LOGE(TAG, "Invalid servo ID: %d", servo_id);
    return EXIT_FAILURE;
  }

  Servo_t *servo_ptr = &servos[servo_id];

  // Create timer
  mcpwm_timer_config_t timer_config = {
      .group_id = servo_id, // Use unique group ID for each servo
      .clk_src = MCPWM_TIMER_CLK_SRC_DEFAULT,
      .resolution_hz = SERVO_FREQUENCY_HZ,
      .period_ticks = SERVO_TIMEBASE_PERIOD,
      .count_mode = MCPWM_TIMER_COUNT_MODE_UP,
  };
  ESP_ERROR_CHECK(mcpwm_new_timer(&timer_config, &servo_ptr->timer));

  // Create operator
  mcpwm_operator_config_t operator_config = {
      .group_id = servo_id, // Operator in the same group as the timer
  };
  ESP_ERROR_CHECK(mcpwm_new_operator(&operator_config, &servo_ptr->oper));

  // Connect operator to timer
  ESP_ERROR_CHECK(
      mcpwm_operator_connect_timer(servo_ptr->oper, servo_ptr->timer));

  // Create comparator
  mcpwm_comparator_config_t comparator_config = {
      .flags.update_cmp_on_tez = true,
  };
  ESP_ERROR_CHECK(mcpwm_new_comparator(servo_ptr->oper, &comparator_config,
                                       &servo_ptr->comparator));

  // Create generator
  mcpwm_generator_config_t generator_config = {
      .gen_gpio_num = servo_ptr->pwm_pin,
  };
  ESP_ERROR_CHECK(mcpwm_new_generator(servo_ptr->oper, &generator_config,
                                      &servo_ptr->generator));

  // Set the initial compare value, so that the servo will spin to the center
  ESP_ERROR_CHECK(mcpwm_comparator_set_compare_value(
      servo_ptr->comparator, angle_to_duty_us(VALVE_CLOSE_POSITION)));

  // Set generator action on timer and compare event
  // Go high on counter empty
  ESP_ERROR_CHECK(mcpwm_generator_set_actions_on_timer_event(
      servo_ptr->generator,
      MCPWM_GEN_TIMER_EVENT_ACTION(MCPWM_TIMER_DIRECTION_UP,
                                   MCPWM_TIMER_EVENT_EMPTY,
                                   MCPWM_GEN_ACTION_HIGH),
      MCPWM_GEN_TIMER_EVENT_ACTION_END()));

  // Go low on compare threshold
  ESP_ERROR_CHECK(mcpwm_generator_set_actions_on_compare_event(
      servo_ptr->generator,
      MCPWM_GEN_COMPARE_EVENT_ACTION(MCPWM_TIMER_DIRECTION_UP,
                                     servo_ptr->comparator,
                                     MCPWM_GEN_ACTION_LOW),
      MCPWM_GEN_COMPARE_EVENT_ACTION_END()));

  // Enable and start timer
  ESP_ERROR_CHECK(mcpwm_timer_enable(servo_ptr->timer));
  ESP_ERROR_CHECK(
      mcpwm_timer_start_stop(servo_ptr->timer, MCPWM_TIMER_START_NO_STOP));

  ESP_LOGI(TAG, "Servo %d initialized on GPIO %d", servo_id, servo_ptr->pwm_pin);
  return EXIT_SUCCESS;
}


uint16_t move_servo(ServoId_t servo_id, uint8_t angle) {
  if (servo_id >= SERVO_COUNT) {
    ESP_LOGE(TAG, "Invalid servo ID: %d", servo_id);
    return EXIT_FAILURE;
  }

  Servo_t *servo_ptr = &servos[servo_id];
  ESP_LOGI(TAG, "Moving servo %d to angle: %d", servo_id, angle);

  if (mcpwm_comparator_set_compare_value(servo_ptr->comparator, angle_to_duty_us(angle)) != ESP_OK) {
    ESP_LOGE(TAG, "Move servo %d FAILURE", servo_id);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

esp_err_t open_servo(ServoId_t servo_id)
{
  if (servo_id >= SERVO_COUNT) {
    ESP_LOGE(TAG, "Invalid servo ID: %d", servo_id);
    return ESP_LOG_ERROR;
  }

  Servo_t *servo_ptr = &servos[servo_id];
  ESP_LOGI(TAG, "OPENING servo[%d] to angle: %d", servo_id, VALVE_OPEN_POSITION);

   if (mcpwm_comparator_set_compare_value(servo_ptr->comparator, angle_to_duty_us(VALVE_OPEN_POSITION)) != ESP_OK) {
    ESP_LOGE(TAG, "OPENING servo[%d] FAILURE", servo_id);
    return ESP_LOG_ERROR;
  }
  ESP_LOGI(TAG, "OPENED servo[%d] to angle: %d", servo_id, VALVE_OPEN_POSITION);

  return ESP_OK;
}

esp_err_t close_servo(ServoId_t servo_id)
{
  if (servo_id >= SERVO_COUNT) {
    ESP_LOGE(TAG, "Invalid servo ID: %d", servo_id);
    return ESP_LOG_ERROR;
  }

  Servo_t *servo_ptr = &servos[servo_id];
  ESP_LOGI(TAG, "CLOSING servo[%d] to angle: %d", servo_id, VALVE_CLOSE_POSITION);

   if (mcpwm_comparator_set_compare_value(servo_ptr->comparator, angle_to_duty_us(VALVE_CLOSE_POSITION)) != ESP_OK) {
    ESP_LOGE(TAG, "CLOSING servo[%d] FAILURE", servo_id);
    return ESP_LOG_ERROR;
  }
  ESP_LOGI(TAG, "CLOSED servo[%d] to angle: %d", servo_id, VALVE_CLOSE_POSITION);

  return ESP_OK;
}