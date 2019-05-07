/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// BatteryMode.h

#ifndef _BATTERYMODE_h
#define _BATTERYMODE_h

 // for floor of 3.7, (3.7/4.8) * 4096
#define BATTERY_VOLTAGE_FLOOR 3157
 // for ceil of 4.1, (4.1/4.8) * 4096
#define BATTERY_VOLTAGE_CEIL 3498
#define BATTERY_SAMPLE_RATE 3

#include "Mode.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class BatteryMode : public Mode
{
  private:
    uint32_t lastSample;
    fract8 lastPercent;
  public:
    BatteryMode();
    RequestedAction handleInput(byte input);
    uint16_t getVoltage();
    fract8 getPercentage();
    void fillLEDs();
    void start();
};

extern BatteryMode batteryMode;

#endif
