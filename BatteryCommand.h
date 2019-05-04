// BatteryCommand.h

#ifndef _BATTERYCOMMAND_h
#define _BATTERYCOMMAND_h

#include "SerialCommand.h"
#include "BatteryMode.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class GetBatteryCmd : public OSerialCommand {
public:
    CommandState Run();
    GetBatteryCmd(char* rsp);
};

#endif

