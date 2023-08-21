#include "playlists.h"

const uint8_t pl_white_color[] = { 0xff, 0xff, 0xff };
const uint16_t pl_white_images[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43};
const uint32_t pl_white_durations[] = {10000};
const Playlist pl_white = { pl_white_color, true, 2, 44, pl_white_durations, pl_white_images };

const uint8_t pl_red_color[] = { 0xbf, 0x00, 0x00 };
const uint16_t pl_red_images[] = {2,10,1,8,9,23,7};
const uint32_t pl_red_durations[] = {10000};
const Playlist pl_red = { pl_red_color, true, 10, 7, pl_red_durations, pl_red_images };

const uint8_t pl_2_color[] = { 0x00, 0x20, 0xdf };
const uint16_t pl_2_images[] = {4,11,3,15,17,16,14};
const uint32_t pl_2_durations[] = {10000};
const Playlist pl_2 = { pl_2_color, true, 10, 7, pl_2_durations, pl_2_images };

const uint8_t pl_4_color[] = { 0xff, 0x82, 0x00 };
const uint16_t pl_4_images[] = {25,26,27,28};
const uint32_t pl_4_durations[] = {10000};
const Playlist pl_4 = { pl_4_color, true, 10, 4, pl_4_durations, pl_4_images };

const uint8_t pl_5_color[] = { 0x14, 0xc1, 0x47 };
const uint16_t pl_5_images[] = {30,29,35,36,38,37,43};
const uint32_t pl_5_durations[] = {10000};
const Playlist pl_5 = { pl_5_color, true, 10, 7, pl_5_durations, pl_5_images };

const uint8_t pl_3_color[] = { 0xec, 0xff, 0x00 };
const uint16_t pl_3_images[] = {24,20,18,19,22,21};
const uint32_t pl_3_durations[] = {10000};
const Playlist pl_3 = { pl_3_color, true, 10, 6, pl_3_durations, pl_3_images };

const uint8_t pl_6_color[] = { 0x06, 0xb4, 0xec };
const uint16_t pl_6_images[] = {42,40};
const uint32_t pl_6_durations[] = {10000};
const Playlist pl_6 = { pl_6_color, true, 2, 2, pl_6_durations, pl_6_images };

const Playlist playlists[] = {pl_white,pl_red,pl_2,pl_4,pl_5,pl_3,pl_6};

const uint8_t num_playlists = 7;

