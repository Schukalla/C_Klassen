#include <WiFi.h>
#include "WeatherClient.h"

// WLAN-Daten
const char* ssid = "FRITZ!Box 7530";        // Ersetze mit deinem WLAN-Namen
const char* password = "....AS..";          // Ersetze mit deinem WLAN-Passwort

// API URL
const char* apiUrl = "https://api.open-meteo.com/v1/forecast?latitude=48.9939&longitude=12.1827&current_weather=true&hourly=temperature_2m,relative_humidity_2m&forecast_days=1";

// Instanz der Wetterklasse erstellen
WeatherClient weatherClient(apiUrl);
void connectToWiFi(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);
    Serial.println("Verbinde mit WLAN...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nVerbunden mit WLAN");
    Serial.println("IP-Adresse: " + WiFi.localIP().toString());
    Serial.println(WL_CONNECTED);
}

void setup() {
    Serial.begin(9600);
    connectToWiFi(ssid, password); 

}

void loop() {
      // Wetterdaten abrufen
    if (weatherClient.fetchData()) {
        Serial.println("Wetterdaten erfolgreich abgerufen!");
        Serial.println("Aktuelle Stunde: " + weatherClient.getHour());
        Serial.println("Aktuelle Minute: " + weatherClient.getMinute());
        Serial.println("Aktuelle Temperatur: " + String(weatherClient.getTemperature()) + " °C");
        Serial.println("Aktuelle Luftfeuchtigkeit: " + String(weatherClient.getHumidity()) + " %");
        delay(1000);
    } else {
        Serial.println("Fehler beim Abrufen der Wetterdaten.");
    }
    // In diesem Beispiel bleibt die Schleife leer
}
