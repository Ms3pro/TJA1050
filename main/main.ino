
//----- Includes --------------------------------------------------------------

#include <TFT_eSPI.h>
#include <CAN.h>

#include "src/config.h"
#include "src/styling.h"
#include "src/can_protocol.h"
#include "src/screens/Screens.h"

//----- Globals ---------------------------------------------------------------

TFT_eSPI tft = TFT_eSPI();

Screen1 screen1 = Screen1(&tft);
Screen2 screen2 = Screen2(&tft);

int curr_screen = SCREEN_1;

bool flagNewData = false;

long id;          // CAN id
uint8_t bytes[8]; // CAN data
uint8_t len = 0;  // CAN length (of data)

int pbLast = LOW;  // pushbutton last state
int pbCurrent;     // pushbutton current state



//----- SETUP -----------------------------------------------------------------

void setup() {

  // initialize serial
  Serial.begin(115200);

  //initialize display
  tft.init();
  tft.setRotation(3); // landscape orientation
  tft.fillScreen(COLOR_BACKGROUND);

  //initialize CAN
  CAN.setPins(CAN_RX, CAN_TX);
  if (!CAN.begin(500E3)) {
    TextLarge(&tft, SCREEN_W/2, SCREEN_H/2, 4).update("CAN fail", COLOR_DANGER);
    while (1); // wait for reset
  }

  // initialize push button
  pinMode(PB_PIN, INPUT_PULLUP);

  // initialize GUI
  curr_screen = 0;
  screen1.init();
}

//----- EVENTS ----------------------------------------------------------------

void eventScreenSwitch() {

  pbCurrent = digitalRead(PB_PIN); 
  // check for button state change
  if (pbLast == HIGH && pbCurrent == LOW) {
    
    // cycle next screen
    curr_screen++;
    if (curr_screen > MAX_SCREEN) curr_screen = 0;
    
    // init new screen
    if      (curr_screen == SCREEN_1) screen1.init();
    else if (curr_screen == SCREEN_2) screen2.init();
  }
  pbLast = pbCurrent;

}

void eventGetCAN() {

  int len = CAN.parsePacket();
  if (len) {
    
    // get ID
    id = CAN.packetId();
    
    // get bytes
    int i = 0;
    while (CAN.available() && (i < len)) {
      bytes[i] = (char)CAN.read();
      i++;
    }

    // flag CAN parser event
    flagNewData = true;
  }

}

void eventUpdateScreen() {

  if (flagNewData) {
	  flagNewData = false;

	  if (curr_screen == SCREEN_1) {

		  if      (id == CAN_RPM)  screen1.updateTachometer(bytes); 
		  else if (id == CAN_GEAR) screen1.updateGear      (bytes);

    }
    else if (curr_screen == SCREEN_2) {
      /*FIXME -do something*/
    }

  }

}

//----- MAIN ------------------------------------------------------------------

void loop() {

  //------- Screen Switcher Event -------
  eventScreenSwitch();

  //------- CAN Getter Event -------
  eventGetCAN();
  

  //------- CEL Checker event -------  //FIXME -add
  // if new data, if concerns CEL light, trigger CEL flag


  //------- Updater Event ------- 
  eventUpdateScreen();
  
  //------- Heartbeat Event -------  //FIXME -add
  // if CAN watchdog timeout, display error/disconnect screen


  //------- Force-clear Event -------  //FIXME -add
  //if time interval X reached & system alive, force-reset widgets
  
}







