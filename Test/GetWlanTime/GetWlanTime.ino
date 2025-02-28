#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

class TimeClient {
public:
    TimeClient(const char* apiUrl);
    bool fetchData();
    int getHour();
    int getMinute();

private:
    void parseJson(const String& payload);
    const char* apiUrl;
    int hour;
    int minute;
};

TimeClient::TimeClient(const char* apiUrl) : apiUrl(apiUrl), hour(0), minute(0) {}

bool TimeClient::fetchData() {
    HTTPClient http;
    http.begin(apiUrl);
    int httpCode = http.GET();

    if (httpCode == 200) {
        String payload = http.getString();
        Serial.println(payload);
        parseJson(payload);
        http.end();
        return true;
    } else {
        http.end();
        return false;
    }
}

void TimeClient::parseJson(const String& payload) {
    StaticJsonDocument<512> doc;
    DeserializationError error = deserializeJson(doc, payload);

    if (error) {
        hour = 0;
        minute = 0;
        return;
    }

    const char* timeString = doc["dateTime"].as<const char*>();
    String currentTime = String(timeString);
    Serial.println(currentTime.substring(11, 13));
    Serial.println(currentTime.substring(14, 16));
    hour = currentTime.substring(11, 13).toInt();
    minute = currentTime.substring(14, 16).toInt();
}

int TimeClient::getHour() {
    return hour;
}

int TimeClient::getMinute() {
    return minute;
}

const char* ssid = "FRITZ!Box 7530";
const char* password = "....AS..";
const char* timeApi = "https://timeapi.io/api/time/current/coordinate?latitude=48.9939&longitude=12.1827";

TimeClient timeClient(timeApi);

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Verbindung zu WiFi wird hergestellt...");
    }
    Serial.println("Verbunden mit dem WiFi-Netzwerk");
}

void loop() {
    if (timeClient.fetchData()) {
      
        int hour = timeClient.getHour();
        int minute = timeClient.getMinute();
        Serial.printf("Aktuelle Zeit: %02d:%02d\n", hour, minute);
    } else {
        Serial.println("Fehler beim Abrufen der Zeit");
    }
    delay(1000); // Aktualisierung alle 15 Minuten
}
