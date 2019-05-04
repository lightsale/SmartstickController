// BrightnessMode.h

#ifndef _BRIGHTNESSMODE_h
#define _BRIGHTNESSMODE_h

#include "Mode.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class BrightnessMode : public Mode {
private:
    byte numBrightnessLevels = 12;
    byte brightness = 4;
public:
    void setBrightness();
    RequestedAction handleInput(byte input);
    void fillLEDs();
};

extern BrightnessMode brightnessMode;

#endif