// ModeController.h

#ifndef _MODECONTROLLER_h
#define _MODECONTROLLER_h

#include "Mode.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ModeController {
private:
    std::vector<Mode*> modeList;
    byte lastModeIndex = 0;
    byte modeIndex = 0;
public:
    void SetupModes(CRGB* leds);
    void NextMode();
    void LastMode();
    void ActivateBrightnessMode();
    Mode* CurrentMode();
};

extern ModeController modeController;
#endif