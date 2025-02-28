// Potentiometer einlesen
// Batch von Tobias Tippait, 2020

const int Poti = A0; // Pin, an dem das Potentiometer angeschlossen ist
int potiWert = 0; // Initialwert des Potentiometer-Werts
float potiWertAnzeige = 0; // Variable für die Ausgabe im seriellen Monitor

void setup() {
  // Setup-Code, der einmal ausgeführt wird
  Serial.begin(9600); // Datenrate für die serielle Kommunikation (9600 Baud)
  Serial.println("Programmstart: Potentiometer einlesen");
}

void loop() {
  // Potentiometer-Wert einlesen
  potiWert = analogRead(Poti);
  Serial.println(potiWert);
  // Umrechnung des Potentiometer-Werts in eine Spannung (0–5 V)
  potiWertAnzeige = ((float)potiWert / 1023.0) * 5.0;
  
  // Ausgabe des Werts auf den seriellen Monitor
  Serial.println(potiWertAnzeige);
  
  // Verzögerung von 100 ms
  delay(100);
}
