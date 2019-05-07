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

#include "BrightnessMode.h"

void BrightnessMode::setBrightness()
{
    uint8_t minbrightness = 4;
    uint8_t val = minbrightness + ((255 - minbrightness) * brightness / numBrightnessLevels);
    FastLED.setBrightness(val);
}

RequestedAction BrightnessMode::handleInput(byte input)
{
    switch (input) {
    case singleclick:
        brightness = (brightness + 1) % numBrightnessLevels;
        setBrightness();
        break;
    case doubleclick:
        return RequestedAction::lastmode;
        break;
    }
    return RequestedAction::donothing;
}

void BrightnessMode::fillLEDs()
{
    for (int i = 0; i < NUM_LEDS; i++) {
        if (i < (brightness + 1) * 2)
            leds[i] = CRGB(CRGB::Red);
        else
            leds[i] = CRGB(CRGB::Black);
    }
    mirrorBackHalf();
}

BrightnessMode brightnessMode;