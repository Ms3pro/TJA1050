
#include <Arduino.h>
#include <TFT_eSPI.h>

#include "screens.h"
#include "widgets/widgets.h"
#include "../CAN/can_protocol.h"


//----- General Functions -----------------------------------------------------

int clearScreen() {
	clearTFT();
	return 0;
}


//----- Initializer Functions -------------------------------------------------

int initScreen1() {

  clearScreen();
  initGear();
  initTachometer();

  return 0;
}

int initScreen2() {

  //FIXME create
  clearScreen();
  testingLabel("Screen2");
  return 0;
}

int initScreen(int s) {

  if      (s == SCREEN_1) initScreen1();
  else if (s == SCREEN_2) initScreen2();
  else                    return -1;

  return 0;
}


//----- Updater Functions -----------------------------------------------------

int updateScreen1(uint32_t widgetID, uint16_t value) {
	if      (widgetID == CAN_RPM)  updateTachometer(value);
	else if (widgetID == CAN_GEAR) updateGear(value);
	else return -1;
	return 0;
}


int updateScreen2(uint32_t widgetID, uint16_t value) {
	return -1;
	//FIXME create
	return 0;
}



int updateScreen(int s, uint32_t widgetID, uint16_t value) {
	
	if      (s == SCREEN_1) updateScreen1(widgetID, value);
	else if (s == SCREEN_2) updateScreen2(widgetID, value);
	else                    return -1;
  
	return 0;
}