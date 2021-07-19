#include "playlists.h"

const uint8_t pl_white_color[] = { 0xff, 0xff, 0xff };
const uint16_t pl_white_images[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48};
const uint32_t pl_white_durations[] = {10000};
const Playlist pl_white = { pl_white_color, true, 2, 49, pl_white_durations, pl_white_images };

const uint8_t pl_red_color[] = { 0xbf, 0x00, 0x00 };
const uint16_t pl_red_images[] = {0,0,0,0};
const uint32_t pl_red_durations[] = {10000};
const Playlist pl_red = { pl_red_color, true, 2, 4, pl_red_durations, pl_red_images };

const Playlist playlists[] = {pl_white,pl_red};

const uint8_t num_playlists = 2;

