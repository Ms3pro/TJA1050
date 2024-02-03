// _TemplateObject_.h

#ifndef TEMPLATEOBJ_H
#define TEMPLATEOBJ_H

#include "Widget.h"

class TemplateObject : public Widget {
private:
    
    // style constants

    // object constants (set once on instantiation)

    // internal vars

public:
    // constructor
	TemplateObject(TFT_eSPI* tft, int x, int y, int w, int h) : Widget(x, y, w, h, tft) {}
	
	//destructor
	~TemplateObject() {}

    /*override superclass method*/
    void init() {
		//reset internal vars & widget here
	}
    
    /*override superclass method (unused)*/
    int update() { return -1; }

    /*overloaded w parameters*/
    int update(/*parameters here*/) 
	{
	    //update widget here
        return 0;
    }

};

#endif //TEMPLATEOBJ_H