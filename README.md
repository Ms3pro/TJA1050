# digital-dashboard
For ESP32 based CAN bus powered dashboard. Originally developed for Wildcat Formula Racing (University of Arizona) FSAE racecar.

# Get started

1. Install Arduino IDE (version 2.x is more straightforward)
2. Open the `.ino` file in Arduino IDE
3. Go to File > Preferences and set Sketchbook location to the path of this project (location of README)
4. Install all dependencies (see "Code Dependencies" below) inside Arduino IDE. 
5. Drag the provided `User_Setup.h` file into `libraries\TFT_eSPI`. (should overwrite)
6. Connect ESP32, select its COM port, and set as "ESP32 Dev Module"
7. Click upload.
8. Output tab displays "Connecting....", hold BOOT button on ESP32 until upload completes.
9. Reboot the device.

# Building the Dashboard Unit

### Parts Used:

[ESP32 Microcontroller](https://www.amazon.com/dp/B08D5ZD528)

[CAN Transceiver (TJA1050)](https://www.amazon.com/dp/B07W4VZ2F2)

[7" TFT Display (SSD1963)](https://www.aliexpress.us/item/3256804550146211.html)

### Connecting pinouts:

TFT to ESP32, defined in the provided `User_Setup.h`

Transceiver to ESP32, defined in `main/src/config.h`

Pushbutton to ESP32, defined in `main/src/config.h`

# Code Dependencies:

### Drivers:

[ESP32 by Espressif Systems](https://github.com/espressif/arduino-esp32)

### Libraries:

[TFT_eSPI by Bodmer (v2.5.34)](https://www.arduino.cc/reference/en/libraries/tft_espi/)

[CAN by Sandeep Mistry (v0.3.1)](https://www.arduino.cc/reference/en/libraries/can/)

# Reconfigurations:

### CAN codes:

The code has been setup for the current version (as of Spring 2024) of the Wildcat Formula Racing racecar. For any other vehicle applications, follow reconfiguration steps inside `main\src\can_protocol.h`. 

### Vehicle constants:

Constants found in `main\src\vehicle_constants.h` to reflect your car's redline, RPM range, etc.

### Different TFT display / pinouts

The GUI part of this project is driven by Bodmer's TFT_eSPI library. A pre-configured `User_Setup.h` for the library is included to mitigate configuration for SSD1963. If you are changing TFT config (pinouts, driver selection, etc), it can be done in `libraries\TFT_eSPI\User_Setup.h`. Beforehand, make sure your intended display is even on the list of compatible drivers, found under `/libraries/TFT_eSPI/TFT_Drivers`.

# Common Troubleshooting

### Not detecting ESP32 in COM ports

You may try installing [VCP drivers](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads) on your PC first
