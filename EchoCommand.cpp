// 
// 
// 

#include "EchoCommand.h"

CommandState EchoCommand::ParseByte(byte input) {
    responseBuffer[index] = input;
    if (index > 255 || input == '\n') {
        index = 0;
        return COMMAND_RESPOND;
    }
	else if (input == '\0') {
		return COMMAND_COMPLETE;
	}
    else {
        index++;
        return COMMAND_READ;
    }
}

CommandState EchoCommand::Run()
{
    return COMMAND_READ;
}

EchoCommand::EchoCommand(char* rsp) {
    responseBuffer = rsp;
}