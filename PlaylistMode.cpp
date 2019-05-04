// 
// 
// 

#include "PlaylistMode.h"

void PlaylistMode::fillPlaylist() {
    Playlist playlist = playlists[playlistIndex];
    uint32_t duration = playlist.fixedDuration ? playlist.durations[0] : playlist.durations[imageIndex];
    uint32_t elapsed = millis() - lastChange;
    if (elapsed > duration && playing) {
        lastChange = millis();
        imageIndex = (imageIndex + 1) % playlist.num_images;
        frameIndex = nextFrameIndex;
        nextFrameIndex = 0;
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
    uint8_t renderIndex = 0;
    uint8_t pixelIndex;
    for (pixelIndex = 0; pixelIndex < 4; pixelIndex++) {
        leds[pixelIndex] = CRGB::White;
        if (playlistIndex == renderIndex) {
            leds[pixelIndex] = leds[pixelIndex].fadeToBlackBy(sin8(millis() / 4));
        }
    }
    for (uint8_t i = 0; i < 4; i++) {
        renderIndex++;
        uint8_t stop = pixelIndex + 5;
        for (pixelIndex; pixelIndex < stop; pixelIndex++) {
            CRGB color;
            switch (i) {
            case 0:
                color = CRGB::Red;
                break;
            case 1:
                color = CRGB::Yellow;
                break;
            case 2:
                color = CRGB::Green;
                break;
            case 3:
                color = CRGB::Blue;
                break;
            }
            leds[pixelIndex] = color;
            if (playlistIndex == renderIndex) {
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
            // During playback, single click to stop/start playback
            playing = !playing;
        }
        break;
    case doubleclick:
        if (inMenu) {
            // In menu, double click to select
            lastChange = millis();
            inMenu = false;
        }
        else {
            // During playback, doubleclick to reset to head
            imageIndex = 0;
            frameIndex = 0;
            nextFrameIndex = 0;
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