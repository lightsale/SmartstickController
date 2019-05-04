#include "input.h"

ButtonState bstate;

void reset_button_state() {
    bstate.uptime = 0;
    bstate.downtime = 0;
    bstate.clicks = 0;
    bstate.is_clicking = false;
    bstate.timing_out = false;
    bstate.long_pressing = false;
}

/* Parses the button state-stream into interprettable click/double click/long-press/etc */
byte get_input() {
    unsigned long t = millis();
    byte switchposition = digitalRead(SWITCH_PIN);
    if (switchposition == LOW) {
        // pressed
        if (!bstate.is_clicking) {
            bstate.downtime = t;
            bstate.is_clicking = true;
            bstate.timing_out = false;
            bstate.clicks++;
        }
        else {
            if (t - bstate.downtime > LONGPRESS_INTERVAL && !bstate.long_pressing) {
                bstate.long_pressing = true;
                return longpress;
            }
        }
    }
    else {
        // up
        if (bstate.is_clicking) {
            // released
            bstate.uptime = t;
            bstate.is_clicking = false;
            bstate.timing_out = true;
        }
        else {
            // up
            if (bstate.timing_out) {
                // In the timeout period
                if (t - bstate.uptime > DOUBLECLICK_INTERVAL) {
                    byte input;
                    // Exceeded doubleclick interval, interpret as is
                    if (bstate.long_pressing) {
                        input = NO_INPUT;
                    }
                    else {
                        input = bstate.clicks;
                    }
                    reset_button_state();
                    return input;
                }
            }
        }
    }
    return NO_INPUT;
}
