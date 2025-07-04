#include "console_config.h"
#include "BoardData.h"
#include "esp_system.h"
#include "esp_log.h"
#include "console.h"
#define TAG "CONSOLE_CONFIG"

static int reset_device(int argc, char **argv) {
    esp_restart();
    return 0;
}

static int sol_on(int argc, char **argv) {
    CONSOLE_WRITE("TURNED ON SOLENOIDS ALL!:");
    esp_err_t err = gpio_set_level(CONFIG_GPIO_SOL1, 1);
     err = gpio_set_level(CONFIG_GPIO_SOL2, 1);
     err = gpio_set_level(CONFIG_GPIO_SOL3, 1);
     err = gpio_set_level(CONFIG_GPIO_SOL4, 1);
     err = gpio_set_level(CONFIG_GPIO_SOL5, 1);
     err = gpio_set_level(CONFIG_GPIO_SOL6, 1);
     CONSOLE_WRITE("TURNED ON SOLENOIDS ALL!:");
   // set_valve_state(N20_SOL_FILL,VALVE_ON);
    return 0;
}

static int sol_off(int argc, char **argv) {
    CONSOLE_WRITE("TURNED OFF SOLENOID!:");
    set_valve_state(N20_SOL_FILL,VALVE_OFF);
    return 0;
}

static int read_temperature(int argc, char **argv) {
    float temp[2] = {50, 100};
    int raw[2] = {1000,2000};
    uint8_t ret = 0;
/**
    ret = tmp1075_get_temp_raw(&(TANWA_hardware.tmp1075[0]), &raw[0]);
    if (ret != TMP1075_OK) {
        ESP_LOGE(TAG, "TMP1075 #1 read raw failed - status: %d", ret);
        return -1;
    }
    ret = tmp1075_get_temp_celsius(&(TANWA_hardware.tmp1075[0]), &temp[0]);
    if (ret != TMP1075_OK) {
        ESP_LOGE(TAG, "TMP1075 #1 read temp failed - status: %d", ret);
        return -1;
    }
    ret = tmp1075_get_temp_raw(&(TANWA_hardware.tmp1075[1]), &raw[1]);
    if (ret != TMP1075_OK) {
        ESP_LOGE(TAG, "TMP1075 #2 read raw failed - status: %d", ret);
        return -1;
    }
    ret = tmp1075_get_temp_celsius(&(TANWA_hardware.tmp1075[1]), &temp[1]);
    if (ret != TMP1075_OK) {
        ESP_LOGE(TAG, "TMP1075 #2 read temp failed - status: %d", ret);
        return -1;
    }
        */
    
    CONSOLE_WRITE("TMP1075 Temperature:");
    CONSOLE_WRITE("#1 => raw: %d, temp: %f", raw[0], temp[0]);
    CONSOLE_WRITE("#2 => raw: %d, temp: %f", raw[1], temp[1]);

    return 0;
}

static int read_pwr_data(int argc, char **argv)
{
    CONSOLE_WRITE("PWR DATA :");
    CONSOLE_WRITE("##########  24V  ############");
    CONSOLE_WRITE("V_in => %f, I_in: %f", 55, 55);
    CONSOLE_WRITE("##########  12V  ############");
    CONSOLE_WRITE("V_in => %f, I_in: %f", 55, 55);
    return 0;
}

static esp_console_cmd_t cmd[] = {
    // system commands
    {"reset-dev", "restart device", NULL, reset_device, NULL, NULL, NULL},
    {"temp-read", "read temperature", NULL, read_temperature, NULL, NULL, NULL},
    {"pwr-data", "read pwr data", NULL, read_pwr_data, NULL, NULL, NULL},
    {"sol-on", "sol_on", NULL, sol_on, NULL, NULL, NULL},
    {"sol-off", "sol_off", NULL, sol_off, NULL, NULL, NULL},
};

esp_err_t console_config_init() {
    esp_err_t ret;
    ret = console_init();  // Ensure this succeeds
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "console_init failed: %s", esp_err_to_name(ret));
        return ret;
    }

    ret = console_register_commands(cmd, sizeof(cmd) / sizeof(cmd[0]));
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "console_register_commands failed: %s", esp_err_to_name(ret));
        return ret;
    }

    ESP_LOGI(TAG, "Console commands registered successfully.");
    return ESP_OK;
}
