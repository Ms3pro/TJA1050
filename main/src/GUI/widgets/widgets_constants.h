
#ifndef WIDGETS_CONST_H 
#define WIDGETS_CONST_H

#include <TFT_eSPI.h>

#include "../../config.h"
#include "../../styling.h"
#include "../../vehicle_constants.h"


//----- updateGear() Constants ------------------------------------------------

//strings for printing car gears
extern const char g[CAR_FORWARD_GEARS+2][2] = {"R", "N", "1", "2", "3", "4", "5", "6"};

#define g_x      (SCREEN_W / 2)     // x coord to print at
#define g_y      (2 * SCREEN_H / 3) // y coord to print at
#define g_td     MC_DATUM           // text datum (i.e. alignment mode) (4 = center on x,y)
#define g_f      FONT_HUGE          // font style
#define g_f_us   FONT_HUGE_SZ       // font upscale factor
#define g_c_pr   COLOR_PRIMARY      // color text (primary)
#define g_c_bg   COLOR_BACKGROUND   // color background




//----- updateTachometer() Constants ------------------------------------------

// x coord of redline along bar
extern const int r_x = int(SCREEN_W * (CAR_RPM_REDLINE / float(CAR_RPM_MAX))); 

#define  t_h        (SCREEN_H / 6)     // pixels tall
#define  t_os_y     (SCREEN_H / 12)    // offset from top of screen (y=0)

#define  t_c_pr     COLOR_PRIMARY      // color of bar
#define  t_c_bg     COLOR_BACKGROUND   // color behind bar
#define  t_c_rl     COLOR_DANGER       // redline color




#endif // WIDGETS_CONST_H