#ifndef WEATHER_CLIENT_H
#define WEATHER_CLIENT_H

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

class WeatherClient {
public:
    WeatherClient(const char* apiUrl);
    bool fetchData();  // Ruft Wetterdaten ab
    String getHour();  // Gibt die aktuelle Stunde zurück
    String getMinute();  // Gibt die aktuelle Minute zurück
    float getTemperature();  // Gibt die aktuelle Temperatur zurück
    float getHumidity();  // Gibt die aktuelle relative Luftfeuchtigkeit zurück

private:
    const char* apiUrl;
    String hour;
    String minute;
    float temperature;
    float humidity;

    void parseJson(const String& payload);  // Hilfsfunktion zum JSON-Parsen
};

#endif
