#ifndef PWRINSPACE_CAN_COMMANDS_H
#define PWRINSPACE_CAN_COMMANDS_H

/** PLACE YOUR CAN CALLBACKS AND CAN MESSAGES HERE IN FORMAT*/
typedef enum {
    CAN_TEMPLATE_MESSAGE_ID = 0xFF,
    CAN_OPEN_SOL_ID = 0x11,
    CAN_CLOSE_SOL_ID = 0x12,
    CAN_SERVO_1,
    CAN_SERVO_2
} can_message_id_t;

/*PLACE YOUR FUNCTIONS ACCORDING TO THE TEMPLATE
* typedef esp_err_t (*can_command_handler_t)(uint8_t *data, uint8_t length);
* 
* REGISTER THEM IN can_config.c FILE
*/




#endif //PWRINSPACE_CAN_COMMANDS_H