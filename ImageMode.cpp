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

#include "ImageMode.h"

RequestedAction ImageMode::handleInput(byte input)
{
    switch (input) {
    case singleclick:
        frame = 0;
        /*image_index = image_index+1 % ARRAY_SIZE(image_patterns);*/
        image_index = (image_index + 1) % image_count;
        break;
    case doubleclick:
        break;
    }
    return RequestedAction::donothing;
}

void ImageMode::fillLEDs()
{
    ImageData image = image_patterns[image_index];
    ImageUtils::fillPixels(leds, image, frame);
    mirrorBackHalf();
    frame = (frame + 1) % image.frames;
}

ImageMode imageMode;