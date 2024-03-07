# Get started

1. Install Arduino IDE (version 2.x is more straightforward)
2. Open the `.ino` file in Arduino IDE
3. Install all dependencies (see "Code Dependencies" below) inside Arduino IDE. 
4. Place the provided `User_Setup.h` in `Documents\Arduino\libraries\TFT_eSPI` (should overwrite).
5. Connect ESP32, select its COM port, and set as "ESP32 Dev Module"
6. Click upload.
7. Output tab displays "Connecting....", hold BOOT button on ESP32 until upload completes.
8. Reboot the device.

# Building the Prototype Dashboard

### Parts Used:

[ESP32 Microcontroller](https://www.amazon.com/dp/B08D5ZD528)

[CAN Transceiver (TJA1050)](https://www.amazon.com/dp/B07W4VZ2F2)

[TFT display (ILI9486)](https://www.amazon.com/gp/product/B0BJDTL9J3) 

### Connecting pinouts:

[See provided image for pinouts, as well as UserSetup.h for TFT pinout]

# Code Dependencies:

### Arduino Drivers:

[ESP32 by Espressif Systems](https://github.com/espressif/arduino-esp32)

### Windows Drivers: (if ESP32 not recognized)

[VCP drivers](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads)

### Libraries:

[TFT_eSPI by Bodmer (v2.5.34)](https://www.arduino.cc/reference/en/libraries/tft_espi/)

# Reconfiguration for new vehicle:

### CAN codes:

Please read `TranslateCAN.h` file

### Vehicle constants:

Please read `warning_limits.h` file

### Display Compatibility

The GUI part of this project is driven by Bodmer's TFT_eSPI library. If you have installed it for your Arduino IDE already, you may look through `Documents\Arduino\libraries\TFT_eSPI\TFT_Drivers` If you are changing TFT config (pinouts, driver selection, etc), it can be done in `libraries\TFT_eSPI\User_Setup.h`. Beforehand, make sure your intended display is even on the list of compatible drivers, found under `/libraries/TFT_eSPI/TFT_Drivers`.
