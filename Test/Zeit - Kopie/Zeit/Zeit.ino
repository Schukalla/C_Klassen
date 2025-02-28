//Libs
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino.h>
#include <TimeLib.h>

// WLAN-Daten
const char* ssid = "FRITZ!Box 7530";
const char* password = "....AS..";
const char* timeApi = "http://worldtimeapi.org/api/timezone/Europe/Berlin";

// Synchronisationsparameter
unsigned long lastSyncTime = 0;
const unsigned long syncInterval = 15 * 60 * 1000;  // 15 Minuten in Millisekunden

void setup() {
    Serial.begin(9600);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
    syncTimeFromWeb();  // Initialer Zeitsync
}

void loop() {
    now();  // Aktualisiert die interne Zeit von TimeLib
    printTime();
    
    // Prüft alle 15 Minuten, ob eine Synchronisation erforderlich ist
    if (millis() - lastSyncTime > syncInterval) {
        syncTimeFromWeb();
    }
    delay(1000);  // Sekündliches Update der Uhr
}

void syncTimeFromWeb() {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(timeApi);
        int httpCode = http.GET();
        if (httpCode > 0) {
            String payload = http.getString();
            int timeIndex = payload.indexOf("datetime");
            String dateTime = payload.substring(timeIndex + 10, timeIndex + 29);
            int year = dateTime.substring(0, 4).toInt();
            int month = dateTime.substring(5, 7).toInt();
            int day = dateTime.substring(8, 10).toInt();
            int hour = dateTime.substring(11, 13).toInt();
            int minute = dateTime.substring(14, 16).toInt();
            int second = dateTime.substring(17, 19).toInt();
            setTime(hour, minute, second, day, month, year);
            Serial.println("Time synced from web");
            lastSyncTime = millis();
        }
        http.end();
    }
}

void printTime() {
    Serial.print(hour());
    Serial.print(":");
    Serial.print(minute());
    Serial.print(":");
    Serial.println(second());
}
