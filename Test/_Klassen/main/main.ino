#include "LED.h"

LED myLED(13);

void setup() {
    myLED.begin();
}

void loop() {
    myLED.turnOn();
    delay(500);
    myLED.turnOff();
    delay(500);
}
