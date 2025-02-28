#ifndef LED_H
#define LED_H

class LED {
private:
    int pin;

public:
    LED(int p);
    void begin();
    void turnOn();
    void turnOff();
};

#endif
