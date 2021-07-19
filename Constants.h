/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// Constants.h

#ifndef _CONSTANTS_h
#define _CONSTANTS_h

//Pin definitions
#define MOSFET_GATE_PIN 22
#define LED_DATA_PIN 0
#define SWITCH_PIN 2
#define CLK_PIN 3

//Rev 5
#define BATTERY_VOLTAGE_PIN 10
//Rev 3
//#define BATTERY_VOLTAGE_PIN 9

#define STBC_CHG_PIN 23
#define STBC_PWR_PIN 1

//Strip settings
#define STARTING_BRIGHTNESS 24
#define FRAMES_PER_SECOND 240

//LED parameters
#define NUM_LEDS 24
#define LED_TYPE APA102
#define COLOR_ORDER BGR

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#endif