/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// ImageMode.h

#ifndef _IMAGEMODE_h
#define _IMAGEMODE_h

#include "Mode.h"
#include "ImageUtils.h"
#include <vector>

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ImageMode : public Mode {
private:
    int frame = 0;
    int image_index = 0;
public:
    RequestedAction handleInput(byte input);
    void fillLEDs();
};

extern ImageMode imageMode;
#endif
