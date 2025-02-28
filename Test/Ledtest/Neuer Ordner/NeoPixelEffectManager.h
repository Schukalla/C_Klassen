#ifndef NEOPIXELEFFECTMANAGER_H
#define NEOPIXELEFFECTMANAGER_H

#include "NeoPixelController.h"

class NeoPixelEffectManager {
public:
    NeoPixelEffectManager(NeoPixelController &controller);
    void runRedLighthouseEffect(uint16_t delayMs);
    void runBlueLighthouseEffect(uint16_t delayMs);
	//Temperature	
	void setTemperaturTemplate();
	void setTemp(int i, int room, uint16_t delayMs);
	//Humidity
	void setHumidityTemplate();
	void setHumidity(int i, int room);
	void setRoomColors(int startIndex, int endIndex, uint32_t color);
	//Clock
	void setClockHourTemplate(int hour);
	void setClockHour(int hour);
	void setClockMinuteTemplate(int minute);
	void setClockMinute(int minute);
private:
    NeoPixelController &controller;
};

#endif
