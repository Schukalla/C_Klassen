#include "NeoPixelEffectManager.h"
// erstellt die LED Anzeigen fur 
// Temperatur innen und außen
// Feuchtigkeit innen und außen

NeoPixelEffectManager::NeoPixelEffectManager(NeoPixelController &controller) 
    : controller(controller) {}
	
void NeoPixelEffectManager::runRedLighthouseEffect(uint16_t delayMs) {
    Adafruit_NeoPixel& strip = controller.getStrip(); // Zugriff auf `strip` über Getter
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
        controller.setPixelColor(i, strip.Color(255, 0, 0)); // Rot
        controller.show();
        delay(delayMs);
        controller.setPixelColor(i, 0); // LED ausschalten
    }
}

void NeoPixelEffectManager::runBlueLighthouseEffect(uint16_t delayMs) {
    Adafruit_NeoPixel& strip = controller.getStrip(); // Zugriff auf `strip` über Getter
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
        controller.setPixelColor(i, strip.Color(0, 0, 255)); // Blau
        controller.show();
        delay(delayMs);
        controller.setPixelColor(i, 0); // LED ausschalten
    }
}



//Temperatur vorlage
void NeoPixelEffectManager::setTemperaturTemplate(){
	int arr[] = {5,10, 15, 20, 25, 30, 35, 40, 45,50, 55};
	int line = 15;
    int size = sizeof(arr) / sizeof(arr[0]);
	Adafruit_NeoPixel& strip = controller.getStrip();
    for (int i = 0; i < size; i++) {
        controller.setPixelColor(arr[i], strip.Color(0,0,30));
		controller.show();
    }
	controller.setPixelColor(line, strip.Color(255, 255, 0));
}
void NeoPixelEffectManager::setTemp(int i, int room, uint16_t delayMs){
	int line = 15;
	Adafruit_NeoPixel& strip = controller.getStrip();
	controller.setPixelColor(line + i, strip.Color(0,200,0));
	controller.show();
	
}
//Temperatur vorlage
//###########################################################################################
//Feuchtigkeit vorlage
void NeoPixelEffectManager::setHumidityTemplate(){
	Adafruit_NeoPixel& strip = controller.getStrip();
	controller.clear();
	controller.show();
}

void NeoPixelEffectManager::setRoomColors(int startIndex, int endIndex, uint32_t color) {
	
    for (int k = startIndex; k < endIndex; k++) {
        controller.setPixelColor(k, color);
		controller.show();
    }
}

//led Rot,Grün,Blau
void NeoPixelEffectManager::setHumidity(int i, int room) {
	Adafruit_NeoPixel& strip = controller.getStrip();
    if (room == 1) {
        if (i < 40) {
            setRoomColors(0, 4, strip.Color(255, 255, 0));
        } else if (i < 60) {
            setRoomColors(20, 24, strip.Color(0, 255, 0));
        } else {
            setRoomColors(40, 44, strip.Color(255, 0, 0));
        }
    } else if (room == 0) {
        if (i < 40) {
            setRoomColors(10, 14, strip.Color(255, 255, 0));
        } else if (i < 60) {
            setRoomColors(30, 34, strip.Color(0, 255, 0));
        } else {
            setRoomColors(50, 54, strip.Color(255, 0, 0));
        }
    }
}
//Feuchtigkeit vorlage
//###########################################################################################
//Uhr hour

void NeoPixelEffectManager::setClockHourTemplate(int hour) { 
	hour %= 13;
	if (hour == 0) hour = 12;
	controller.clear();
	Adafruit_NeoPixel& strip = controller.getStrip();
	for (int i = 1; i < hour + 1; i++) {
			controller.setPixelColor((i * 5)-1, strip.Color(0, 200, 0));
		}
	controller.show(); // Zeige LEDs nach der Schleife
}

void NeoPixelEffectManager::setClockHour(int hour) {
	int tmphour = hour;
	hour %= 12;
	if (hour == 0) hour = 12;
	Adafruit_NeoPixel& strip = controller.getStrip();
	if (tmphour < 0 || hour == 1) { // Validierung für Stunden
        controller.clear();
        controller.show();
    }
	controller.setPixelColor((hour * 5)-1, strip.Color(0, 200, 0)); // Besser: Farbfunktion aus Controller
    controller.show();
}

void NeoPixelEffectManager::setClockMinuteTemplate(int minute) {
	minute %= 60;
    if (minute == 0) minute == 60; 
    controller.clear();
    Adafruit_NeoPixel& strip = controller.getStrip();
    for (int i = 1; i < minute+1; i++) {
        controller.setPixelColor(i-1, strip.Color(0, 0, 200));
    }
    controller.show(); // Zeige LEDs nach der Schleife
}


void NeoPixelEffectManager::setClockMinute(int minute) {
	minute %= 60;
	if (minute == 0) minute == 60;
	Adafruit_NeoPixel& strip = controller.getStrip();
    if (minute < 0 || minute >= 59) { // Validierung für Minuten
		controller.clear();
        controller.show();
		return;
    }
    
    //controller.clear(); // Optional: entferne vorherigen Status
    controller.setPixelColor(minute-1, strip.Color(0, 0, 200)); // Besser: Farbfunktion aus Controller
    controller.show();
}
//todo bei h oder m = 0 led nix
// h, m = 1 => led = 0
//Uhr minute
//###########################################################################################



























