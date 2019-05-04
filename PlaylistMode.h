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

