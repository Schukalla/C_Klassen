#include <FastLED.h>

// LED Setup
#define LED_PIN     15          // GPIO 15 für den Daten-Pin
#define NUM_LEDS    300         // 5m * 60 LEDs/m
#define BRIGHTNESS  120         // Maximale Helligkeit
#define LED_TYPE    WS2812B     
#define COLOR_ORDER GRB        

CRGB leds[NUM_LEDS];
unsigned long previousMillis = 0;
const long interval = 60000;   // 1 Minute (60000 ms)
int currentEffect = 0;

// Setup
void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
}

// Loop
void loop() {
  unsigned long currentMillis = millis();
  
  // Wechsel der Effekte alle 60 Sekunden
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    currentEffect++;
    if (currentEffect > 9) {  // 10 Effekte (0-9)
      currentEffect = 0;
    }
  }
  
  // Auswahl des aktuellen Effekts
  switch (currentEffect) {
    case 0: rainbowCycle(); break;
    case 1: waveEffect(); break;
    case 2: alternateBlink(); break;
    case 3: theaterChase(); break;
    case 4: colorWipe(CRGB::Purple); break;
    case 5: confetti(); break;
    case 6: sinelon(); break;
    case 7: bpm(); break;
    case 8: juggle(); break;
    case 9: sparkle(); break;
  }
  FastLED.show();
  delay(20);  // Sanfte Animationen
}

// 1. Regenbogen-Effekt (läuft langsam über alle LEDs)
void rainbowCycle() {
  static uint8_t hue = 0;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV((hue + i * 5) % 255, 255, 255);
  }
  hue++;
}

// 2. Wellen-Effekt (maximal 60 LEDs gleichzeitig)
void waveEffect() {
  static uint8_t pos = 0;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = (i >= pos && i < pos + 60) ? CRGB(CHSV(i * 10, 255, 255)) : CRGB::Black;
  }
  pos = (pos + 1) % (NUM_LEDS - 60);
}

// 3. Blinkender Effekt mit abwechselnden Farben
void alternateBlink() {
  static bool state = false;
  for (int i = 0; i < NUM_LEDS; i += 2) {
    leds[i] = state ? CRGB::Red : CRGB::Black;
    leds[i + 1] = state ? CRGB::Blue : CRGB::Black;
  }
  state = !state;
  delay(500);
}

// 4. Theater-Chase-Effekt (Lauflicht mit Lücken)
void theaterChase() {
  static uint8_t q = 0;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ((i + q) % 3 == 0) ? CRGB::Green : CRGB::Black;
  }
  q = (q + 1) % 3;
  delay(50);
}

// 5. Farbwisch-Effekt (Wipe-Effekt von links nach rechts)
void colorWipe(CRGB color) {
  static int pos = 0;
  leds[pos] = color;
  pos++;
  if (pos >= NUM_LEDS) pos = 0;
}

// 6. Konfetti-Effekt (zufällige Farben)
void confetti() {
  fadeToBlackBy(leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV(random8(255), 200, 255);
}

// 7. Sinuslauf (Einzelne LED bewegt sich)
void sinelon() {
  fadeToBlackBy(leds, NUM_LEDS, 20);
  int pos = beatsin16(13, 0, NUM_LEDS - 1);
  leds[pos] += CHSV(millis() / 10, 255, 192);
}

// 8. Beat-basierter Effekt (Pulsieren in Farbe)
void bpm() {
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8(BeatsPerMinute, 64, 255);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(palette, i + beat, 255);
  }
}

// 9. Jonglier-Effekt (laufende Punkte)
void juggle() {
  fadeToBlackBy(leds, NUM_LEDS, 20);
  byte dothue = 0;
  for (int i = 0; i < 8; i++) {
    leds[beatsin16(i + 7, 0, NUM_LEDS - 1)] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}

// 10. Funkel-Effekt (zufälliges Funkeln)
void sparkle() {
  fadeToBlackBy(leds, NUM_LEDS, 10);
  if (random8() < 50) {
    int pos = random16(NUM_LEDS);
    leds[pos] += CRGB::White;
  }
}
