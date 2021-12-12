#include "Descriptors.h"

// Pro Controller HID descriptor
// https://gist.github.com/ToadKing/b883a8ccfa26adcc6ba9905e75aeb4f2
const USB_Descriptor_HIDReport_Datatype_t PROGMEM JoystickReport[] = {
    0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
0x15, 0x00,        // Logical Minimum (0)
0x09, 0x04,        // Usage (Joystick)
0xA1, 0x01,        // Collection (Application)
0x85, 0x30,        //   Report ID (48)
0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
0x05, 0x09,        //   Usage Page (Button)
0x19, 0x01,        //   Usage Minimum (0x01)
0x29, 0x0A,        //   Usage Maximum (0x0A)
0x15, 0x00,        //   Logical Minimum (0)
0x25, 0x01,        //   Logical Maximum (1)
0x75, 0x01,        //   Report Size (1)
0x95, 0x0A,        //   Report Count (10)
0x55, 0x00,        //   Unit Exponent (0)
0x65, 0x00,        //   Unit (None)
0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
0x05, 0x09,        //   Usage Page (Button)
0x19, 0x0B,        //   Usage Minimum (0x0B)
0x29, 0x0E,        //   Usage Maximum (0x0E)
0x15, 0x00,        //   Logical Minimum (0)
0x25, 0x01,        //   Logical Maximum (1)
0x75, 0x01,        //   Report Size (1)
0x95, 0x04,        //   Report Count (4)
0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
0x75, 0x01,        //   Report Size (1)
0x95, 0x02,        //   Report Count (2)
0x81, 0x03,        //   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
0x0B, 0x01, 0x00, 0x01, 0x00,  //   Usage (0x010001)
0xA1, 0x00,        //   Collection (Physical)
0x0B, 0x30, 0x00, 0x01, 0x00,  //     Usage (0x010030)
0x0B, 0x31, 0x00, 0x01, 0x00,  //     Usage (0x010031)
0x0B, 0x32, 0x00, 0x01, 0x00,  //     Usage (0x010032)
0x0B, 0x35, 0x00, 0x01, 0x00,  //     Usage (0x010035)
0x15, 0x00,        //     Logical Minimum (0)
0x27, 0xFF, 0xFF, 0x00, 0x00,  //     Logical Maximum (65534)
0x75, 0x10,        //     Report Size (16)
0x95, 0x04,        //     Report Count (4)
0x81, 0x02,        //     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
0xC0,              //   End Collection
0x0B, 0x39, 0x00, 0x01, 0x00,  //   Usage (0x010039)
0x15, 0x00,        //   Logical Minimum (0)
0x25, 0x07,        //   Logical Maximum (7)
0x35, 0x00,        //   Physical Minimum (0)
0x46, 0x3B, 0x01,  //   Physical Maximum (315)
0x65, 0x14,        //   Unit (System: English Rotation, Length: Centimeter)
0x75, 0x04,        //   Report Size (4)
0x95, 0x01,        //   Report Count (1)
0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
0x05, 0x09,        //   Usage Page (Button)
0x19, 0x0F,        //   Usage Minimum (0x0F)
0x29, 0x12,        //   Usage Maximum (0x12)
0x15, 0x00,        //   Logical Minimum (0)
0x25, 0x01,        //   Logical Maximum (1)
0x75, 0x01,        //   Report Size (1)
0x95, 0x04,        //   Report Count (4)
0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
0x75, 0x08,        //   Report Size (8)
0x95, 0x34,        //   Report Count (52)
0x81, 0x03,        //   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
0x06, 0x00, 0xFF,  //   Usage Page (Vendor Defined 0xFF00)
0x85, 0x21,        //   Report ID (33)
0x09, 0x01,        //   Usage (0x01)
0x75, 0x08,        //   Report Size (8)
0x95, 0x3F,        //   Report Count (63)
0x81, 0x03,        //   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
0x85, 0x81,        //   Report ID (-127)
0x09, 0x02,        //   Usage (0x02)
0x75, 0x08,        //   Report Size (8)
0x95, 0x3F,        //   Report Count (63)
0x81, 0x03,        //   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
0x85, 0x01,        //   Report ID (1)
0x09, 0x03,        //   Usage (0x03)
0x75, 0x08,        //   Report Size (8)
0x95, 0x3F,        //   Report Count (63)
0x91, 0x83,        //   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Volatile)
0x85, 0x10,        //   Report ID (16)
0x09, 0x04,        //   Usage (0x04)
0x75, 0x08,        //   Report Size (8)
0x95, 0x3F,        //   Report Count (63)
0x91, 0x83,        //   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Volatile)
0x85, 0x80,        //   Report ID (-128)
0x09, 0x05,        //   Usage (0x05)
0x75, 0x08,        //   Report Size (8)
0x95, 0x3F,        //   Report Count (63)
0x91, 0x83,        //   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Volatile)
0x85, 0x82,        //   Report ID (-126)
0x09, 0x06,        //   Usage (0x06)
0x75, 0x08,        //   Report Size (8)
0x95, 0x3F,        //   Report Count (63)
0x91, 0x83,        //   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Volatile)
0xC0,              // End Collection
};

