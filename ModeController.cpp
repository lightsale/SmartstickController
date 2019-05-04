// 
// 
// 

#include "ModeController.h"

//BEGIN_MODE_IMPORTS
#include "PlaylistMode.h"
#include "DemoReelMode.h"
#include "SerialMonitorMode.h"
#include "ImageMode.h"
#include "FlashlightMode.h"
#include "BatteryMode.h"
#include "BrightnessMode.h"
//END_MODE_IMPORTS



void ModeController::SetupModes(CRGB* leds) {
 //BEGIN_MODE_INSTANTIATION
    modeList.push_back(&batteryMode);
    modeList.push_back(&playlistMode);
    modeList.push_back(&imageMode);
    modeList.push_back(&demoReelMode);
    modeList.push_back(&flashlightMode);
    /*modeList.push_back(&serialMonitorMode);*/
    modeList.push_back(&brightnessMode);

    for (byte i = 0; i < modeList.size(); i++) {
        modeList[i]->leds = leds;
    }

//END_MODE_INSTANTIATION
}

void ModeController::LastMode() {
    modeList[modeIndex]->active = false;
    modeIndex = lastModeIndex;
    modeList[modeIndex]->active = true;
}

Mode* ModeController::CurrentMode() {
    return modeList[modeIndex];
}

void ModeController::NextMode() {
    if ((CurrentMode() == &playlistMode) && !playlistMode.inMenu) {
        // Reset back to menu via start()
    }
    else {
        lastModeIndex = modeIndex;
        modeList[modeIndex]->active = false;
        modeIndex = (modeIndex + 1) % (modeList.size() - 1);
        modeList[modeIndex]->active = true;
    }
    CurrentMode()->start();
}

void ModeController::ActivateBrightnessMode() {
    modeList[modeIndex]->active = false;
    lastModeIndex = modeIndex;
    modeIndex = modeList.size() - 1;
    modeList[modeIndex]->active = true;
}

ModeController modeController;