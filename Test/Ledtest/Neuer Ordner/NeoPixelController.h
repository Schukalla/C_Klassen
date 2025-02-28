#ifndef NEOPIXELCONTROLLER_H
#define NEOPIXELCONTROLLER_H

#include <Adafruit_NeoPixel.h>

class NeoPixelController {
public:
    NeoPixelController(uint16_t numLeds, uint8_t pin);
    void begin();
    void setPixelColor(uint16_t index, uint32_t color);
    void show();
    void clear();

    // Getter für das `strip`-Objekt
    Adafruit_NeoPixel& getStrip();

private:
    Adafruit_NeoPixel strip;
};

#endif
