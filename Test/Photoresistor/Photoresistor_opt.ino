// Konstanten
const int sensorPin = A0;    // Pin für den Sensor
const int ledPin = 9;        // Pin für die LED

// Variablen
int sensorValue = 0;         // Sensorwert
int sensorMin = 1023;        // Minimaler Sensorwert
int sensorMax = 0;           // Maximaler Sensorwert

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Signalisiert den Start der Kalibrierung
  digitalWrite(LED_BUILTIN, HIGH);
  
  // Kalibrieren des Sensors
  calibrateSensor(sensorPin, sensorMin, sensorMax, 5000);

  // Signalisiert das Ende der Kalibrierung
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // Sensorwert lesen und kalibrieren
  sensorValue = analogRead(sensorPin);
  sensorValue = mapSensorValue(sensorValue, sensorMin, sensorMax, 0, 255);

  // LED-Helligkeit einstellen
  analogWrite(ledPin, sensorValue);

  // Kurze Verzögerung
  delay(50);
}

// Funktion zur Kalibrierung des Sensors
void calibrateSensor(int pin, int& minVal, int& maxVal, unsigned long duration) {
  unsigned long startTime = millis();
  
  while (millis() - startTime < duration) {
    int value = analogRead(pin);

    // Aktualisiere Minimal- und Maximalwerte
    minVal = min(minVal, value);
    maxVal = max(maxVal, value);
  }
}

// Funktion zum Mappen und Begrenzen des Sensorwerts
int mapSensorValue(int value, int minVal, int maxVal, int newMin, int newMax) {
  // Wert auf neuen Bereich mappen
  int mappedValue = map(value, minVal, maxVal, newMin, newMax);
  
  // Begrenzung sicherstellen
  return constrain(mappedValue, newMin, newMax);
}
