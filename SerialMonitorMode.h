/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// SerialMonitorMode.h

#ifndef _SERIALMONITORMODE_h
#define _SERIALMONITORMODE_h

#include "Mode.h"


#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class SerialMonitorMode : public Mode {
private:
    const byte bufferSize = 12;
    byte inputIndex = 0;
    byte outputIndex = 0;
public:
    void clear();
    void setOutputByte(byte msg);
    void setInputByte(byte msg);
    void start();
    RequestedAction handleInput(byte input);
    void fillLEDs();
};

extern SerialMonitorMode serialMonitorMode;

#endif

