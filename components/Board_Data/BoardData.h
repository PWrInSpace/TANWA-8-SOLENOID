#pragma once
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "stdbool.h"
#include "Solenoid.h"
#include "servo_control.h"

typedef struct {
    Valve valves[NUM_OF_SOLENOIDS];
} BoardData_t;

extern BoardData_t BoardData;
extern SemaphoreHandle_t BoardDataSemaphore;