// BrightnessCommand.h

#ifndef _BRIGHTNESSCOMMAND_h
#define _BRIGHTNESSCOMMAND_h

#include "SerialCommand.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class SetBrightness : public ISerialCommand {
public:
    CommandState ParseByte(byte input);
    CommandState Run();
};

class GetBrightness : public OSerialCommand {
public:
    CommandState Run();
    GetBrightness(char* rsp);
};

#endif

