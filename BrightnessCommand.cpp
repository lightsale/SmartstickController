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
