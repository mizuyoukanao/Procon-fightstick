/*
 Copyright (c) 2021 mizuyoukanao
 License: MIT
 */

#include <stdint.h>
#include <stdbool.h>

#include <avr/wdt.h>
#include <avr/power.h>

#include <LUFA/Drivers/USB/USB.h>
#include <LUFA/Drivers/Peripheral/Serial.h>
#include "Response.h"

#define ADAPTER_IN_NUM       (ENDPOINT_DIR_IN | 1)
#define ADAPTER_IN_SIZE      64
#define ADAPTER_OUT_NUM      (ENDPOINT_DIR_OUT | 2)
#define ADAPTER_OUT_SIZE     64

static bool CALLBACK_beforeSend(void);
static USB_ExtendedReport_t *selectedReport;
static USB_ExtendedReport_t r;
static USB_ExtendedReport_t idleReport;

ISR(USART1_RX_vect) {
}

void SetupHardware(void) {

    MCUSR = 0;
    wdt_disable();

    clock_prescale_set(clock_div_1);

    TCCR1B |= (1 << CS12); // Set up timer at FCPU / 256

    Serial_Init(9600, false);

    UCSR1B |= (1 << RXCIE1); // Enable the USART Receive Complete interrupt (USART_RXC)

    GlobalInterruptEnable();

    //while (!started) {}

    USB_Init();
}

void EVENT_USB_Device_ControlRequest(void) {
    // Switch doesn't use GetReport or SetReport

    switch (USB_ControlRequest.bRequest) {
        case HID_REQ_SetIdle: { // Difference between old firmware and this #1 : Old FW Sends a Broken Pipe status.
            if (USB_ControlRequest.bmRequestType == (REQDIR_HOSTTODEVICE | REQTYPE_CLASS | REQREC_INTERFACE)) {
                Endpoint_ClearSETUP();
                Endpoint_ClearStatusStage();
                // Ignore idle period
            }
            break;
        }
            // No other HID requests are used
            // Standard control requests (such as SET_CONFIGURATION) are handled by LUFA
    }
}

void EVENT_USB_Device_Connect(void) {
}

void EVENT_USB_Device_Disconnect(void) {
}

void EVENT_USB_Device_ConfigurationChanged(void) {

    Endpoint_ConfigureEndpoint(ADAPTER_IN_NUM, EP_TYPE_INTERRUPT, ADAPTER_IN_SIZE, 1);
#ifdef ADAPTER_OUT_NUM
    Endpoint_ConfigureEndpoint(ADAPTER_OUT_NUM, EP_TYPE_INTERRUPT, ADAPTER_OUT_SIZE, 1);
#endif
}

static void initialize_idle_report(USB_ExtendedReport_t *extendedReport) {
    memset(extendedReport, 0, sizeof(USB_ExtendedReport_t));

    USB_StandardReport_t *standardReport = &(extendedReport->standardReport);
    standardReport->connection_info = 1; // Pro Controller + USB connected
    standardReport->battery_level = BATTERY_FULL | BATTERY_CHARGING;

    /*standardReport->button_y = false;
    standardReport->button_x = false;
    standardReport->button_b = false;
    standardReport->button_a = false;
    standardReport->button_right_sr = false;
    standardReport->button_right_sl = false;
    standardReport->button_r = false;
    standardReport->button_zr = false;
    standardReport->button_minus = false;
    standardReport->button_plus = false;
    standardReport->button_thumb_r = false;
    standardReport->button_thumb_l = false;
    standardReport->button_home = false;
    standardReport->button_capture = false;
    standardReport->dummy = 0;
    standardReport->charging_grip = false;
    standardReport->dpad_down = false;
    standardReport->dpad_up = false;
    standardReport->dpad_right = false;
    standardReport->dpad_left = false;
    standardReport->button_left_sr = false;
    standardReport->button_left_sl = false;
    standardReport->button_l = false;
    standardReport->button_zl = false;*/
    standardReport->charging_grip = true;

    // Left stick
    uint16_t lx = 0x0800;
    uint16_t ly = 0x0800;
    standardReport->analog[0] = lx & 0xFF;
    standardReport->analog[1] = ((ly & 0x0F) << 4) | ((lx & 0xF00) >> 8);
    standardReport->analog[2] = (ly & 0xFF0) >> 4;

    // Right stick
    uint16_t rx = 0x0800;
    uint16_t ry = 0x0800;
    standardReport->analog[3] = rx & 0xFF;
    standardReport->analog[4] = ((ry & 0x0F) << 4) | ((rx & 0xF00) >> 8);
    standardReport->analog[5] = (ry & 0xFF0) >> 4;

    standardReport->vibrator_input_report = 0x0c;
}

static bool CALLBACK_beforeSend() {
    //if (sendReport)
    //{
        selectedReport = &r;
        //selectedReport = &idleReport;
        //sendReport = 0;
        return true;
    //}
    //else
    //{
    //    return false;
    //}
}

void SendNextReport(void) {

    // We'll then move on to the IN endpoint.
    Endpoint_SelectEndpoint(JOYSTICK_IN_EPADDR);
    // We first check to see if the host is ready to accept data.
    if (Endpoint_IsINReady()) {
        // Received IN interrupt. Switch wants a new packet.
        send_IN_report();
    }
}

void ReceiveNextReport(void) {
    // We'll start with the OUT endpoint.
    Endpoint_SelectEndpoint(JOYSTICK_OUT_EPADDR);
    // We'll check to see if we received something on the OUT endpoint.
    if (Endpoint_IsOUTReceived()) {
        // Messages from Switch
        static uint8_t switchResponseBuffer[JOYSTICK_EPSIZE];
        // Clear input buffer before every read
        memset(switchResponseBuffer, 0, sizeof(switchResponseBuffer));

        uint8_t *ReportData = switchResponseBuffer;
        uint16_t ReportSize = 0;
        // If we received something, and the packet has data, we'll store it.
        while (Endpoint_IsReadWriteAllowed()) {
            uint8_t b = Endpoint_Read_8();
            if (ReportSize < sizeof(switchResponseBuffer)) {
                // avoid over filling of the buffer
                *ReportData = b;
                ReportSize++;
                ReportData++;
            }
        }

        // We acknowledge an OUT packet on this endpoint.
        Endpoint_ClearOUT();

        // At this point, we can react to this data.
        //for (uint8_t i = 0; i < ReportSize; i++) {
        //    Serial_SendString(switchResponseBuffer[i]);
        //}
        //Serial_SendString("\r\n");
        process_OUT_report(switchResponseBuffer, ReportSize);
    }
}

void HID_Task(void) {

    if (USB_DeviceState != DEVICE_STATE_Configured)
        return;

    ReceiveNextReport();

    SendNextReport();
}

int main(void) {

    SetupHardware();
    // Assign default controller state values (no buttons pressed and centered sticks)
    //initialize_idle_report(&controllerReport); // Will be populated later with values received from UART
    initialize_idle_report(&idleReport); // Idle report (no buttons pressed)
    selectedReport = &idleReport; // Use idle report until data is received from UART

    setup_response_manager(CALLBACK_beforeSend, &selectedReport);
    for(;;) {
        HID_Task();
        USB_USBTask();
    }
}
