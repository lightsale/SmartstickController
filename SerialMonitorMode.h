// SerialMonitorMode.h

#ifndef _SERIALMONITORMODE_h
#define _SERIALMONITORMODE_h

#include "Mode.h"


#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class SerialMonitorMode : public Mode {
private:
    const byte bufferSize = 12;
    byte inputIndex = 0;
    byte outputIndex = 0;
public:
    void clear();
    void setOutputByte(byte msg);
    void setInputByte(byte msg);
    void start();
    RequestedAction handleInput(byte input);
    void fillLEDs();
};

extern SerialMonitorMode serialMonitorMode;

#endif

