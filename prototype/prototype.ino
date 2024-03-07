
#include "CAN.h"
#include "TranslateCAN.h"
#include "TesterGUI.h"

#define CAN_RX 32    // ESP32 pin for CAN tranciever RX
#define CAN_TX 33    // ESP32 pin for CAN tranciever TX
#define PB_PIN 5     // ESP32 pin for Push Button
#define REFRESH_INTERVAL 2000

CAN can = CAN();
TFT_eSPI tft = TFT_eSPI();
TesterGUI gui = TesterGUI(&tft);

twai_message_t can_frame;
unsigned long last_forceclear = 0;
unsigned long last_CELupdate = 0;
bool flagDisconnect = false;
bool flagCEL = false;

int pbLast = LOW;  // pushbutton last state
int pbCurrent;     // pushbutton current state

void setup() {

    //initialize serial
    Serial.begin(115200);
    while(!Serial){};

    //initialize CAN
    if (!can.init(CAN_RX, CAN_TX, 500)) {
      Serial.println("CAN init fail");
      while(1);
    }

    //initialize tft
    tft.init();
    tft.setRotation(1); // landscape is 1 or 3

    //initialize TesterGUI
    gui.init();

    // initialize push button
    pinMode(PB_PIN, INPUT_PULLUP);

    Serial.println("digital-dashboard-PROTOTYPE");
}


void EVENT_HEARTBEAT() {
  
  bool conn = can.isConnected();

  // If disconnected, but event never done, do event once.
  if (!flagDisconnect && !conn) {
    flagDisconnect = true;
    gui.drawDisconnect(true);
  }
  // If became connected reset flag, reset display
  else if (flagDisconnect && conn) {
    flagDisconnect = false;
    gui.drawDisconnect(false);
  }

}


void EVENT_SWITCH_DISPLAY() {

  pbCurrent = digitalRead(PB_PIN); 
  // check for button state change
  if (pbLast == HIGH && pbCurrent == LOW) {
    
    gui.nextScreen();
  }
  pbLast = pbCurrent;

}

void EVENT_CEL() {
  //FIXME remove placeholder code (toggles it every interval) for real code
  if (millis() - last_CELupdate >= REFRESH_INTERVAL) {
    flagCEL = !flagCEL;
    gui.drawCEL(flagCEL);
    last_CELupdate = millis();
  }
}

void EVENT_FORCE_CLEAR() {

  if (millis() - last_forceclear >= REFRESH_INTERVAL) {
    gui.clear();
    last_forceclear = millis();
  }
}

void loop() {

  //Check display switch
  EVENT_SWITCH_DISPLAY();

  //Check for CAN
  if (can.avaliable() && can.get(&can_frame)) {
    gui.update(can_frame);
  }

  //Check connnection
  EVENT_HEARTBEAT();

  //Check CEL
  EVENT_CEL();

  //Force clear readouts
  EVENT_FORCE_CLEAR();

}

// END FILE
