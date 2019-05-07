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

#include "SerialMonitorMode.h"

RequestedAction SerialMonitorMode::handleInput(byte input)
{
    switch (input) {
    case singleclick:
        clear();
        return RequestedAction::donothing;
    case doubleclick:
        return RequestedAction::donothing;
        break;
    }
    return RequestedAction::donothing;
}

void SerialMonitorMode::fillLEDs()
{

}

void SerialMonitorMode::clear() {
    for (byte i = 0; i < NUM_LEDS * 2; i++) {
        leds[i] = CRGB::Black;
    }
}

void SerialMonitorMode::start() {
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Black;
    }
    mirrorBackHalf();
}

void SerialMonitorMode::setOutputByte(byte msg) {
    if (active) {
        leds[bufferSize + outputIndex] = CHSV(msg, 255, 255);
        outputIndex = (outputIndex + 1) % bufferSize;
    }
}

void SerialMonitorMode::setInputByte(byte msg) {
    if (active) {
        leds[inputIndex] = CHSV(msg, 255, 255);
        inputIndex = (inputIndex + 1) % bufferSize;
    }
}

SerialMonitorMode serialMonitorMode;