# digital-dashboard
Repository for an ESP32 based CAN bus powered dashboard. Originally developed for Wildcat Formula Racing (University of Arizona) FSAE racecar.

## Regarding vehicle specific differences (or changes):

The code has been setup for the current version (as of Spring 2024) of the Wildcat Formula Racing racecar. For any other vehicle applications, you must reconfigure the `can_protocol.h` and `can_protocol.h` files found in `main\src\CAN` otherwise the dashboard will not know what data is relevant or how to translate it from the CAN bus. Additionally, you may want to reconfigure the constants in `main\src\vehicle_constants.h` to reflect your car's redline, RPM range, etc.

## Get started

1. Install Arduino IDE (version 2.x is more straightforward)
2. Open the `.ino` file in Arduino IDE
3. Go to File/Preferences and set Sketchbook location to the path of this project (...to where this README is located)
4. In Arduino IDE, install drivers for ESP32 by Espressif Systems
5. In Arduino IDE, install library TFT_eSPI by Bodmer
6. Move the "User_Setup.h" file into `libraries\TFT_eSPI` (it should overwrite the existing file in there).
7. In Arduino IDE, install library CAN by Sandeep Mistry
8. Plug ESP32 into serial port. If the ESP32 is not detected, you may need to install VCP drivers on your system first from here: https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads
9. Select it's serial port and assign as an ESP32 Dev Module
10. Upload project... let it compile
11. Once Output displays "Connecting....." hold the BOOT button on the ESP32
12. Wait for the upload to complete before releasing BOOT button
13. Reboot the device (using EN button) and it should be working

## Building the Dashboard Unit

### Parts Used:

ESP32 Microcontroller: https://www.amazon.com/dp/B08D5ZD528

CAN Transceiver (TJA1050): https://www.amazon.com/dp/B07W4VZ2F2

7" TFT Display (SSD1963): https://www.aliexpress.us/item/3256804550146211.html

### Connecting pinouts:

TFT to ESP32, defined in `libraries/TFT_eSPI/User_Setup.h`

Transceiver to ESP32, defined in `main/src/config.h`

Pushbutton to ESP32, defined in `main/src/config.h`

## Note on using different TFT

The GUI part of this project is driven solely by Bodmer's TFT_eSPI library. A pre-configured `User_Setup.h` for the library is included to mitigate configuration process if you have already chosen the same display.

If you are using a different TFT display than the one in this project, make sure it is on the list of compatible drivers, found under `/libraries/TFT_eSPI/TFT_Drivers` or it may not display properly.

Additionally, if you are changing TFT config settings (such as pinouts, driver selection, SPI or 8-bit parallel), it can be done in `/libraries/TFT_eSPI/User_Setup.h`. Once happy, make sure to actually select this file inside `/libraries/TFT_eSPI/User_Setup_Select.h`.
