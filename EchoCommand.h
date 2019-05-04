// EchoCommand.h

#ifndef _ECHOCOMMAND_h
#define _ECHOCOMMAND_h

#include "SerialCommand.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class EchoCommand : public IOSerialCommand {
private:
    uint8_t index;
public:
    CommandState ParseByte(byte input);
    CommandState Run();
    EchoCommand(char* responseBuffer);
};

#endif

