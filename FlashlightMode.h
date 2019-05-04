// FlashlightMode.h

#ifndef _FLASHLIGHTMODE_h
#define _FLASHLIGHTMODE_h

#include "Mode.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class FlashlightMode : public Mode {
public:
    RequestedAction handleInput(byte input);
    void fillLEDs();
    void start();
};

extern FlashlightMode flashlightMode;
#endif
