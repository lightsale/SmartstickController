/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
#ifndef _INPUT_h
#define _INPUT_h

#include "Constants.h"

#define DOUBLECLICK_INTERVAL 300
#define LONGPRESS_INTERVAL 1000

#if defined(ARDUINO) && ARDUINO >=100
  #include "arduino.h"
#else
  #include "WProgram.h"
#endif

#define NO_INPUT 255

const typedef enum {
  longpress, singleclick, doubleclick, tripleclick, quadclick
} ClickType;

byte get_input();
void reset_button_state();

struct ButtonState {
    unsigned int downtime;
    unsigned int uptime;
    byte clicks;
    bool is_clicking;
    bool timing_out;
    bool long_pressing;
};

extern ButtonState bstate;
#endif
