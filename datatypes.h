#ifndef FIRMWARE_DATATYPES_H
#define FIRMWARE_DATATYPES_H

#include <stdint.h>
#include <stdbool.h>

// Type Defines
// Enumeration for joystick buttons.
typedef enum {
    SWITCH_Y       = 0x01,
    SWITCH_B       = 0x02,
    SWITCH_A       = 0x04,
    SWITCH_X       = 0x08,
    SWITCH_L       = 0x10,
    SWITCH_R       = 0x20,
    SWITCH_ZL      = 0x40,
    SWITCH_ZR      = 0x80,
    SWITCH_MINUS   = 0x100,
    SWITCH_PLUS    = 0x200,
    SWITCH_LCLICK  = 0x400,
    SWITCH_RCLICK  = 0x800,
    SWITCH_HOME    = 0x1000,
    SWITCH_CAPTURE = 0x2000,
} JoystickButtons_t;

// Battery levels
#define BATTERY_FULL        0x08
#define BATTERY_MEDIUM      0x06
#define BATTERY_LOW         0x04
#define BATTERY_CRITICAL    0x02
#define BATTERY_EMPTY       0x00
#define BATTERY_CHARGING    0x01 // Can be OR'ed

// DPAD values
#define HAT_TOP          0x00
#define HAT_TOP_RIGHT    0x01
#define HAT_RIGHT        0x02
#define HAT_BOTTOM_RIGHT 0x03
#define HAT_BOTTOM       0x04
#define HAT_BOTTOM_LEFT  0x05
#define HAT_LEFT         0x06
#define HAT_TOP_LEFT     0x07
#define HAT_CENTER       0x08

// Analog sticks
#define STICK_MIN      0
#define STICK_CENTER 128
#define STICK_MAX    255

// https://github.com/dekuNukem/Nintendo_Switch_Reverse_Engineering/blob/master/bluetooth_hid_subcommands_notes.md
typedef enum {
    SUBCOMMAND_CONTROLLER_STATE_ONLY        = 0x00,
    SUBCOMMAND_BLUETOOTH_MANUAL_PAIRING     = 0x01,
    SUBCOMMAND_REQUEST_DEVICE_INFO          = 0x02,
    SUBCOMMAND_SET_INPUT_REPORT_MODE        = 0x03,
    SUBCOMMAND_TRIGGER_BUTTONS_ELAPSED_TIME = 0x04,
    SUBCOMMAND_GET_PAGE_LIST_STATE          = 0x05,
    SUBCOMMAND_SET_HCI_STATE                = 0x06,
    SUBCOMMAND_RESET_PAIRING_INFO           = 0x07,
    SUBCOMMAND_SET_SHIPMENT_LOW_POWER_STATE = 0x08,
    SUBCOMMAND_SPI_FLASH_READ               = 0x10,
    SUBCOMMAND_SPI_FLASH_WRITE              = 0x11,
    SUBCOMMAND_SPI_SECTOR_ERASE             = 0x12,
    SUBCOMMAND_RESET_NFC_IR_MCU             = 0x20,
    SUBCOMMAND_SET_NFC_IR_MCU_CONFIG        = 0x21,
    SUBCOMMAND_SET_NFC_IR_MCU_STATE         = 0x22,
    SUBCOMMAND_SET_PLAYER_LIGHTS            = 0x30,
    SUBCOMMAND_GET_PLAYER_LIGHTS            = 0x31,
    SUBCOMMAND_SET_HOME_LIGHTS              = 0x38,
    SUBCOMMAND_ENABLE_IMU                   = 0x40,
    SUBCOMMAND_SET_IMU_SENSITIVITY          = 0x41,
    SUBCOMMAND_WRITE_IMU_REGISTERS          = 0x42,
    SUBCOMMAND_READ_IMU_REGISTERS           = 0x43,
    SUBCOMMAND_ENABLE_VIBRATION             = 0x48,
    SUBCOMMAND_GET_REGULATED_VOLTAGE        = 0x50,
} Switch_Subcommand_t;

// https://github.com/dekuNukem/Nintendo_Switch_Reverse_Engineering/blob/master/spi_flash_notes.md
typedef enum {
    ADDRESS_SERIAL_NUMBER         = 0x6000,
    ADDRESS_CONTROLLER_COLOR      = 0x6050,
    ADDRESS_FACTORY_PARAMETERS_1  = 0x6080,
    ADDRESS_FACTORY_PARAMETERS_2  = 0x6098,
    ADDRESS_FACTORY_CALIBRATION_1 = 0x6020,
    ADDRESS_FACTORY_CALIBRATION_2 = 0x603D,
    ADDRESS_STICKS_CALIBRATION    = 0x8010,
    ADDRESS_IMU_CALIBRATION       = 0x8028,
} SPI_Address_t;

// Standard input report sent to Switch (doesn't contain IMU data)
// Note that compilers can align and order bits in every byte however they want (endianness)
// Taken from https://github.com/dekuNukem/Nintendo_Switch_Reverse_Engineering/blob/master/bluetooth_hid_notes.md#standard-input-report-format
// The order in every byte is inverted
typedef struct {
    uint8_t connection_info: 4;
    uint8_t battery_level: 4;
    bool button_y: 1;
    bool button_x: 1;
    bool button_b: 1;
    bool button_a: 1;
    bool button_right_sr: 1;
    bool button_right_sl: 1;
    bool button_r: 1;
    bool button_zr: 1;
    bool button_minus: 1;
    bool button_plus: 1;
    bool button_thumb_r: 1;
    bool button_thumb_l: 1;
    bool button_home: 1;
    bool button_capture: 1;
    uint8_t dummy: 1;
    bool charging_grip: 1;
    bool dpad_down: 1;
    bool dpad_up: 1;
    bool dpad_right: 1;
    bool dpad_left: 1;
    bool button_left_sr: 1;
    bool button_left_sl: 1;
    bool button_l: 1;
    bool button_zl: 1;
    uint8_t analog[6];
    uint8_t vibrator_input_report;
} USB_StandardReport_t;

// Full (extended) input report sent to Switch, with IMU data
typedef struct {
    USB_StandardReport_t standardReport;
    int16_t imu[3 * 2 * 3]; // each axis is uint16_t, 3 axis per sensor, 2 sensors (accel and gyro), 3 reports
} USB_ExtendedReport_t;

/* https://mzyy94.com/blog/2020/03/20/nintendo-switch-pro-controller-usb-gadget/ */
/*
typedef struct {
    bool button_1:1;
    bool button_2:1;
    bool button_3:1;
    bool button_4:1;
    bool button_5:1;
    bool button_6:1;
    bool button_7:1;
    bool button_8:1;
    bool button_9:1;
    bool button_10:1;
    bool button_11:1;
    bool button_12:1;
    bool button_13:1;
    bool button_14:1;
    int16_t x;
    int16_t y;
    int16_t z;
    int16_t rz;
    uint8_t dpad:4;
    bool button_15: 1;
    bool button_16: 1;
    bool button_17: 1;
    bool button_18: 1;
} USB_HID_Report_t;
*/

#endif // FIRMWARE_DATATYPES_H
