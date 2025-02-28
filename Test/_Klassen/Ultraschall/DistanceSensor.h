#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include <Arduino.h>

class DistanceSensor {
public:
    DistanceSensor(int trigPin, int echoPin);
    void begin();  // Initialisiert die Pins
    bool isDistanceWithinLimit(float limit);  // Überprüft, ob der Abstand kleiner oder gleich dem Limit ist
    float getDistance();  // Gibt den gemessenen Abstand zurück

private:
    int trigPin;
    int echoPin;
    float measureDistance();  // Führt die Messung durch und gibt den Abstand zurück
};

#endif
