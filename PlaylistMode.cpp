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

#include "PlaylistMode.h"

void PlaylistMode::NextImage()
{
    Playlist playlist = playlists[playlistIndex];
    lastChange = millis();
    imageIndex = (imageIndex + 1) % playlist.num_images;
    frameIndex = nextFrameIndex;
    nextFrameIndex = 0;
}

void PlaylistMode::fillPlaylist() {
    Playlist playlist = playlists[playlistIndex];
    uint32_t duration = playlist.fixedDuration ? playlist.durations[0] : playlist.durations[imageIndex];
    uint32_t elapsed = millis() - lastChange;
    if (elapsed > duration && playing) {
        NextImage();
    }
    ImageData image = image_patterns[playlist.images[imageIndex]];
    /*lerp between current image and next image*/
    if (playlist.fadeTime > 0 && playing) {
        uint32_t fadebegin = duration - playlist.fadeTime;
        if (elapsed > fadebegin) {
            uint8_t nextIndex = (imageIndex + 1) % playlist.num_images;
            ImageData nextImg = image_patterns[playlist.images[nextIndex]];
            ImageUtils::fillPixels(leds, image, frameIndex);
            fract8 lerp = 255 * (elapsed - fadebegin) / (duration - fadebegin);
            ImageUtils::fillPixels(leds, nextImg, nextFrameIndex, lerp);
            nextFrameIndex = (nextFrameIndex + 1) % nextImg.frames;
        }
        else {
            ImageUtils::fillPixels(leds, image, frameIndex);
        }
    }
    else {
        ImageUtils::fillPixels(leds, image, frameIndex);
    }
    frameIndex = (frameIndex + 1) % image.frames;
}

void PlaylistMode::fillMenu() {
    uint8_t pixelIndex = 0;
    for (uint8_t i = 0; i < num_playlists; i++) {
        uint8_t remainder = i < (NUM_LEDS% num_playlists) ? 1 : 0;
        uint8_t stop = pixelIndex + (NUM_LEDS / num_playlists) + remainder;
        Playlist pl = playlists[i];
        for (pixelIndex; pixelIndex < stop; pixelIndex++) {
            CRGB color = CRGB(pl.color[0], pl.color[1], pl.color[2]);
            leds[pixelIndex] = color;
            if (playlistIndex == i) {
                leds[pixelIndex] = color.fadeToBlackBy(sin8(millis() / 4));
            }
        }
    }
}

void PlaylistMode::fillLEDs() {
    if (inMenu) {
        fillMenu();
    }
    else {
        fillPlaylist();
    }
    mirrorBackHalf();
}

PlaylistMode::PlaylistMode() {

}

RequestedAction PlaylistMode::handleInput(byte input) {
    switch (input) {
    case singleclick:
        if (inMenu) {
            // In menu, single click to advance pointer
            playlistIndex = (playlistIndex + 1) % num_playlists;
        }
        else {
            // During playback, single click cycle through images
            NextImage();
        }
        break;
    case doubleclick:
        if (inMenu) {
            // In menu, double click to select
            lastChange = millis();
            inMenu = false;
        }
        else {
            // During playback, doubleclick to start/stop playback
            playing = !playing;
        }
        break;
    }
    return RequestedAction::donothing;
}

void PlaylistMode::start() {
    inMenu = true;
    playing = true;
    imageIndex = 0;
    frameIndex = 0;
    nextFrameIndex = 0;
    playlistIndex = 0;
}

PlaylistMode playlistMode;