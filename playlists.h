// playlists.h


#ifndef _PLAYLISTS_h
#define _PLAYLISTS_h
#include <stdint.h>

struct Playlist {
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