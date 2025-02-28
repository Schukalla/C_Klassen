#include <Arduino.h>
#include "LightSensor.h"

// Definiere die Pins für den Lichtsensor und das Potentiometer
#define LIGHT_SENSOR_PIN 36  // Beispiel Pin für den Lichtsensor
#define POTENTIOMETER_PIN 39 // Beispiel Pin für das Potentiometer

LightSensor lightSensor(LIGHT_SENSOR_PIN, POTENTIOMETER_PIN); // Erstelle ein LightSensor-Objekt

void setup() {
    Serial.begin(9600);  // Starte serielle Kommunikation
    lightSensor.begin(); // Initialisiere den Sensor
}

void loop() {
    int brightnessValue = lightSensor.brightness();  // Helligkeit berechnen

    // Ausgabe des berechneten Helligkeitswerts
    Serial.print("Kombinierte Helligkeit: ");
    Serial.println(brightnessValue);

    delay(1000);  // 1 Sekunde warten, bevor die nächste Messung erfolgt
}
