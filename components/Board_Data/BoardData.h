#pragma once
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "stdbool.h"
#include "Solenoid.h"
#include "solenoid_config.h"
#include "servo_config.h"


typedef struct {
    Valve valves[NUM_OF_SOLENOIDS];
    float temperature[2];
    bool servo_state[SERVO_COUNT];
    float servo_angles[SERVO_COUNT];
    bool solenoid_states[NUM_OF_SOLENOIDS];
} BoardData_t;

extern BoardData_t BoardData;
extern SemaphoreHandle_t BoardDataSemaphore;