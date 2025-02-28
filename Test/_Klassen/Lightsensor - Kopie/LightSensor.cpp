#include "LightSensor.h"

LightSensor::LightSensor(int lightPin, int potentiometerPin) 
  : lightSensorPin(lightPin), potentiometerPin(potentiometerPin) {}

void LightSensor::begin() {
    analogSetAttenuation(ADC_11db); // Setzt die ADC-Attenuation für höhere Spannungseingänge
}

int LightSensor::brightness() {
    int readLightRawValue = analogRead(lightSensorPin);  // Liest den Rohwert des Lichtsensors
    int potentiometerValue = analogRead(potentiometerPin); // Liest den Wert des Potentiometers

    int value = readLightRawValue + potentiometerValue; // Summiere die Werte der beiden Sensoren
    value = value * 255 / 7000;
    if (value > 255){value = 255;}
    // Du kannst hier auch eine Art Durchschnitt oder eine Skalierung hinzufügen, wenn nötig
    return value;  // Gibt den kombinierten Wert zurück
}

