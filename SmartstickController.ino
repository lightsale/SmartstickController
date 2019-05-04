#include "ImageUtils.h"
#include "PlaylistMode.h"
#include "playlists.h"
#include "Constants.h"
#include "SerialMonitorMode.h"
#include "BatteryCommand.h"
#include "BatteryMode.h"
#include "CommandInterface.h"
#include "ModeController.h"
#include "FastLED.h"
#include "input.h"
#include "Mode.h"
#include "BrightnessMode.h"
#include "Constants.h"
#include <Snooze.h>

FASTLED_USING_NAMESPACE

SnoozeDigital digital;
SnoozeBlock config(digital);

CRGB leds[2*NUM_LEDS];

bool systemrunning = true;

#define BOARD_LED 13

void setup() {
    delay(3000); // 3 second delay for recovery
    reset_button_state();
    FastLED.addLeds<LED_TYPE, LED_DATA_PIN, CLK_PIN, COLOR_ORDER>(leds, NUM_LEDS*2).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(STARTING_BRIGHTNESS);
    pinMode(SWITCH_PIN, INPUT_PULLUP);
    pinMode(STBC_PWR_PIN, INPUT_PULLUP);
    pinMode(STBC_CHG_PIN, INPUT_PULLUP);
    pinMode(MOSFET_GATE_PIN, OUTPUT);
    digital.pinMode(SWITCH_PIN, INPUT_PULLUP, RISING);
    modeController.SetupModes(leds);
    digitalWrite(MOSFET_GATE_PIN, LOW);
    //pinMode(BOARD_LED, OUTPUT);
    //digitalWrite(BOARD_LED, HIGH);
    Serial.begin(9600);
}

void loop() {
    byte input = get_input();
    RequestedAction action = RequestedAction::donothing;
    switch (input) {
        case NO_INPUT:
            if (systemrunning) {
                modeController.CurrentMode()->fillLEDs();
                FastLED.show();
                FastLED.delay(1000 / FRAMES_PER_SECOND);;
            }
            else {
                delay(100);
            }
            break;
        case longpress:
            if (systemrunning)
                turn_off();
            break;
        case singleclick:
        case doubleclick:
            Serial.println("click");
            if (!systemrunning)
                turn_on();
            else
                action = modeController.CurrentMode()->handleInput(input);
            break;
        case tripleclick:
            modeController.NextMode();
            break;
        case quadclick:
            modeController.ActivateBrightnessMode();
            break;
    }
    switch (action) {
        case RequestedAction::lastmode:
            modeController.LastMode();
            break;
        case RequestedAction::donothing:
            break;
    }
}

void turn_on() {
    systemrunning = true;
    brightnessMode.setBrightness();
}

void turn_off() {
    systemrunning = false;
    for (byte i = 0; i < NUM_LEDS * 2; i++) {
        leds[i] = CRGB::Black;
    }
    // Set all output pins low?
    FastLED.setBrightness(0);
    FastLED.clear();
    FastLED.clear();
    FastLED.show();
    digitalWrite(CLK_PIN, LOW);
    digitalWrite(LED_DATA_PIN, LOW);
    digitalWrite(MOSFET_GATE_PIN, HIGH);
    /*digitalWrite(BOARD_LED, LOW);*/
    // Wait until the user stops depressing the button (LOW => HIGH)
    uint32_t press_begin = millis();
    while (digitalRead(SWITCH_PIN) == LOW && millis() - press_begin < 10000) {
        delay(10);
    }
    commandInterface->programmable = false;
    Snooze.hibernate(config);
    /*digitalWrite(BOARD_LED, HIGH);*/
    digitalWrite(MOSFET_GATE_PIN, LOW);
    turn_on();
}