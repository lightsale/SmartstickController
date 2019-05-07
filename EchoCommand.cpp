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