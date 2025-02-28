#include <Adafruit_NeoPixel.h>

// Konfiguration
#define PIN 15               // Datenleitung an Pin 15 des ESP32
#define NUM_LEDS 60          // Anzahl der LEDs im Streifen

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();             // Initialisiert den LED-Streifen
  strip.show();              // Schaltet alle LEDs aus
}

void loop() {
  rainbowCycle(10);          // Regenbogenanimation mit einer Verzögerung von 10 ms
}

// Regenbogenzyklus für den LED-Streifen
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 komplette Regenbogenzyklen
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Farb-Rad für Regenbogen-Effekte
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
    WheelPos -= 170;
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}
