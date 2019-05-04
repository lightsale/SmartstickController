// 
// 
// 

#include "DemoReelMode.h"



void addGlitter(fract8 chanceOfGlitter, CRGB* leds)
{
    if (random8() < chanceOfGlitter) {
        leds[random16(NUM_LEDS)] += CRGB::White;
    }
}

RequestedAction DemoReelMode::handleInput(byte input)
{
    switch (input) {
    case doubleclick:
        increment ^= 1;
        break;
    case singleclick:
        nextPattern();
        break;
    }
    return RequestedAction::donothing;
}

void DemoReelMode::fillLEDs()
{
    // Dereference array of member methods to an executable function
    (this->*patterns[patternIndex])(leds);
    mirrorBackHalf();
    uint32_t t = millis();
    if (t - time > 20) {
        time = t;
        gHue += increment;
    }
}

void DemoReelMode::nextPattern() {
    patternIndex = (patternIndex + 1) % ARRAY_SIZE(patterns);
}

void DemoReelMode::rainbow(CRGB * leds)
{
    // FastLED's built-in rainbow generator
    fill_rainbow(leds, NUM_LEDS, gHue, 7);
}

void DemoReelMode::rainbowWithGlitter(CRGB * leds)
{
    // built-in FastLED rainbow, plus some random sparkly glitter
    rainbow(leds);
    addGlitter(80, leds);
}

void DemoReelMode::confetti(CRGB * leds)
{
    // random colored speckles that blink in and fade smoothly
    fadeToBlackBy(leds, NUM_LEDS, 10);
    int pos = random16(NUM_LEDS);
    leds[pos] += CHSV(gHue + random8(64), 200, 255);
}

void DemoReelMode::sinelon(CRGB * leds)
{
    // a colored dot sweeping back and forth, with fading trails
    fadeToBlackBy(leds, NUM_LEDS, 20);
    int pos = beatsin16(13, 0, NUM_LEDS);
    leds[pos] += CHSV(gHue, 255, 192);
}

void DemoReelMode::juggle(CRGB * leds)
{
    // eight colored dots, weaving in and out of sync with each other
    fadeToBlackBy(leds, NUM_LEDS, 20);
    byte dothue = 0;
    for (int i = 0; i < 8; i++) {
        leds[beatsin16(i + 7, 0, NUM_LEDS)] |= CHSV(dothue, 200, 255);
        dothue += 32;
    }
}

void DemoReelMode::bpm(CRGB * leds)
{
    // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
    uint8_t BeatsPerMinute = 62;
    CRGBPalette16 palette = PartyColors_p;
    uint8_t beat = beatsin8(BeatsPerMinute, 64, 255);
    for (int i = 0; i < NUM_LEDS; i++) { //9948
        leds[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
    }
}

void DemoReelMode::fade(CRGB * leds)
{
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV(gHue, 255, 255);
    }
}

DemoReelMode demoReelMode;