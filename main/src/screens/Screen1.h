// Screen1.h

#ifndef SCREEN1_H
#define SCREEN1_H


#include "../config.h"
#include "../styling.h"
#include "../vehicle_constants.h"
#include "../can_protocol.h"

#include "widgets/LimiterBar.h"
#include "widgets/TextLarge.h"

/*
* NOTE: Assumes fullscreen on TFT.
* Dimensions defined in "src/config.h"
*/


class Screen1 {
private:

  //* TFT reference */
  TFT_eSPI* tft;          

  /* Widgets */
  LimiterBar tachometer;
  TextLarge  gear; 

public:
  // Constructor
  Screen1(TFT_eSPI* _tft) : tft(_tft), 
                            tachometer(_tft, 0, (SCREEN_H / 12), SCREEN_W, (SCREEN_H / 6), 0, CAR_RPM_MAX, CAR_RPM_REDLINE),
							gear(_tft, (SCREEN_W / 2), (2 * SCREEN_H / 3), MC_DATUM)
  {}
	
  // Destructor
  ~Screen1() {}

  // Init all widgets
  void init() {
	  
    /*clear background*/
    this->tft->fillScreen(COLOR_BACKGROUND);

    /*init() all widgets*/
    this->tachometer.init();
	this->gear.init();
  }

  //-------------- Widget Updaters --------------

  void updateTachometer(uint8_t* bytearr) {
	  
	/* translate bytes to correct datatype*/
    uint16_t val = TranslateCAN::rpm(bytearr);
	
	/* update widget */
	this->tachometer.update(val);
  }
  
  void updateGear(uint8_t* bytearr) {
	  
	/* translate bytes to correct datatype*/
    uint16_t v = TranslateCAN::gear(bytearr);
	
	/* update widget */
	char c[2]; //FIXME -logic is entangled. move to TranslateCAN
	if      (v == 0)         strcpy(c, "R");
	else if (v == 1)         strcpy(c, "N");
	else if (v > 1 && v < 8) sprintf(c, "%d", v-1);
	
	this->gear.update(c);
	
  }
  
};

#endif // SCREEN1_H