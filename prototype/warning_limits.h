
/*
* Under-range and over-range limits on values monitored by dashboard.
* Indicated by readout value turning red on dashboard.
*
* You may edit this file to reflect the range limits 
* for the values your vehicle operates within. 
*/

#ifndef WARNING_LIMITS_H 
#define WARNING_LIMITS_H


//----- DEFINES ---------------------------------------------------------------

#define LIMIT_RPM_REDLINE       2500 //int

#define LIMIT_HIGH_OILTEMP      100  //int
#define LIMIT_LOW_OILTEMP       0    //int

#define LIMIT_HIGH_OILPRESSURE  100  //int
#define LIMIT_LOW_OILPRESSURE   0    //int

#define LIMIT_HIGH_COOLANTTEMP  100  //int
#define LIMIT_LOW_COOLANTTEMP   0    //int

#define LIMIT_HIGH_FUELPSI      100  //int
#define LIMIT_LOW_FUELPSI       0    //int

#define LIMIT_LOW_FUELPERCENT   10   //int

#define LIMIT_HIGH_BATTERYVOLT  14.0 //float
#define LIMIT_LOW_BATTERYVOLT   12.0 //float

#define LIMIT_HIGH_AFR          15.0 //float
#define LIMIT_LOW_AFR           11.0 //float

//----- END OF DEFINES --------------------------------------------------------

#endif //WARNING_LIMITS_H