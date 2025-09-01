#pragma once
#include "servo_control.h"

#define VALVE1_CLOSE_POSITION 0U
#define VALVE1_OPEN_POSITION 110U

#define VALVE3_CLOSE_POSITION 30U
#define VALVE3_OPEN_POSITION 135U

#define VALVE2_CLOSE_POSITION 59U
#define VALVE2_OPEN_POSITION 170U

extern Servo_t servos[SERVO_COUNT];

esp_err_t init_multiple_servos();