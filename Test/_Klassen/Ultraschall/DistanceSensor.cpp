#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(int trigPin, int echoPin)
    : trigPin(trigPin), echoPin(echoPin) {}

void DistanceSensor::begin() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float DistanceSensor::measureDistance() {
    // Trig-Puls erzeugen
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Zeit messen, wie lange das Echo-Signal aktiv ist
    long duration = pulseIn(echoPin, HIGH);

    // Entfernung berechnen (Schallgeschwindigkeit: 343 m/s oder 0.0343 cm/µs)
    return (duration * 0.0343) / 2;
}

float DistanceSensor::getDistance() {
    return measureDistance();
}

bool DistanceSensor::isDistanceWithinLimit(float limit) {
    float distance = measureDistance();
    return distance <= limit;
}
