/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */


#ifndef _IMAGES_h
#define _IMAGES_h
#include <stdint.h>

struct ImageData {
    const uint8_t bitdepth;
    const uint16_t frames;
    const uint8_t* palette;
    const uint8_t* pixels;
};

extern const ImageData image_patterns[];
extern const uint16_t image_count;

#endif