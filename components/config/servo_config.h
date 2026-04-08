#pragma once
#include "servo_control.h"

#define VALVE1_CLOSE_POSITION 0U
#define VALVE1_OPEN_POSITION 0U

#define VALVE3_CLOSE_POSITION 50U
#define VALVE3_OPEN_POSITION 150U

#define VALVE2_CLOSE_POSITION 5U
#define VALVE2_OPEN_POSITION 100U

extern Servo_t servos[SERVO_COUNT];

esp_err_t init_multiple_servos();