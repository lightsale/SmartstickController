/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// CommandInterface.h

#ifndef _COMMANDINTERFACE_h
#define _COMMANDINTERFACE_h
#include "SerialCommand.h"
#include "EchoCommand.h"
#include "BrightnessCommand.h"
#include "SerialMonitorMode.h"
#include "EEPROMCommand.h"
#include <vector>

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum ConnectionState {
    CONNECTION_CLOSED,
    CONNECTION_OPENING,
    CONNECTION_RESUMING,
    CONNECTION_OPEN,
    CONNECTION_CMD_READ,
    CONNECTION_CLOSING,
};

class CommandInterface {
private:
    uint8_t msgIndex;

    ISerialCommand* readingCommand;
    SerialCommand* activeCommand;

    std::vector<SerialCommand*> commandList;

    ConnectionState state;
    void OpeningState(byte input);
    void ResumingState(byte input);
    void OpenState(byte input);
    void ClosingState(byte input);
    void ClosedState(byte input);
    void CmdState(byte input);
    void CmdResponse(CommandState response);
    void Respond(const char* msg);
public:
    bool programmable = true;
    void receiveFlip();
    char responseBuffer[256];
    void ParseByte(byte input);
    CommandInterface();
};

extern CommandInterface* commandInterface;
#endif

