#include "Solenoid.h"
#include "BoardData.h"
#include <esp_err.h>
#include <driver/gpio.h>

esp_err_t valves_init(void) {
    esp_err_t err = ESP_OK;
    
    // Initialize valve array with names and GPIO pins
    for (int i = 0; i < NUM_OF_SOLENOIDS; ++i) {
        BoardData.valves[i].name = (ValveName)i;
        BoardData.valves[i].state = VALVE_OFF;
        BoardData.valves[i].gpio_pin = VALVE_GPIO_PINS[i];

        // Validate GPIO pin
        if (!GPIO_IS_VALID_OUTPUT_GPIO(BoardData.valves[i].gpio_pin)) {
            return ESP_ERR_INVALID_ARG;
        }

        gpio_config_t io_conf = {
            .pin_bit_mask = (1ULL << BoardData.valves[i].gpio_pin),
            .mode = GPIO_MODE_OUTPUT,
            .pull_up_en = GPIO_PULLUP_DISABLE,
            .pull_down_en = GPIO_PULLDOWN_DISABLE,
            .intr_type = GPIO_INTR_DISABLE
        };

        err = gpio_config(&io_conf);
        if (err != ESP_OK) {
            return err;
        }

        // Set initial state
        err = gpio_set_level(BoardData.valves[i].gpio_pin, BoardData.valves[i].state);
        if (err != ESP_OK) {
            return err;
        }
    }
    
    return ESP_OK;
}

esp_err_t set_valve_state(ValveName name, ValveState state) {
    // Validate valve name
    if (name >= NUM_OF_SOLENOIDS) {
        return ESP_ERR_INVALID_ARG;
    }

    // Acquire semaphore
   // if (xSemaphoreTake(BoardDataSemaphore, pdMS_TO_TICKS(1000)) != pdTRUE) {
   //     return ESP_ERR_TIMEOUT;
   // }

    // Update valve state
  //  BoardData.valves[name].state = state;
    
    // Set GPIO level
    esp_err_t err = gpio_set_level(BoardData.valves[name].gpio_pin, state);
    
    // Release semaphore
  //  xSemaphoreGive(BoardDataSemaphore);
    
    return err;
}