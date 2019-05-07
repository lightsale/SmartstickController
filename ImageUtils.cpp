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

#include "ImageUtils.h"

void ImageUtils::fillTruecolorPixels(CRGB* leds, ImageData img, uint16_t frame) {
    int frame_offset = NUM_LEDS * 3 * frame;
    for (uint8_t i = 0; i < NUM_LEDS; i++) {
        byte r = img.pixels[frame_offset + 3 * i + 0];
        byte g = img.pixels[frame_offset + 3 * i + 1];
        byte b = img.pixels[frame_offset + 3 * i + 2];
        leds[NUM_LEDS - 1 - i] = CRGB(r, g, b);
    }
}

void ImageUtils::fillTruecolorPixels(CRGB* leds, ImageData img, uint16_t frame, fract8 interp) {
    int frame_offset = NUM_LEDS * 3 * frame;
    for (uint8_t i = 0; i < NUM_LEDS; i++) {
        byte r = img.pixels[frame_offset + 3 * i + 0];
        byte g = img.pixels[frame_offset + 3 * i + 1];
        byte b = img.pixels[frame_offset + 3 * i + 2];
        leds[NUM_LEDS - 1 - i] = leds[NUM_LEDS - 1 - i].lerp8(CRGB(r, g, b), interp);
    }
}

void ImageUtils::fillPalettizedPixels(CRGB* leds, ImageData img, uint16_t frame) {
    int frame_offset = (NUM_LEDS * img.bitdepth * frame) / 8;
    uint8_t bytes_read = 0;
    uint8_t buffer_index = 0;
    uint8_t buffer = img.pixels[frame_offset];
    uint8_t paletteIndex = 0;
    for (uint8_t i = 0; i < NUM_LEDS; i++) {

        for (uint8_t j = 0; j < img.bitdepth; j++) {
            if (buffer & (1 << buffer_index))
                paletteIndex |= (1 << j);
            buffer_index++;
            if (buffer_index == 8) {
                bytes_read++;
                buffer = img.pixels[frame_offset + bytes_read];
                buffer_index = 0;
            }
        }
        uint8_t r = img.palette[3 * paletteIndex + 0];
        uint8_t g = img.palette[3 * paletteIndex + 1];
        uint8_t b = img.palette[3 * paletteIndex + 2];
        leds[NUM_LEDS - 1 - i] = CRGB(r, g, b);
        paletteIndex = 0;
    }
}

void ImageUtils::fillPalettizedPixels(CRGB* leds, ImageData img, uint16_t frame, fract8 interp) {
    // Determine offset in bits, then divide by 8 for byte offset. Because NUM_LEDS
    //  is divisible by 8, LEDS*bd*frame should always be divisible by 8.
    int frame_offset = (NUM_LEDS * img.bitdepth * frame) / 8;
    uint8_t bytes_read = 0;
    uint8_t buffer_index = 0;
    uint8_t buffer = img.pixels[frame_offset];
    uint8_t paletteIndex = 0;
    for (uint8_t i = 0; i < NUM_LEDS; i++) {

        // Loop over bit depth, reading bits out of a byte buffer.
        // When the end of the byte is reached, read the next byte and reset
        // the buffer index. Use the resulting palette index to look up R/G/B from
        // the associated palette.

        for (uint8_t j = 0; j < img.bitdepth; j++) {
            if (buffer & (1 << buffer_index))
                paletteIndex |= (1 << j);
            buffer_index++;
            if (buffer_index == 8) {
                bytes_read++;
                buffer = img.pixels[frame_offset + bytes_read];
                buffer_index = 0;
            }
        }
        uint8_t r = img.palette[3 * paletteIndex + 0];
        uint8_t g = img.palette[3 * paletteIndex + 1];
        uint8_t b = img.palette[3 * paletteIndex + 2];
        leds[NUM_LEDS - 1 - i] = leds[NUM_LEDS - 1 - i].lerp8(CRGB(r, g, b), interp);
        paletteIndex = 0;
    }
}

void ImageUtils::fillPixels(CRGB* leds, ImageData img, uint16_t frame) {
    if (img.bitdepth == 24) {
        fillTruecolorPixels(leds, img, frame);
    }
    // Palettized, do lookup per pixel
    else {
        fillPalettizedPixels(leds, img, frame);
    }
}

void ImageUtils::fillPixels(CRGB* leds, ImageData img, uint16_t frame, fract8 interp) {
    if (img.bitdepth == 24) {
        fillTruecolorPixels(leds, img, frame, interp);
    }
    // Palettized, do lookup per pixel
    else {
        fillPalettizedPixels(leds, img, frame, interp);
    }
}