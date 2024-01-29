
/*
* NOTE:
* This file simply utilizes tools and resources 
* from TFT_eSPI library. Certain customizations 
* or reconfiguration may or may not be within TFT_eSPI lib. 
*/


#include "widgets.h"
#include "../../config.h"
#include "widgets_constants.h"
#include "widgets_globals.h"
#include "../../vehicle_constants.h"

int clearTFT() {
	
	tft.fillScreen(COLOR_BACKGROUND);
	return 0;
}

//(TESTER FUNCTION)
int testingLabel(const char* text) {

  tft.setTextDatum(MC_DATUM); 
  tft.setTextColor(COLOR_MUTED, COLOR_BACKGROUND);
  tft.setTextSize(FONT_MAIN_SZ);
  tft.drawString(text, (SCREEN_W / 2), (SCREEN_H / 2), FONT_MAIN);

  return 0;
  
}

int initGear() {
  g_gear = 1; //"N"
  tft.setTextDatum(g_td); 
  tft.setTextColor(g_c_pr, g_c_bg);
  tft.setTextSize(g_f_us);
  tft.drawString("--", g_x, g_y, g_f);
  return 0;
}


int updateGear(int gear) {

  if ((gear < 0) || (gear > CAR_FORWARD_GEARS+1)) return -1;
  
  //else...
  g_gear = gear;

  tft.setTextDatum(g_td); 
  tft.setTextColor(g_c_pr, g_c_bg);
  tft.setTextSize(g_f_us);
  tft.drawString(g[g_gear], g_x, g_y, g_f);

  return 0;
  
}


int initTachometer() {
  l_x = 0;
  clr = t_c_pr;
  updateTachometer(0);
  return 0;
}


int updateTachometer(int rpm) {

  if ((rpm > CAR_RPM_MAX) || (rpm < 0)) return -1;
  //else....


  // current x (where edge of bar will move to)
  int c_x = int(SCREEN_W * (rpm / float(CAR_RPM_MAX)));    


  // decrease
  if (c_x < l_x) {

    // fill end with black 
    // (faster to subtract using black than clear+redraw bar)
    tft.fillRect(c_x, t_os_y, l_x-c_x, t_h, t_c_bg); 

    // crossed over redline
    if ((c_x <= r_x) && (l_x > r_x)) {
      clr = t_c_pr; // change color to primary
    }

  }
  // increased, cross over redline
  else if ((l_x <= r_x) && (c_x > r_x)) { 

    tft.fillRect(l_x, t_os_y, r_x-l_x, t_h, clr); // draw colored side of bar
    clr = t_c_rl;                                 // change color to redline
    tft.fillRect(r_x, t_os_y, c_x-r_x, t_h, clr); // draw redline side of bar

  }
  // increased (no crossover)
  else if (l_x < c_x) {
    
    tft.fillRect(l_x, t_os_y, c_x-l_x, t_h, clr); // append segment to end
  }
  

  l_x = c_x;

  return 1;

}