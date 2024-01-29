/*
* IMPORTANT:
* 
* List of all CAN IDs the dashboard uses to filter, translate, and display CAN bus data.
* This file MUST BE EDITED to correspond to your vehicle's CAN bus IDs otherwise 
* it may not be reading your vehicle properly.
* 
* Additionally, the functions used to translate values from the CAN byte arrays
* MUST BE EDITED in can_protocol.cpp otherwise it cannot properly translate to meaningful data.
* (One way of doing it fast could be bit masking)
*/


#ifndef CAN_SETUP_H 
#define CAN_SETUP_H


//----- Defines ---------------------------------------------------------------
#define CAN_RPM           0x01
#define CAN_GEAR          0x02
#define CAN_SPEED         0x03
#define CAN_OILTEMP       0x04
#define CAN_OILPRESSURE   0x05
#define CAN_COOLANTTEMP   0x06
#define CAN_FUELPSI       0x07
#define CAN_FUELPERCENT   0x08
#define CAN_BATTERYVOLT   0x09

//FIXME add CEL codes


//----- Functions -------------------------------------------------------------
int translateBytes(uint32_t id, uint8_t* bytearr);


#endif // CAN_SETUP_H