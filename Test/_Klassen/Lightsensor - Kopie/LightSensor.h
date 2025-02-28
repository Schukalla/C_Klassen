#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include <Arduino.h>

class LightSensor {
public:
    // Konstruktor mit den Pins für den Lichtsensor und das Potentiometer
    LightSensor(int lightPin, int potentiometerPin);
    
    // Initialisierungsmethode
    void begin();

    // Methode zur Berechnung der Helligkeit (kombiierter Wert)
    int brightness();

private:
    int lightSensorPin;      // Pin für den Lichtsensor
    int potentiometerPin;    // Pin für das Potentiometer
};

#endif
