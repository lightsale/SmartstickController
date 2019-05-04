// BrightnessCommand.h

#ifndef _EEPROMCOMMAND_h
#define _EEPROMCOMMAND_h

#include "SerialCommand.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class SetEEPROM : public ISerialCommand {
public:
	CommandState ParseByte(byte input);
	CommandState Run();
private:
	uint8_t idx;
};

class GetEEPROM : public OSerialCommand {
public:
	CommandState Run();
	GetEEPROM(char* rsp);
};

#endif

