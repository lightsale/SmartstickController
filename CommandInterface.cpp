/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// 
// 
// 

#include "CommandInterface.h"

CommandInterface* commandInterface = new CommandInterface();

const char* openMsg         = "OPN";
const char* closeMsg        = "CLS";
const char* badMsg          = "BAD";
const char* acknowledgeMsg  = "ACK";
const char* finishedMsg     = "FIN";
const char* resumeMsg       = "RSM";
const char* programmableMsg = "PRG";
const char* rebootMsg       = "RBT";

CommandInterface::CommandInterface() {
    GetBrightness* getbright = new GetBrightness(responseBuffer);
    SetBrightness* setbright = new SetBrightness();
    EchoCommand* echo = new EchoCommand(responseBuffer);
	GetEEPROM* getEEPROM = new GetEEPROM(responseBuffer);
	SetEEPROM* setEEPROM = new SetEEPROM();

    // Note: the order of this list must match that of the opcodes enum.
	commandList = {
		getbright,
		setbright,
		echo,
		getEEPROM,
		setEEPROM
	};
    state = CONNECTION_CLOSED;
}

void CommandInterface::Respond(const char* msg) {
    Serial.println(msg);
    Serial.flush();
    for (uint8_t i = 0; i < strlen(msg); i++) {
        serialMonitorMode.setOutputByte(msg[i]);
    }
}

void CommandInterface::ClosedState(byte input) {
    switch (input) {
    case 'O':
        msgIndex = 1;
        state = CONNECTION_OPENING;
        break;
    case 'R':
        msgIndex = 1;
        state = CONNECTION_RESUMING;
        break;
    default:
        Respond(badMsg);
        break;
    }
}

void CommandInterface::OpeningState(byte input) {
    bool valid = input == openMsg[msgIndex];
    if (valid) {
        if (msgIndex == 2) {
            msgIndex = 0;
            state = CONNECTION_OPEN;
            Respond(openMsg);
        }
        else {
            msgIndex++;
        }
    }
    else {
        state = CONNECTION_CLOSED;
        msgIndex = 0;
        Respond(badMsg);
        // Did not complete magic connection opening string
    }
}

void CommandInterface::ResumingState(byte input) {
    bool valid = input == resumeMsg[msgIndex];
    if (valid) {
        if (msgIndex == 2) {
            msgIndex = 0;
            state = CONNECTION_OPEN;
            Respond(resumeMsg);
            if (programmable) {
                Respond(programmableMsg);
            }
        }
        else {
            msgIndex++;
        }
    }
    else {
        state = CONNECTION_CLOSED;
        msgIndex = 0;
        Respond(badMsg);
        // Did not complete magic connection opening string
    }
}

void CommandInterface::OpenState(byte input) {
    switch (input) {
    case ECHO:
    case SET_BRIGHTNESS:
    case GET_NUM_LEDS:
    case GET_BRIGHTNESS:
    case GET_BATTERY:
	case GET_EEPROM:
	case SET_EEPROM:
    {
        activeCommand = commandList[input];
        CommandState result = activeCommand->Run();
        CmdResponse(result);
    }
        break;
	case 'B':
	{
		activeCommand = commandList[SET_BRIGHTNESS];
		CommandState result = activeCommand->Run();
		CmdResponse(result);
	}
	break;
	case 'E':
	{
		activeCommand = commandList[GET_EEPROM];
		CommandState result = activeCommand->Run();
		CmdResponse(result);
	}
	break;
	case 'F':
	{
		activeCommand = commandList[SET_EEPROM];
		CommandState result = activeCommand->Run();
		CmdResponse(result);
	}
	break;
    case CLEAR:
        serialMonitorMode.clear();
        break;
    case 'R':
        msgIndex = 1;
        state = CONNECTION_RESUMING;
        break;
    case 'C':
        msgIndex = 1;
        state = CONNECTION_CLOSING;
        break;
    default:
        Respond(badMsg);
        //Unrecognized command!
        break;
    }
}

void CommandInterface::CmdResponse(CommandState response) {
    switch (response) {
    case COMMAND_READ:
        if (state != CONNECTION_CMD_READ) {
            readingCommand = reinterpret_cast<ISerialCommand*>(activeCommand);
            state = CONNECTION_CMD_READ;
        }
        break;
    case COMMAND_RESPOND:
    {
        uint8_t i = 0;
        char val = responseBuffer[0];
        while (i < 256 && responseBuffer[i] != '\0') {
            Serial.write(responseBuffer[i]);
            i++;
        }
        Serial.write('\n');
        //Serial.write('\0');
        Serial.println(finishedMsg);
        //Assume for now responding = complete
        state = CONNECTION_OPEN;
    }
    break;
    case COMMAND_COMPLETE:
        state = CONNECTION_OPEN;
        Respond(acknowledgeMsg);
        break;
    }
}

void CommandInterface::CmdState(byte input) {
    CommandState commandState = readingCommand->ParseByte(input);
    CmdResponse(commandState);
}

void CommandInterface::ClosingState(byte input) {
    bool valid = input == closeMsg[msgIndex];;
    if (valid) {
        if (msgIndex == 2) {
            msgIndex = 0;
            state = CONNECTION_CLOSED;
            Respond(closeMsg);
        }
        else {
            msgIndex++;
        }
    }
    else {
        state = CONNECTION_OPEN;
        msgIndex = 0;
        // Did not complete magic connection closing string
    }
}

void CommandInterface::ParseByte(byte input) {
    // Dispatch input based on current state
    switch (state) {
    case CONNECTION_CLOSED:
        ClosedState(input);
        break;
    case CONNECTION_RESUMING:
        ResumingState(input);
        break;
    case CONNECTION_OPENING:
        OpeningState(input);
        break;
    case CONNECTION_OPEN:
        OpenState(input);
        break;
    case CONNECTION_CMD_READ:
        CmdState(input);
        break;
    case CONNECTION_CLOSING:
        ClosingState(input);
        break;
    }
}

void CommandInterface::receiveFlip() {
    if (state == CONNECTION_OPEN) {
        state = CONNECTION_CLOSED;
    }
}
//serialEvent is called by arduino/teensy framework when bytes are available
//on the serial port.
void serialEvent() {
    uint32_t read_begin = millis();
    // Time out after 10 seconds
    while (Serial.available() && millis() - read_begin < 10000) {
        byte input = (byte)Serial.read();
        /*serialMonitorMode.setInputByte(input);*/
        commandInterface->ParseByte(input);
    }
}