// Widget.h


/*
* Abstract Parent Class
*/


#ifndef WIDGET_H
#define WIDGET_H

class Widget {
protected:

    TFT_eSPI* tft;

    int x; // x coord (top left)
    int y; // y coord (top left)
    int w; // width
    int h; // height

    Widget(int _x, int _y, int _w, int _h, TFT_eSPI* _tft) : x(_x), y(_y), w(_w), h(_h), tft(_tft) {}
	~Widget() {}
public:
    
    virtual void init() = 0;   // reset widget & internal vars 
    virtual int update() = 0;  // update widget & internal vars
};

#endif // WIDGET_H