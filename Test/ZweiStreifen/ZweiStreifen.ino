#include <Adafruit_NeoPixel.h>

// Pin-Definitionen für die LED-Streifen
#define LED_PIN1 5   // Pin für Streifen 1
#define LED_PIN2 16  // Pin für Streifen 2

// Anzahl der LEDs in jedem Streifen
#define NUM_LEDS1 30
#define NUM_LEDS2 30

// Initialisierung der Streifen
Adafruit_NeoPixel strip1(NUM_LEDS1, LED_PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(NUM_LEDS2, LED_PIN2, NEO_GRB + NEO_KHZ800);

void setup() {
  // LED-Streifen initialisieren
  strip1.begin();
  strip2.begin();

  // Alle LEDs ausschalten
  strip1.show();
  strip2.show();
}

void loop() {
  // Streifen 1: Rote Lauflichter
  for (int i = 0; i < NUM_LEDS1; i++) {
    strip1.setPixelColor(i, strip1.Color(255, 0, 0)); // Rot
    strip1.show();
    delay(50);
    strip1.setPixelColor(i, 0); // LED ausschalten
  }

  // Streifen 2: Blaue Lauflichter
  for (int i = 0; i < NUM_LEDS2; i++) {
    strip2.setPixelColor(i, strip2.Color(0, 0, 255)); // Blau
    strip2.show();
    delay(50);
    strip2.setPixelColor(i, 0); // LED ausschalten
  }
}
