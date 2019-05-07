/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// PlaylistMode.h

#ifndef _PLAYLISTMODE_h
#define _PLAYLISTMODE_h

#include "ImageUtils.h"
#include "playlists.h"
#include "Mode.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class PlaylistMode : public Mode
{
private:
    bool playing;
    uint32_t lastChange;
    uint8_t playlistIndex;
    uint16_t imageIndex;
    uint16_t frameIndex;
    uint16_t nextFrameIndex;
    void fillPlaylist();
    void fillMenu();
public:
    bool inMenu;
    PlaylistMode();
    RequestedAction handleInput(byte input);
    void fillLEDs();
    void start();
};

extern PlaylistMode playlistMode;

#endif

