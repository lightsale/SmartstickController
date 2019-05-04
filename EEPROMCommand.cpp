// 
// 
// 

#include "EEPROMCommand.h"
#include <EEPROM.h>

CommandState SetEEPROM::Run() {
	idx = 0;
	return COMMAND_READ;
}

CommandState SetEEPROM::ParseByte(byte input) {
	EEPROM.write(idx, input);
	idx++;
	if (input == '\0')
		return COMMAND_COMPLETE;
	return COMMAND_READ;
}

CommandState GetEEPROM::Run() {
	for (int i = 0; i < 255; i++) {
		responseBuffer[i] = EEPROM.read(i);
		if (responseBuffer[i] == '\0') {
			break;
		}
	}
	return COMMAND_RESPOND;
}

GetEEPROM::GetEEPROM(char* rsp) {
	responseBuffer = rsp;
}