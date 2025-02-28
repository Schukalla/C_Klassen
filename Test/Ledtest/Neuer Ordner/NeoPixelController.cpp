#include "NeoPixelController.h"
//Steuert die Led an

NeoPixelController::NeoPixelController(uint16_t numLeds, uint8_t pin) 
    : strip(numLeds, pin, NEO_GRB + NEO_KHZ800) {}

void NeoPixelController::begin() {
    strip.begin();
    strip.show();
}

void NeoPixelController::setPixelColor(uint16_t index, uint32_t color) {
    strip.setPixelColor(index, color);
}

void NeoPixelController::show() {
    strip.show();
}

void NeoPixelController::clear() {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0);
    }
    strip.show();
}

Adafruit_NeoPixel& NeoPixelController::getStrip() {
    return strip;
}
