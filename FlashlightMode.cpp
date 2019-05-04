// 
// 
// 

#include "FlashlightMode.h"

RequestedAction FlashlightMode::handleInput(byte input)
{
    return RequestedAction::donothing;
}

void FlashlightMode::fillLEDs()
{

}

void FlashlightMode::start() {
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(CRGB::White);
    }
    for (int i = NUM_LEDS; i < NUM_LEDS * 2; i++) leds[i] = CRGB(CRGB::Black);
}

FlashlightMode flashlightMode;