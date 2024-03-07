/*
TesterGUI class utilizes TranslateCAN class
to process, identify, and translate recieved CAN 
frames in order to update relevant display fields.
Class designed to verify-by-obervation all visual 
updates on all vital systems of dashboard project
*/


#ifndef TEST_GUI_H 
#define TEST_GUI_H

#include <Arduino.h>
#include <TFT_eSPI.h>
#include "driver/twai.h"
#include "TranslateCAN.h"

#define TXT_FONT     &FreeMono12pt7b // in TFT_eSPI
#define TXT_SIZE     1               // in TFT_eSPI
#define SCR_WIDTH    480             //
#define SCR_HEIGHT   320             //
#define SCREEN_COUNT 6               //

//----- TesterGUI Class ------------------------------------------------------

class TesterGUI {
private:

  //---- VARIABLES ------------------------------

  TFT_eSPI* _tft;  

  uint16_t curr_screen = 0;
  bool isCEL = false;
  bool isDisconnect = false;
  
  //---- HELPERS --------------------------------

  void formatDrawText(uint32_t clr, uint32_t clr_bg, uint8_t datum) {
    _tft->setTextColor(clr, clr_bg);
    _tft->setTextDatum(datum);
	  _tft->setTextSize(TXT_SIZE);
    _tft->setFreeFont(TXT_FONT);
  }

  void drawText(char* strn, int x=0, int y=0, uint32_t clr=TFT_WHITE, uint32_t clr_bg=TFT_BLACK, uint8_t datum=TL_DATUM) {
	  formatDrawText(clr, clr_bg, datum);
	  _tft->drawString(strn, x, y);
  }

  void drawText(float flt, int x=0, int y=0, uint32_t clr=TFT_WHITE,  uint32_t clr_bg=TFT_BLACK, uint8_t datum=TL_DATUM) {
    char temp[15];
    sprintf(temp, "%5.1f", flt); //FIXME hardcoded fieldwidth at 5. make modulatible
	  drawText(temp, x, y, clr, clr_bg, datum);
  }

  void drawText(uint16_t intNum, int x=0, int y=0, uint32_t clr=TFT_WHITE,  uint32_t clr_bg=TFT_BLACK, uint8_t datum=TL_DATUM) {
	  char temp[15];
    sprintf(temp, "%5d", intNum); //FIXME hardcoded fieldwidth at 5. make modulatible
    drawText(temp, x, y, clr, clr_bg, datum);
  }

public:

  TesterGUI(TFT_eSPI* tft) : _tft(tft) {}
	
  // init GUI setup
  void init() {
    
    // ----- background -----

    _tft->fillScreen(TFT_BLACK);

    // ---- labels -----

    drawText("RPM",      0, ((0 * SCR_HEIGHT) / 11));
    drawText("RPMGhost", 0, ((1 * SCR_HEIGHT) / 11));
    drawText("Gear",     0, ((2 * SCR_HEIGHT) / 11));
    drawText("Speed",    0, ((3 * SCR_HEIGHT) / 11));
    drawText("OilTemp",  0, ((4 * SCR_HEIGHT) / 11));
    drawText("OilPres",  0, ((5 * SCR_HEIGHT) / 11));
    drawText("CoolTemp", 0, ((6 * SCR_HEIGHT) / 11));
    drawText("FuelPres", 0, ((7 * SCR_HEIGHT) / 11));
    drawText("Fuel%",    0, ((8 * SCR_HEIGHT) / 11));
    drawText("BattVolt", 0, ((9 * SCR_HEIGHT) / 11));
    drawText("AFR",      0, ((10 * SCR_HEIGHT) / 11));

    drawText("Screen#:      ", SCR_WIDTH, (( 2 * SCR_HEIGHT) / 11), TFT_WHITE, TFT_BLACK, TR_DATUM);

    // ----- fields -----

    clear(); // clears all value fields
    

  }

  // clear all updatable GUI fields
  void clear() {
    if (curr_screen % 2) return; // do nothing if not primary screen

    // curr_screen readout
    drawText(curr_screen, SCR_WIDTH, (( 2 * SCR_HEIGHT) / 11), TFT_WHITE, TFT_BLACK, TR_DATUM); 

    //indicators
    drawCEL(isCEL);
    drawDisconnect(isDisconnect);

    // CAN readouts
    drawText("      ",  (SCR_WIDTH / 3),  ((0  * SCR_HEIGHT) / 11)); //FIXME hardcoded fieldwidth at 5. make modulatible
    drawText("      ",  (SCR_WIDTH / 3),  ((1  * SCR_HEIGHT) / 11));
    drawText("      ",  (SCR_WIDTH / 3),  ((2  * SCR_HEIGHT) / 11));
    drawText("      ",  (SCR_WIDTH / 3),  ((3  * SCR_HEIGHT) / 11));
    drawText("      ",  (SCR_WIDTH / 3),  ((4  * SCR_HEIGHT) / 11));
    drawText("      ",  (SCR_WIDTH / 3),  ((5  * SCR_HEIGHT) / 11));
    drawText("      ",  (SCR_WIDTH / 3),  ((6  * SCR_HEIGHT) / 11));
    drawText("      ",  (SCR_WIDTH / 3),  ((7  * SCR_HEIGHT) / 11));
    drawText("      ",  (SCR_WIDTH / 3),  ((8  * SCR_HEIGHT) / 11));
    drawText("      ",  (SCR_WIDTH / 3),  ((9  * SCR_HEIGHT) / 11));
    drawText("      ",  (SCR_WIDTH / 3),  ((10 * SCR_HEIGHT) / 11));
  }

