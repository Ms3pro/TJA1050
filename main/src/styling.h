
/*
* For configuration of visual look of dashboard.
*/


#ifndef STYLING_H
#define STYLING_H

//----- Colors ----------------------------------------------------------------
#define COLOR_PRIMARY    TFT_ORANGE    // 
#define COLOR_SECONDARY  TFT_BLUE      //
#define COLOR_BORDER     TFT_WHITE     //
#define COLOR_MUTED      TFT_DARKGREY  // for displaying "off" elements (e.g. CEL off)
#define COLOR_BACKGROUND TFT_BLACK     //
#define COLOR_DANGER     TFT_RED       // redline, shift light, overheat, etc..

//----- Fonts -----------------------------------------------------------------
#define FONT_MAIN        4 // font sytle (digital values)
#define FONT_MAIN_SZ     2 // pixel upscale factor

#define FONT_SUBTEXT     4 // font sytle (subtext/labels)
#define FONT_SUBTEXT_SZ  2 // pixel upscale factor

#define FONT_HUGE        4 // font sytle (large elements, e.g. gear indicator)
#define FONT_HUGE_SZ     6 // pixel upscale factor

#endif // STYLING_H