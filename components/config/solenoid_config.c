#include "solenoid_config.h"
#include "Solenoid.h"
#include "esp_log.h"
Valve valves[NUM_OF_SOLENOIDS] = {
    [N20_SOL_FILL] = {.name = N20_SOL_FILL},
    [N20_SOL_DEPR] = {.name = N20_SOL_DEPR},
    [N2_SOL_FILL] = {.name = N2_SOL_FILL},
    [N2_SOL_DEPR] = {.name = N2_SOL_DEPR},
    [DEPR_SOL_1] = {.name = DEPR_SOL_1},
    [DEPR_SOL_2] = {.name = DEPR_SOL_2}
};

esp_err_t valves_init()
{
    esp_err_t ret = 0;
    for(int i=0; i<NUM_OF_SOLENOIDS; i++)
    {
        ret |= valve_init(&valves[i]);
    }
    return ret;
}

