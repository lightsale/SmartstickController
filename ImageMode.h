// ImageMode.h

#ifndef _IMAGEMODE_h
#define _IMAGEMODE_h

#include "Mode.h"
#include "ImageUtils.h"
#include <vector>

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ImageMode : public Mode {
private:
    int frame = 0;
    int image_index = 0;
public:
    RequestedAction handleInput(byte input);
    void fillLEDs();
};

extern ImageMode imageMode;
#endif
