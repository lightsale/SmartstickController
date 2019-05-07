/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// ModeController.h

#ifndef _MODECONTROLLER_h
#define _MODECONTROLLER_h

#include "Mode.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ModeController {
private:
    std::vector<Mode*> modeList;
    byte lastModeIndex = 0;
    byte modeIndex = 0;
public:
    void SetupModes(CRGB* leds);
    void NextMode();
    void LastMode();
    void ActivateBrightnessMode();
    Mode* CurrentMode();
};

extern ModeController modeController;
#endif