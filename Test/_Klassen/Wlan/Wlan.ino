#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Adafruit_NeoPixel.h>

// Replace with your network credentials
const char* ssid     = "FRITZ!Box 7530";
const char* password = "....AS..";
// Konfiguration
#define PIN 15               // Datenleitung an Pin 15 des ESP32
#define NUM_LEDS 60          // Anzahl der LEDs im Streifen

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// Variables to save date and time
String formattedDate;
String dayStamp;
String timeStamp;
int hours = 0;
int minutes = 0;
int seconds = 0;
int last_second = 0;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

// Initialize a NTPClient to get time
  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
  timeClient.setTimeOffset(3600);
}
void loop() {
  timeClient.update();  // Hole die aktuelle Zeit
  
  // Hole die formatierte Zeit
  String formattedDate = timeClient.getFormattedTime();
  Serial.println(formattedDate);
  // Zeit im Format HH:MM:SS splitten
  int hourPos = formattedDate.indexOf(':');
  int minutePos = formattedDate.indexOf(':', hourPos + 1);
  
  // Extrahiere Stunden, Minuten und Sekunden
  hours = formattedDate.substring(0, hourPos).toInt();
  minutes = formattedDate.substring(hourPos + 1, minutePos).toInt();
  seconds = formattedDate.substring(minutePos + 1).toInt();
  
  // Ausgabe der extrahierten Stunden, Minuten und Sekunden
  Serial.print("Stunden: ");
  Serial.print(hours);
  Serial.print(", Minuten: ");
  Serial.print(minutes);
  Serial.print(", Sekunden: ");
  Serial.println(seconds);

  singlepin(seconds, minutes);            // Nacheinander LEDs einschalten
  delay(1000);  // 1 Sekunde warten

}

int last_minute = -1;

void singlepin(int seconds, int minutes) {
    // Sekunden-LED aktualisieren, wenn sich die Sekunde ändert
    if (seconds != last_second) {
        if (last_second >= 0) {
            strip.setPixelColor(last_second, strip.Color(0, 0, 0)); // Schaltet die alte LED aus
        }
        int seconds_led = NUM_LEDS - seconds - 1; // Berechnet die aktuelle Sekunden-LED
        strip.setPixelColor(seconds_led, strip.Color(0, 0, 255)); // Beleuchtet die neue Sekunden-LED
        last_second = seconds; // Aktualisiert die gespeicherte Sekunde
    }

    // Minuten-LED aktualisieren, wenn sich die Minute ändert
    if (minutes != last_minute) {
        // lösche minuten leiste
        for (int i = 0; i < NUM_LEDS; i++) { 
            strip.setPixelColor(i, strip.Color(0, 0, 0));
        }
        strip.show();

        for (int i = 0; i < minutes; i++){
          strip.setPixelColor(minutes, strip.Color(0, 0, 255)); // Beleuchtet die neue Minuten-LED
        }
        strip.show();
        
        last_minute = minutes; // Aktualisiert die gespeicherte Minute




    }

    // LEDs anzeigen (einmaliger Aufruf für beide Änderungen)
    strip.show();
}

