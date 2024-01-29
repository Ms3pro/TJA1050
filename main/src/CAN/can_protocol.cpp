#include <Arduino.h>

#include "can_protocol.h"


int get_RPM(uint8_t* bytearr) {
  return int(((uint16_t)bytearr[0] << 8) | bytearr[1]);
}


int get_GEAR(uint8_t* bytearr) {
  return int(bytearr[0]);
}

/*
int get_SPEED(uint8_t* bytearr){}
int get_OILTEMP(uint8_t* bytearr){}
int get_OILPRESSURE(uint8_t* bytearr){}
int get_COOLANTTEMP(uint8_t* bytearr){}
int get_FUELPSI(uint8_t* bytearr){}
int get_FUELPERCENT(uint8_t* bytearr){}
int get_BATTERYVOLT(uint8_t* bytearr){}
*/

int translateBytes(uint32_t id, uint8_t* bytearr) {
	if      (id == CAN_RPM)         return get_RPM(bytearr);
	else if (id == CAN_GEAR)        return get_GEAR(bytearr);
	/*
	else if (id == CAN_SPEED)       return get_SPEED(bytearr);
	else if (id == CAN_OILTEMP)     return get_OILTEMP(bytearr);
	else if (id == CAN_OILPRESSURE) return get_OILPRESSURE(bytearr);
	else if (id == CAN_COOLANTTEMP) return get_COOLANTTEMP(bytearr);
	else if (id == CAN_FUELPSI)     return get_FUELPSI(bytearr);
	else if (id == CAN_FUELPERCENT) return get_FUELPERCENT(bytearr);
	else if (id == CAN_BATTERYVOLT) return get_BATTERYVOLT(bytearr);
	*/
	else return -1;
}