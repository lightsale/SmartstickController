#include "playlists.h"

const uint16_t pl_white_images[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
const uint32_t pl_white_durations[] = {10000};
const Playlist pl_white = { true, 2, 27, pl_white_durations, pl_white_images };

const uint16_t pl_red_images[] = {};
const uint32_t pl_red_durations[] = {10000};
const Playlist pl_red = { true, 2, 0, pl_red_durations, pl_red_images };

const uint16_t pl_yellow_images[] = {};
const uint32_t pl_yellow_durations[] = {};
const Playlist pl_yellow = { false, 0, 0, pl_yellow_durations, pl_yellow_images };

const uint16_t pl_green_images[] = {};
const uint32_t pl_green_durations[] = {};
const Playlist pl_green = { false, 3, 0, pl_green_durations, pl_green_images };

const uint16_t pl_blue_images[] = {};
const uint32_t pl_blue_durations[] = {8000};
const Playlist pl_blue = { true, 0, 0, pl_blue_durations, pl_blue_images };

const Playlist playlists[] = {pl_white,pl_red,pl_yellow,pl_green,pl_blue};

const uint8_t num_playlists = 5;

