// 
// 
// 

#include "BrightnessCommand.h"

CommandState SetBrightness::Run() {
    return COMMAND_READ;
}

CommandState SetBrightness::ParseByte(byte input) {
    uint8_t level = (uint8_t)input;
    FastLED.setBrightness(level);
    return COMMAND_COMPLETE;
}

CommandState GetBrightness::Run() {
    uint8_t level = FastLED.getBrightness();
	sprintf(responseBuffer, "%u\0", level);
    return COMMAND_RESPOND;
}

GetBrightness::GetBrightness(char* rsp) {
    responseBuffer = rsp;
}