
//----- Includes --------------------------------------------------------------

#include <SPI.h>
#include <TFT_eSPI.h>
#include <CAN.h>

#include "src/config.h"
#include "src/styling.h"
#include "src/GUI/screens.h"
#include "src/CAN/can_protocol.h"


//----- Globals ---------------------------------------------------------------

TFT_eSPI tft = TFT_eSPI();

bool CEL            = false;  // set by (CAN) parse event,  read by updater event,                    reset never (i.e until reboot)
bool flagNewData    = false;  // set by CAN event,          read by (CAN) parse event,                reset by loop()
bool flagPrintData  = false;  // set by (CAN) parse event,  read by updater event,                    reset by loop()
int  curr_screen    = 0;      // set by button interrupt,   read by screen switcher & updater events, cycled by button interrupt

long id;          // CAN id
uint8_t bytes[8]; // CAN data
uint8_t len = 0;  // CAN length (of data)

uint16_t decodedBytes; // CAN data decoded

int pbLast = LOW;  // pushbutton last state
int pbCurrent;     // pushbutton current state


//----- SETUP -----------------------------------------------------------------

void setup() {

  // initialize serial
  Serial.begin(115200);

  //initialize display
  tft.init();
  tft.setRotation(3); // landscape orientation
  clearScreen();

  //initialize CAN
  CAN.setPins(CAN_RX, CAN_TX);
  if (!CAN.begin(500E3)) {
    tft.setTextDatum(MC_DATUM); 
    tft.setTextSize(FONT_MAIN_SZ);
    tft.setTextColor(COLOR_DANGER, COLOR_BACKGROUND);
    tft.drawString("[!] CAN Fail", (SCREEN_W / 2), (SCREEN_H / 2), FONT_MAIN);
    while (1); 
  }

  // initialize push button
  pinMode(PB_PIN, INPUT_PULLUP);

  // initialize GUI
  initScreen(curr_screen);
}



//----- MAIN ------------------------------------------------------------------

void loop() {


  //------- Screen Switcher Event -------
  pbCurrent = digitalRead(PB_PIN); 
  // check for button state change
  if (pbLast == HIGH && pbCurrent == LOW) {
    // cycle next screen
    curr_screen++;
    if (curr_screen > SCREEN_MAX) curr_screen = 0;
    // init new screen
    initScreen(curr_screen);
  }
  pbLast = pbCurrent;

  
  //------- CAN Getter Event -------
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
  
  
  //FIXME remove (test code)
  if (flagNewData) {
    flagNewData = false;
    decodedBytes = translateBytes(id, bytes);
    flagPrintData = true;
  }
  /*
  //------- CAN Parse Event -------
  //FIXME: add
  // check if data concerns CEL light
  //    flag CEL light
  // check data is for current screen
  //    translate bytes to printable form
  //    flag updater event (using printData)
  */


  //------- Screen Updater Event -------
  if (flagPrintData) {
    flagPrintData = false;
    updateScreen(curr_screen, id, decodedBytes);
  }
  
  
}







