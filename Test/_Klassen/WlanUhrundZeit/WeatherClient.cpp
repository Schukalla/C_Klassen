#include "WeatherClient.h"

WeatherClient::WeatherClient(const char* apiUrl) : apiUrl(apiUrl), temperature(0), humidity(0) {}

bool WeatherClient::fetchData() {
    HTTPClient http;
    http.begin(apiUrl);  // URL der REST API
    int httpCode = http.GET();  // GET-Anfrage senden

    if (httpCode == 200) {
        String payload = http.getString();  // Die Antwort als String speichern
        parseJson(payload);  // JSON-Daten verarbeiten
        http.end();  // Verbindung schließen
        return true;
    } else {
        http.end();  // Verbindung schließen
        return false;
    }
}

void WeatherClient::parseJson(const String& payload) {
    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, payload);

    if (error) {
        hour = "";
        minute = "";
        temperature = 0;
        humidity = 0;
        return;
    }

    const char* time = doc["current_weather"]["time"];  // Zeit (ISO8601)
    temperature = doc["current_weather"]["temperature"];  // Temperatur
    humidity = doc["hourly"]["relative_humidity_2m"][0];  // Luftfeuchtigkeit

    String currentTime = String(time);  // Zeit als String speichern
    hour = currentTime.substring(11, 13);  // Stunde extrahieren
    minute = currentTime.substring(14, 16);  // Minute extrahieren
}

String WeatherClient::getHour() {
    return hour;
}

String WeatherClient::getMinute() {
    return minute;
}

float WeatherClient::getTemperature() {
    return temperature;
}

float WeatherClient::getHumidity() {
    return humidity;
}
