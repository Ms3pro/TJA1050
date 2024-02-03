// _TemplateScreen_.h

#ifndef TEMPLATESCREEN_H
#define TEMPLATESCREEN_H


#include "../config.h"
#include "../styling.h"
#include "../can_protocol.h"

class TemplateScreen {
private:

  //* TFT reference */
  TFT_eSPI* tft;          

  /* Widgets */
  

public:
  // Constructor
  TemplateScreen(TFT_eSPI* _tft) : tft(_tft) {}
	
  // Destructor
  ~TemplateScreen() {}

  // Init all widgets
  void init() {
	  
    /*clear background*/
    this->tft->fillScreen(COLOR_BACKGROUND);

    /*init() all widgets*/
  }

  //-------------- Widget Updaters --------------
  
  /*
  void updateSOMEWIDGET(uint8_t* bytearr) {
	  
	//translate bytes to correct datatype
	
	//update widget using translated value
  }
  */
};

#endif // TEMPLATESCREEN_H