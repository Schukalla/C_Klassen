#include "NeoPixelController.h"
#include "NeoPixelEffectManager.h"

// LED-Streifen 1
NeoPixelController strip1(60, 5);
// LED-Streifen 2
NeoPixelController strip2(60, 16);

// Effektmanager
NeoPixelEffectManager effectManager1(strip1);
NeoPixelEffectManager effectManager2(strip2);

bool startTemp = true;
bool startHumidity = true;
bool startTime = true;

void setup() {
    strip1.begin();
    strip2.begin();
}

int minute = 40;
int hour = 1;
void loop() {
  
}
