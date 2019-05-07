/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// BrightnessCommand.h

#ifndef _BRIGHTNESSCOMMAND_h
#define _BRIGHTNESSCOMMAND_h

#include "SerialCommand.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class SetBrightness : public ISerialCommand {
public:
    CommandState ParseByte(byte input);
    CommandState Run();
};

class GetBrightness : public OSerialCommand {
public:
    CommandState Run();
    GetBrightness(char* rsp);
};

#endif

