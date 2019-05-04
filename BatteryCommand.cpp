// 
// 
// 

#include "BatteryCommand.h"

CommandState GetBatteryCmd::Run() {
    float voltage = batteryMode.getVoltage();
    memcpy(responseBuffer, &voltage, sizeof voltage);
    return COMMAND_RESPOND;
}

GetBatteryCmd::GetBatteryCmd(char* rsp) {
    responseBuffer = rsp;
}