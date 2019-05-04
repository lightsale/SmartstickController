

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