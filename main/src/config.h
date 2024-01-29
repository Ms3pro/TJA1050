
/*
* NOTE:
* For any reconfiguration related to 
* changed TFT pinouts or different display unit,
* this must be modified in "User_Setup.h" file 
* inside TFT_eSPI library. ALSO, if you do create 
* your own setup, ensure that "User_Setup.h" 
* is chosen in "User_Setup_Select.h".
*/

#ifndef CONFIG_H
#define CONFIG_H

//----- CAN Transceiver Pins --------------------------------------------------

#define CAN_RX 18    // ESP32 pin for CAN tranciever RX
#define CAN_TX 19    // ESP32 pin for CAN tranciever TX

//----- Push Button Pins -----------------------------------------------------------
#define PB_PIN 5     // ESP32 pin for Push Button

//----- Display Size ----------------------------------------------------------

#define SCREEN_W 800 //
#define SCREEN_H 480 //

#endif // CONFIG_H