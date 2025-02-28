#include "LED.h"
#include <Arduino.h>

LED::LED(int p) {
    pin = p;
}

void LED::begin() {
    pinMode(pin, OUTPUT);
}

void LED::turnOn() {
    digitalWrite(pin, HIGH);
}

void LED::turnOff() {
    digitalWrite(pin, LOW);
}
