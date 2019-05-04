// commands.h

#ifndef _SERIALCOMMAND_h
#define _SERIALCOMMAND_h

#include "FastLED.h"
#include <string>

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


enum Opcodes {
    GET_BRIGHTNESS = 0,
    SET_BRIGHTNESS = 1,
    ECHO = 2,
	GET_EEPROM = 3,
	SET_EEPROM = 4,
    GET_NUM_LEDS = 5,
    GET_BATTERY = 6,
    CLEAR
};

enum CommandState {
    COMMAND_COMPLETE,
    COMMAND_READ,
    COMMAND_RESPOND
};

class SerialCommand {
public:
    virtual CommandState Run() = 0;
};

class ISerialCommand : virtual public SerialCommand {
public:
    virtual CommandState ParseByte(byte input) = 0;
};

class OSerialCommand : virtual public SerialCommand {
public:
    char* responseBuffer;
};

class IOSerialCommand : public ISerialCommand, public OSerialCommand {

};
#endif