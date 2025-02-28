#include "NeoPixelController.h"
#include "NeoPixelEffectManager.h"

// LED-Streifen 1
NeoPixelController strip1(60, 5);
// LED-Streifen 2
NeoPixelController strip2(60, 16);

// Effektmanager
NeoPixelEffectManager effectManager1(strip1);
NeoPixelEffectManager effectManager2(strip2);

bool startTemp = true;
bool startHumidity = true;
bool startTime = true;

void setup() {
    strip1.begin();
    strip2.begin();
}

int minute = 40;
int hour = 1;
void loop() {
    //effectManager1.runRedLighthouseEffect(50);
    //effectManager2.runBlueLighthouseEffect(50);
	
	//Temp
	int ii = 0;
	if(ii == 1){
		if (startTemp){
			effectManager1.setTemperaturTemplate();
			startTemp = false;
			startTime = true;
		}
		effectManager1.setTemp(10,1,100); //pin, raum, delay
		effectManager1.setTemp(-4,1,100); //pin, raum, delay
		delay(1000);
		
		//Humidity
		if(startHumidity){
			effectManager2.setHumidityTemplate();
			startHumidity = false;
		}	
		effectManager2.setHumidity(30,1); //pin, raum, delay
		effectManager2.setHumidity(50,1); //pin, raum, delay
		effectManager2.setHumidity(70,1); //pin, raum, delay
		
		effectManager2.setHumidity(30,0); //pin, raum, delay
		effectManager2.setHumidity(50,0); //pin, raum, delay
		effectManager2.setHumidity(70,0); //pin, raum, delay
	}else{
		
		if (startTime){
			effectManager1.setClockHourTemplate(hour);
			effectManager2.setClockMinuteTemplate(minute);
			startTime = false;
			startTemp = true;
			startHumidity = true;			
		}
		effectManager2.setClockMinute(minute);
		effectManager1.setClockHour(hour);
		delay(20);
		minute++;
		if (minute >= 60){
			minute = 0;
			hour++;
		}
		if (hour >= 13){
			hour = 1;
		}
		printf("min: %d\n", minute); 
		printf("h: %d\n", hour); 
	}
	
}