// Device Descriptor Structure
const USB_Descriptor_Device_t PROGMEM DeviceDescriptor = {
        .Header                 = {.Size = sizeof(USB_Descriptor_Device_t), .Type = DTYPE_Device},

        .USBSpecification       = VERSION_BCD(2,0,0),
        .Class                  = USB_CSCP_NoDeviceClass,
        .SubClass               = USB_CSCP_NoDeviceSubclass,
        .Protocol               = USB_CSCP_NoDeviceProtocol,

        .Endpoint0Size          = FIXED_CONTROL_ENDPOINT_SIZE,

        .VendorID               = 0x057E,
        .ProductID              = 0x2009,
        .ReleaseNumber          = VERSION_BCD(2,1,0),

        .ManufacturerStrIndex   = STRING_ID_Manufacturer,
        .ProductStrIndex        = STRING_ID_Product,
        .SerialNumStrIndex      = STRING_ID_Serial,

        .NumberOfConfigurations = FIXED_NUM_CONFIGURATIONS
};

// Configuration Descriptor Structure
const USB_Descriptor_Configuration_t PROGMEM ConfigurationDescriptor = {
        .Config = {
                .Header                 = {.Size = sizeof(USB_Descriptor_Configuration_Header_t), .Type = DTYPE_Configuration},

                .TotalConfigurationSize = sizeof(USB_Descriptor_Configuration_t),
                .TotalInterfaces        = 1,

                .ConfigurationNumber    = 1,
                .ConfigurationStrIndex  = NO_DESCRIPTOR,

                .ConfigAttributes       = (USB_CONFIG_ATTR_RESERVED | USB_CONFIG_ATTR_REMOTEWAKEUP),

                .MaxPowerConsumption    = USB_CONFIG_POWER_MA(500)
        },

        .HID_Interface = {
                .Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},

                .InterfaceNumber        = INTERFACE_ID_Joystick,
                .AlternateSetting       = 0x00,

                .TotalEndpoints         = 2,

                .Class                  = HID_CSCP_HIDClass,
                .SubClass               = HID_CSCP_NonBootSubclass,
                .Protocol               = HID_CSCP_NonBootProtocol,

                .InterfaceStrIndex      = NO_DESCRIPTOR
        },

        .HID_JoystickHID = {
                .Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},

                .HIDSpec                = VERSION_BCD(1,1,1),
                .CountryCode            = 0x00,
                .TotalReportDescriptors = 1,
                .HIDReportType          = HID_DTYPE_Report,
                .HIDReportLength        = sizeof(JoystickReport)
        },

        .HID_ReportINEndpoint = {
                .Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

                .EndpointAddress        = JOYSTICK_IN_EPADDR,
                .Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
                .EndpointSize           = JOYSTICK_EPSIZE,
                .PollingIntervalMS      = 0x08
        },

        .HID_ReportOUTEndpoint = {
                .Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

                .EndpointAddress        = JOYSTICK_OUT_EPADDR,
                .Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
                .EndpointSize           = JOYSTICK_EPSIZE,
                .PollingIntervalMS      = 0x08
        },
};

// Language Descriptor Structure
const USB_Descriptor_String_t PROGMEM LanguageString = {
        .Header = { .Size = USB_STRING_LEN(1), .Type = DTYPE_String },
        .UnicodeString = { LANGUAGE_ID_ENG }
};

// Manufacturer, Product and Serial number Descriptor Strings
const USB_Descriptor_String_t PROGMEM ManufacturerString = {
        .Header = { .Size = USB_STRING_LEN(18), .Type = DTYPE_String },
        .UnicodeString = L"Nintendo Co., Ltd."
};
const USB_Descriptor_String_t PROGMEM ProductString = {
        .Header = { .Size = USB_STRING_LEN(14), .Type = DTYPE_String },
        .UnicodeString = L"Pro Controller"
};
const USB_Descriptor_String_t PROGMEM SerialNumberString = {
        .Header = { .Size = USB_STRING_LEN(12), .Type = DTYPE_String },
        .UnicodeString = L"010101010101"
};

//const USB_Descriptor_String_t PROGMEM ConfigurationString = {
//        .Header = { .Size = USB_STRING_LEN(30), .Type = DTYPE_String },
//        .UnicodeString = L"Nintendo Switch Pro Controller"
//};
//
// USB Device Callback - Get Descriptor
uint16_t CALLBACK_USB_GetDescriptor(
        const uint16_t wValue,
        const uint16_t wIndex,
        const void **const DescriptorAddress
) {
    const uint8_t  DescriptorType   = (wValue >> 8);
    const uint8_t  DescriptorNumber = (wValue & 0xFF);

    const void *Address = NULL;
    uint16_t    Size    = NO_DESCRIPTOR;

    switch (DescriptorType) {
        case DTYPE_Device:
            Address = &DeviceDescriptor;
            Size    = sizeof(USB_Descriptor_Device_t);
            break;
        case DTYPE_Configuration:
            Address = &ConfigurationDescriptor;
            Size    = sizeof(USB_Descriptor_Configuration_t);
            break;
        case DTYPE_String:
            switch (DescriptorNumber) {
                case STRING_ID_Language:
                    Address = &LanguageString;
                    Size    = pgm_read_byte(&LanguageString.Header.Size);
                    break;
                case STRING_ID_Manufacturer:
                    Address = &ManufacturerString;
                    Size    = pgm_read_byte(&ManufacturerString.Header.Size);
                    break;
                case STRING_ID_Product:
                    Address = &ProductString;
                    Size    = pgm_read_byte(&ProductString.Header.Size);
                    break;
                case STRING_ID_Serial:
                    Address = &SerialNumberString;
                    Size    = pgm_read_byte(&SerialNumberString.Header.Size);
                    break;
                
            }

            break;
        case DTYPE_HID:
            Address = &ConfigurationDescriptor.HID_JoystickHID;
            Size    = sizeof(USB_HID_Descriptor_HID_t);
            break;
        case DTYPE_Report:
            Address = &JoystickReport;
            Size    = sizeof(JoystickReport);
            break;
    }

    *DescriptorAddress = Address;
    return Size;
}
