#ifndef _INPUT_h
#define _INPUT_h

#include "Constants.h"

#define DOUBLECLICK_INTERVAL 300
#define LONGPRESS_INTERVAL 1000

#if defined(ARDUINO) && ARDUINO >=100
  #include "arduino.h"
#else
  #include "WProgram.h"
#endif

#define NO_INPUT 255

const typedef enum {
  longpress, singleclick, doubleclick, tripleclick, quadclick
} ClickType;

byte get_input();
void reset_button_state();

struct ButtonState {
    unsigned int downtime;
    unsigned int uptime;
    byte clicks;
    bool is_clicking;
    bool timing_out;
    bool long_pressing;
};

extern ButtonState bstate;
#endif
