// TextLarge.h

#ifndef TEXTLARGE_H
#define TEXTLARGE_H

#include "Widget.h"
#include "../../styling.h"

//FIXME -could make more generic (generic sizing, auto-associate corrent font)
class TextLarge : public Widget {
private:
    
    // style constants
	static const uint32_t clr_pr    = COLOR_PRIMARY;     // primary color
    static const uint32_t clr_bg    = COLOR_BACKGROUND;  // background color
    static const int      font      = FONT_HUGE;         // font style
    static const int      font_size = FONT_HUGE_SZ;      // font upscale factor
	
	
	// object constants (set once on instantiation)
	int datum;    // alignment-mode about it's x, y

public:
    // constructor
	TextLarge(TFT_eSPI* tft, int x, int y, int text_datum) : Widget(x, y, NULL, NULL, tft), 
	                                                         datum(text_datum) 
															 {}
															 
	//destructor
	~TextLarge() {}

    /*override superclass method*/
    void init() { 
		update("--"); 
	}
    
    /*override superclass method (unused)*/
    int update() { return -1; }

    /*overloaded w parameters*/
    int update(const char* text) 
	{
	  update(text, this->clr_pr);
      return 0;
    }
	
    /*overloaded w parameters*/
    int update(const char* text, uint32_t color) 
	{
	  this->tft->setTextDatum(this->datum); 
	  this->tft->setTextColor(color, this->clr_bg);
	  this->tft->setTextSize(this->font_size);
	  this->tft->drawString(text, this->x, this->y, this->font);
      return 0;
    }

};

#endif // TEXTLARGE_H