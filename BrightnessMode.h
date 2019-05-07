/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// BrightnessMode.h

#ifndef _BRIGHTNESSMODE_h
#define _BRIGHTNESSMODE_h

#include "Mode.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class BrightnessMode : public Mode {
private:
    byte numBrightnessLevels = 12;
    byte brightness = 4;
public:
    void setBrightness();
    RequestedAction handleInput(byte input);
    void fillLEDs();
};

extern BrightnessMode brightnessMode;

#endif