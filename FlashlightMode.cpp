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

#include "FlashlightMode.h"

RequestedAction FlashlightMode::handleInput(byte input)
{
    return RequestedAction::donothing;
}

void FlashlightMode::fillLEDs()
{

}

void FlashlightMode::start() {
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(CRGB::White);
    }
    for (int i = NUM_LEDS; i < NUM_LEDS * 2; i++) leds[i] = CRGB(CRGB::Black);
}

FlashlightMode flashlightMode;