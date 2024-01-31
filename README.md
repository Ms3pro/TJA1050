# digital-dashboard
Repository for an ESP32 based CAN bus powered dashboard. Originally developed for Wildcat Formula Racing (University of Arizona) FSAE racecar.

## Get started

1. Install Arduino IDE (version 2.x is more straightforward)
2. Open the `.ino` file in Arduino IDE
3. Go to File > Preferences and set Sketchbook location to the path of this project (To where this README is located)
4. In Arduino IDE, install drivers for ESP32 by Espressif Systems
5. In Arduino IDE, install library TFT_eSPI by Bodmer (v2.5.34)
6. In Arduino IDE, install library CAN by Sandeep Mistry (v0.3.1)
7. If using different display, [see reconfiguration steps](https://github.com/Sneupi/digital-dashboard/edit/main/README.md#Configuring-different-TFT-display)
8. Move the `"User_Setup.h` file into `libraries\TFT_eSPI` (should overwrite existing file).
9. Plug ESP32 to computer. If not detected, you may need to install [VCP drivers](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads) on your PC first.
10. In Arduino IDE, select it's COM port and set as "ESP32 Dev Module"
11. Upload project... let it compile
12. Once Output displays "Connecting....." hold the BOOT button on the ESP32
13. Wait for the upload to complete before releasing BOOT button
14. Reboot the device (using EN button) and it should be working

## Building the Dashboard Unit

### Parts Used:

[ESP32 Microcontroller](https://www.amazon.com/dp/B08D5ZD528)

[CAN Transceiver (TJA1050)](https://www.amazon.com/dp/B07W4VZ2F2)

[7" TFT Display (SSD1963)](https://www.aliexpress.us/item/3256804550146211.html)

### Connecting pinouts:

TFT to ESP32, defined in the provided `User_Setup.h`

Transceiver to ESP32, defined in `main/src/config.h`

Pushbutton to ESP32, defined in `main/src/config.h`

# Reconfiguring CAN codes:

The code has been setup for the current version (as of Spring 2024) of the Wildcat Formula Racing racecar. For any other vehicle applications, you must reconfigure the `can_protocol.h` and `can_protocol.cpp` files (found in `main\src\CAN`) otherwise the dashboard will not read the correct CAN frames or know how to translate them into meaningful data. 

# Reconfiguring vehicle constants:

Constants found in `main\src\vehicle_constants.h` to reflect your car's redline, RPM range, etc.

# Configuring different TFT display

The GUI part of this project is driven by Bodmer's TFT_eSPI library. A pre-configured `User_Setup.h` for the library is included to mitigate configuration process if you have already chosen the same display. If you are changing TFT config settings (such as pinouts, driver selection, SPI or 8-bit parallel), it can be done here.

If you are using a different TFT display than the one in this project, make sure it is on the list of compatible drivers, found under `/libraries/TFT_eSPI/TFT_Drivers` or it may not display properly.
