/*  Copyright (C) 2019, Lightsale, Inc.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
// playlists.h


#ifndef _PLAYLISTS_h
#define _PLAYLISTS_h
#include <stdint.h>

struct Playlist {
    const uint8_t* color;
    const bool fixedDuration;
    const uint16_t fadeTime;
    const uint8_t num_images;
    const uint32_t* durations;
    const uint16_t* images;
};

extern const Playlist playlists[];
extern const int playlist_count;
extern const uint8_t num_playlists;
#endif