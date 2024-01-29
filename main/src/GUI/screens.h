

/*
Properties related to switching and updating screens
*/

#ifndef SCREENS_H 
#define SCREENS_H

#include <TFT_eSPI.h>


//----- Public Defines --------------------------------------------------------
#define SCREEN_1 0
#define SCREEN_2 1

#define SCREEN_MAX SCREEN_2 // index of last screen


//----- Public Functions ------------------------------------------------------
int clearScreen();
int initScreen(int s);
int updateScreen(int s, uint32_t widgetID, uint16_t value);


#endif // SCREENS_H