/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// FlashlightMode.h

#ifndef _FLASHLIGHTMODE_h
#define _FLASHLIGHTMODE_h

#include "Mode.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class FlashlightMode : public Mode {
public:
    RequestedAction handleInput(byte input);
    void fillLEDs();
    void start();
};

extern FlashlightMode flashlightMode;
#endif
