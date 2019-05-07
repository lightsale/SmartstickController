/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// DemoReel.h

#ifndef _DEMOREELMODE_h
#define _DEMOREELMODE_h

#include "Mode.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


class DemoReelMode : public Mode {
private:
    void(DemoReelMode::*patterns[7])(CRGB* leds) =
    { &DemoReelMode::rainbow,
     &DemoReelMode::rainbowWithGlitter,
     &DemoReelMode::confetti,
     &DemoReelMode::sinelon,
     &DemoReelMode::juggle,
     &DemoReelMode::bpm,
     &DemoReelMode::fade };

    uint8_t patternIndex;;
    uint8_t gHue;

    byte increment;
    uint32_t time;

    void rainbow(CRGB* leds);
    void rainbowWithGlitter(CRGB* leds);
    void confetti(CRGB* leds);
    void sinelon(CRGB* leds);
    void juggle(CRGB* leds);
    void bpm(CRGB* leds);
    void fade(CRGB* leds);

    void nextPattern();

public:
    RequestedAction handleInput(byte input);
    void fillLEDs();
};
extern DemoReelMode demoReelMode;
#endif
