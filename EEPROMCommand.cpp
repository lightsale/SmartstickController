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