// ImageUtils.h

#ifndef _IMAGEUTILS_h
#define _IMAGEUTILS_h

#include "Constants.h"
#include "images.h"
#include "FastLED.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ImageUtils {
private:
    static void fillTruecolorPixels(CRGB* leds, ImageData img, uint16_t frame);
    static void fillPalettizedPixels(CRGB* leds, ImageData img, uint16_t frame);
    static void fillTruecolorPixels(CRGB* leds, ImageData img, uint16_t frame, fract8 interp);
    static void fillPalettizedPixels(CRGB* leds, ImageData img, uint16_t frame, fract8 interp);
public:
    static void fillPixels(CRGB* leds, ImageData img, uint16_t frame);
    static void fillPixels(CRGB* leds, ImageData img, uint16_t frame, fract8 interp);
};

#endif