#pragma once
#include "servo_control.h"

#define VALVE1_CLOSE_POSITION 155U
#define VALVE1_OPEN_POSITION 35U

#define VALVE3_CLOSE_POSITION 50U
#define VALVE3_OPEN_POSITION 170U

#define VALVE2_CLOSE_POSITION 170U
#define VALVE2_OPEN_POSITION 50U

extern Servo_t servos[SERVO_COUNT];

esp_err_t init_multiple_servos();