  // updates curr_screen display field & variable
  // also demonstrates a potential screen switch
  void nextScreen() {
    curr_screen = (curr_screen + 1) % SCREEN_COUNT; //increments and cycles back to 0 (1st screen) if exceeds max

    if (curr_screen % 2) { // toggle to demo second screen

      _tft->fillScreen(TFT_BLACK);
      drawText("      <- Screen#");
      drawText(curr_screen);

      drawCEL(isCEL);
      drawDisconnect(isDisconnect);
    }
    else {  // toggle to main tester screen

      init();
    }
    
  }

  // update CEL display field (Check Engine Light), regardless of curr_screen
  void drawCEL(bool en) {
    isCEL = en;
    // if not en, draw blacked out, else show as color
    uint32_t clr    = (en) ? TFT_ORANGE : TFT_BLACK;
    drawText("CEL [!]", SCR_WIDTH, 0, clr, TFT_BLACK, TR_DATUM);
  }
  
  // update Disconnect display field, regardless of curr_screen
  void drawDisconnect(bool en) {
    isDisconnect = en;
    // if not en, draw blacked out, else show as color
    uint32_t clr    = (en) ? TFT_RED : TFT_BLACK;
    drawText("DC  [!]", SCR_WIDTH, SCR_HEIGHT/11, clr, TFT_BLACK, TR_DATUM);
  }

  /* 
  * Process, identify, and translate recieved CAN frame 
  * (using TranslateCAN class) to update any relevant display fields
  */ 
  void update(twai_message_t c) {
    
    if (curr_screen % 2) return; // do nothing if not primary screen

    // get CAN ID
    uint32_t id = c.identifier;

    //get CAN data
    uint8_t bytes[8] = {0,0,0,0,0,0,0,0};
    for (int i = 0; i < c.data_length_code; i++) {
      bytes[i] = c.data[i];
    }

    //identify, translate, update display
    //FIXME implement red text if over-range/under-range per warning_limits.h
    if (id == CAN_RPM)         { drawText(TranslateCAN::rpm        (bytes),  (SCR_WIDTH / 3),  ((0  * SCR_HEIGHT) / 11)); 
                                 drawText("FIXME"                         ,  (SCR_WIDTH / 3),  ((1  * SCR_HEIGHT) / 11)); }
    if (id == CAN_GEAR)        { drawText(TranslateCAN::gear       (bytes),  (SCR_WIDTH / 3),  ((2  * SCR_HEIGHT) / 11)); }
    if (id == CAN_SPEED)       { drawText(TranslateCAN::speed      (bytes),  (SCR_WIDTH / 3),  ((3  * SCR_HEIGHT) / 11)); }
    if (id == CAN_OILTEMP)     { drawText(TranslateCAN::oilTemp    (bytes),  (SCR_WIDTH / 3),  ((4  * SCR_HEIGHT) / 11)); }
    if (id == CAN_OILPRESSURE) { drawText(TranslateCAN::oilPressure(bytes),  (SCR_WIDTH / 3),  ((5  * SCR_HEIGHT) / 11)); }
    if (id == CAN_COOLANTTEMP) { drawText(TranslateCAN::coolantTemp(bytes),  (SCR_WIDTH / 3),  ((6  * SCR_HEIGHT) / 11)); }
    if (id == CAN_FUELPSI)     { drawText(TranslateCAN::fuelPSI    (bytes),  (SCR_WIDTH / 3),  ((7  * SCR_HEIGHT) / 11)); }
    if (id == CAN_FUELPERCENT) { drawText(TranslateCAN::fuelPercent(bytes),  (SCR_WIDTH / 3),  ((8  * SCR_HEIGHT) / 11)); }
    if (id == CAN_BATTERYVOLT) { drawText(TranslateCAN::batteryVolt(bytes),  (SCR_WIDTH / 3),  ((9  * SCR_HEIGHT) / 11)); }
    if (id == CAN_AFR)         { drawText(TranslateCAN::afr        (bytes),  (SCR_WIDTH / 3),  ((10 * SCR_HEIGHT) / 11)); }
  }
	
};


#endif // TEST_GUI_H