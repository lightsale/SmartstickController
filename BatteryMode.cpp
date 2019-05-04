// 
// 
// 

#include "BatteryMode.h"

uint16_t BatteryMode::getVoltage() {
    return analogRead(BATTERY_VOLTAGE_PIN);
}

fract8 BatteryMode::getPercentage() {
    // For now, assume linear from 3.7 : 0% => 4.1v : 100%
    if (millis() - lastSample > (BATTERY_SAMPLE_RATE*1000)) {
        uint16_t pinValue = getVoltage();
        if (pinValue > BATTERY_VOLTAGE_CEIL)
            lastPercent = 255;
        else if (pinValue < BATTERY_VOLTAGE_FLOOR)
            lastPercent = 0;
        else
            // yields a value from 0 => 255, because the range from FLOOR to CEIL
            // is 1/12th of 4096 (aka 0.4v/4.8v), so * (3/4) yields 1/16, aka 0-255
            lastPercent = (3 *(pinValue - BATTERY_VOLTAGE_FLOOR))/4;
        lastSample = millis();
    }
    return lastPercent;
}

void BatteryMode::fillLEDs() {
    bool charging = digitalRead(STBC_CHG_PIN) == LOW;
    fract8 percent = getPercentage();
    uint8_t numToFill = lerp8by8(0, NUM_LEDS, percent);
    CHSV color = CHSV(lerp8by8(0,96, percent), 255, 255);
    for (int i = 0; i < NUM_LEDS; i++) {
        if (i < numToFill) {
            // If we're charging, pulse the last LED
            leds[i] = color;
            if (charging && i == numToFill-1) {
                leds[i] = leds[i].fadeToBlackBy(sin8(millis() / 4));
            }
        }
        else {
            leds[i] = CRGB::Black;
        }
    }
    mirrorBackHalf();
}

BatteryMode::BatteryMode() {
    analogReference(INTERNAL1V2);
    analogReadAveraging(4);
    analogReadResolution(12);
}

RequestedAction BatteryMode::handleInput(byte input) {
    return RequestedAction::donothing;
}

void BatteryMode::start() {
    Serial.println("BatteryMode started");
    lastSample = -(BATTERY_SAMPLE_RATE*1000+1);
}

BatteryMode batteryMode;