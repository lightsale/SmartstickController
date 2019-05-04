// 
// 
// 
#include "Mode.h"
//
void Mode::start() {}

void Mode::mirrorBackHalf() {
    for (int i = NUM_LEDS; i < NUM_LEDS * 2; i++) {
        leds[i] = leds[NUM_LEDS * 2 - 1 - i];
    }
}