/*
* IMPORTANT:
* 
* List of all CAN IDs the dashboard uses to filter, translate, and display CAN bus data.
* This file MUST BE EDITED to correspond to your vehicle's CAN bus IDs otherwise 
* it may not be reading your vehicle properly.
* 
* Additionally, the functions used to translate values from the CAN byte arrays
* MUST BE EDITED otherwise it cannot properly translate to meaningful data.
* (One way of doing it fast could be bit masking & bit shifting)
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


//----- Translator Class ------------------------------------------------------

class TranslateCAN {
private:
		/*none*/
public:
	static uint16_t rpm(uint8_t* bytes)  { return ((uint16_t)bytes[0] << 8) | bytes[1]; }
	static uint8_t  gear(uint8_t* bytes) { return bytes[0]; }
	/*
	static <datatype> speed     (uint8_t* bytes) {}
	static <datatype> oilTemp   (uint8_t* bytes) {}
	static <datatype> oilPres   (uint8_t* bytes) {}
	static <datatype> coolTemp  (uint8_t* bytes) {}
	static <datatype> fuelPSI   (uint8_t* bytes) {}
	static <datatype> fuelPcent (uint8_t* bytes) {}
	static <datatype> battVolt  (uint8_t* bytes) {}
	*/
};


#endif // CAN_SETUP_H