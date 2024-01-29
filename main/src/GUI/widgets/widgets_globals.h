
/*
* Variables that are frequently used & dynamically changed in runtime
*/

#ifndef WIDGETS_GLOB_H 
#define WIDGETS_GLOB_H



//----- updateGear() Global Variables -----------------------------------------

extern int g_gear = 1; //"N"



//----- updateTachometer() Global Variables -----------------------------------

// last x coord (where edge of bar is)
extern int       l_x = 0;
// color used during bar-increase events (for segment-to-be-drawn)
extern uint32_t  clr = t_c_pr;



#endif // WIDGETS_GLOB_H