#include <Adafruit_NeoPixel.h>

// Konfiguration
#define PIN 16               // Datenleitung an Pin 15 // RX2
#define NUM_LEDS 120          // Anzahl der LEDs im Streifen

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();             // Initialisiert den LED-Streifen
  strip.show();              // Schaltet alle LEDs aus
}

void loop() {
  singlepin(1000);            // Nacheinander LEDs einschalten
  // rainbowCycle(10);       // Optional: Regenbogeneffekt
}


// LEDs nacheinander an- und ausschalten
void singlepin(uint8_t wait) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 100)); // Setzt LED i auf Blau
    strip.show();
    delay(wait);
    strip.setPixelColor(i, strip.Color(0, 0, 0)); // Schaltet LED i aus
    strip.show();
  }
}
