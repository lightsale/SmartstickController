// 
// 
// 

#include "ImageMode.h"

RequestedAction ImageMode::handleInput(byte input)
{
    switch (input) {
    case singleclick:
        frame = 0;
        /*image_index = image_index+1 % ARRAY_SIZE(image_patterns);*/
        image_index = (image_index + 1) % image_count;
        break;
    case doubleclick:
        break;
    }
    return RequestedAction::donothing;
}

void ImageMode::fillLEDs()
{
    ImageData image = image_patterns[image_index];
    ImageUtils::fillPixels(leds, image, frame);
    mirrorBackHalf();
    frame = (frame + 1) % image.frames;
}

ImageMode imageMode;