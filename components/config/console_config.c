#include "console_config.h"
#include "BoardData.h"
#include "esp_system.h"
#include "esp_log.h"
#include "console.h"
#include "servo_control.h"
#include "solenoid_config.h"
#include "Solenoid.h"
#include "tmp1075.h"
#include "board_config.h"

#define TAG "CONSOLE_CONFIG"

static int reset_device(int argc, char **argv) {
    esp_restart();
    return 0;
}

static int sol_on(int argc, char **argv) {
    ValveName valve = atoi(argv[1]);
        set_valve_state(valve, VALVE_ON);
    CONSOLE_WRITE("TURNED ON -> SOLENOID[%d]", valve);
    return 0;
}

static int sol_off(int argc, char **argv) {
    ValveName valve = atoi(argv[1]);
    set_valve_state(valve, VALVE_OFF);
    CONSOLE_WRITE("TURNED OFF -> SOLENOID[%d]", valve);
    return 0;
}


static int read_temperature(int argc, char **argv) {

    uint8_t ret = 0;
    float temp[TMP1075_NUM];

    ret = tmp1075_get_temp_celsius(&(config.tmp1075[0]), &temp[0]);
    if (ret != TMP1075_OK) {
        ESP_LOGE(TAG, "TMP1075 #1 read temp failed - status: %d", ret);
        return -1;
    }
    ret = tmp1075_get_temp_celsius(&(config.tmp1075[1]), &temp[1]);
    if (ret != TMP1075_OK) {
        ESP_LOGE(TAG, "TMP1075 #2 read temp failed - status: %d", ret);
        return -1;
    }
    
    CONSOLE_WRITE("TMP1075 Temperature:");
    CONSOLE_WRITE("#1 => temp1 %d, #1 => temp2: %f", temp[0], temp[1]);

    return 0;
}


static int read_board_data(int argc, char **argv)
{
    CONSOLE_WRITE("SOLENOID DATA :");
    CONSOLE_WRITE("########## TEMPERATURES ##########");
    CONSOLE_WRITE("V_in => %f, I_in: %f", 55, 55);
    CONSOLE_WRITE("########## SOLENOID_STATES ##########");
    CONSOLE_WRITE("V_in => %f, I_in: %f", 55, 55);
    CONSOLE_WRITE("########## SERVO_STATES_AND_ANGLES ##########");
    return 0;
}

static int servo_angle_move(int argc, char **argv)
{
    if (argc < 3) {
    CONSOLE_WRITE("ERROR: Usage: servo-move <servo_id> <angle> <time_ms>");
    return -1;
  }
    ServoId_t servo = atoi(argv[1]);
    uint8_t angle = atoi(argv[2]);
    uint16_t time_ms = 0;
    if (argc >= 4) {
    time_ms = atoi(argv[3]);
    } else {
    CONSOLE_WRITE("No time_ms provided, servo %d will stay at angle %d", servo, angle);
    }
    move_servo(servo, angle, time_ms);
    CONSOLE_WRITE("MOVE_SERVO_ANGLE SERVO[%d] = %d",servo, angle);
    return 0;
}

static int servo_close_cli(int argc, char **argv)
{
    
    ServoId_t servo = atoi(argv[1]);
    close_servo(servo);
    CONSOLE_WRITE("SERVO_CLOSE SERVO[%d] = %d",servo, VALVE_CLOSE_POSITION);
    return 0;
}

static int servo_open_cli(int argc, char **argv)
{
    if (argc < 3) {
    CONSOLE_WRITE("ERROR: Usage: servo-open <servo_id> <time_ms>");
    return -1;
  }
    ServoId_t servo = atoi(argv[1]);
    uint16_t time_ms = 0 ;
    if (argc >= 3) {
    time_ms = atoi(argv[2]);
    } else {
    CONSOLE_WRITE("No time_ms provided, servo %d will stay at angle %d", servo, VALVE_OPEN_POSITION);
    }
    open_servo(servo, time_ms);
    CONSOLE_WRITE("OPEN_SERVO SERVO[%d] = %d",servo, VALVE_OPEN_POSITION);
    return 0;
}

static esp_console_cmd_t cmd[] = {
    // system commands
    {"reset-dev", "restart device", NULL, reset_device, NULL, NULL, NULL},
    {"temp-read", "read temperature", NULL, read_temperature, NULL, NULL, NULL},
    {"board-data", "read pwr data", NULL, read_board_data, NULL, NULL, NULL},
    {"sol-on", "sol_on", NULL, sol_on, NULL, NULL, NULL},
    {"sol-off", "sol_off", NULL, sol_off, NULL, NULL, NULL},
    {"servo-move", "servo-angle-move", NULL, servo_angle_move, NULL, NULL, NULL},
    {"servo-open", "servo-open", NULL, servo_open_cli, NULL, NULL, NULL},
    {"servo-close", "servo-close", NULL, servo_close_cli, NULL, NULL, NULL},
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
