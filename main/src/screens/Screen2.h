// Screen2.h

#ifndef SCREEN2_H
#define SCREEN2_H


#include "../config.h"
#include "../styling.h"
#include "../can_protocol.h"

#include "widgets/TextLarge.h"

/*
* NOTE: Assumes fullscreen on TFT.
* Dimensions defined in "src/config.h"
*/


class Screen2 {
private:

  //* TFT reference */
  TFT_eSPI* tft;          

  /* Widgets */
  TextLarge  test; //FIXME -temporary tester. make this class

public:
  // Constructor
  Screen2(TFT_eSPI* _tft) : tft(_tft), 
							test(_tft, (SCREEN_W / 2), (SCREEN_H / 2), MC_DATUM)
  {}
	
  // Destructor
  ~Screen2() {}

  // Init all widgets
  void init() {
	  
    /*clear background*/
    this->tft->fillScreen(COLOR_BACKGROUND);

    /*init() all widgets*/
	this->test.update("Screen2"); //init with text "Screen2"
  }

  //-------------- Widget Updaters --------------

  
};

#endif // SCREEN2_H