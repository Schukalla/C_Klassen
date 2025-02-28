#include <Arduino.h>
#include "DistanceSensor.h"

#define TRIG_PIN 17  // Pin für Trig-Signal
#define ECHO_PIN 2   // Pin für Echo-Signal

DistanceSensor sensor(TRIG_PIN, ECHO_PIN);  // Instanz der Klasse erstellen
const float DISTANCE_LIMIT = 50.0;         // Abstandslimit in cm

void setup() {
    Serial.begin(9600);  // Startet die serielle Kommunikation
    sensor.begin();      // Initialisiert den Sensor
}

void loop() {
    // Abstand messen und prüfen, ob er innerhalb des Limits liegt
    bool withinLimit = sensor.isDistanceWithinLimit(DISTANCE_LIMIT);
    float distance = sensor.getDistance();

    // Ergebnis ausgeben
    Serial.print("Gemessener Abstand: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (withinLimit) {
        Serial.println("Abstand ist innerhalb des Limits.");
    } else {
        Serial.println("Abstand überschreitet das Limit!");
    }

    delay(2000);  // Warte 2 Sekunden, bevor die nächste Messung erfolgt
}
