
#ifndef WIDGETS_H 
#define WIDGETS_H


#include <Arduino.h>
#include <TFT_eSPI.h>


extern TFT_eSPI tft;

//----TEST FUNCTOINS----------------//FIXME
int clearTFT();
int testingLabel(const char* text);


//----- Gear Indicator --------------------------------------------------------

//reset gear ui & associated globals
int initGear();

//0: "R",
//1: "N",
//2: "1",
//3: "2",
//4: "3",
//5: "4",
//6: "5",
//7: "6"  
int updateGear(int gear);



//----- RPM Gauge -------------------------------------------------------------

//reset tachometer ui & associated globals
int initTachometer();

//updates tachometer.
int updateTachometer(int rpm);



#endif // WIDGETS_H