#ifndef SOLENOID_H
#define SOLENOID_H

#include <driver/gpio.h>

typedef enum {
    N20_SOL_FILL,
    N20_SOL_DEPR,
    N2_SOL_FILL,
    N2_SOL_DEPR,
    DEPR_SOL_1,
    DEPR_SOL_2,
    NUM_OF_SOLENOIDS // Count of solenoids
} ValveName;

// GPIO pin mapping for each solenoid
static const gpio_num_t VALVE_GPIO_PINS[NUM_OF_SOLENOIDS] = {
    [N20_SOL_FILL] = CONFIG_GPIO_SOL1,
    [N20_SOL_DEPR] = CONFIG_GPIO_SOL2,
    [N2_SOL_FILL] = CONFIG_GPIO_SOL3,
    [N2_SOL_DEPR] = CONFIG_GPIO_SOL4,
    [DEPR_SOL_1] = CONFIG_GPIO_SOL5,
    [DEPR_SOL_2] = CONFIG_GPIO_SOL5
};

typedef enum {
    VALVE_OFF = 0,
    VALVE_ON = 1
} ValveState;

typedef struct {
    ValveName name;
    ValveState state;
    gpio_num_t gpio_pin;
} Valve;

extern Valve valves[NUM_OF_SOLENOIDS];

esp_err_t valves_init(void);
esp_err_t set_valve_state(ValveName name, ValveState state);

#endif // SOLENOID_H