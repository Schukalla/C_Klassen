
int TRIGGER_PIN =7; //Trigger-Pin Ultraschallsensors = Pin7  Arduino-Boards
int ECHO_PIN =6; //Echo-Pin Ultraschallsensors = Pin6 Arduino-Boards
long dauer=0; //Dauer = Variable, Zeit wird gespeichert, die eine Schallwelle bis zur Reflektion und zurück benötigt. Startwert ist hier 0.
long entfernung=0; //entfernung = variable („long“ damit größere Zahl gespeichert werden kann)

void setup()
{
  Serial.begin(9600); //Serielle kommunikation starten, damit man sich später die Werte am serial monitor ansehen kann.
  pinMode(TRIGGER_PIN, OUTPUT); //Trigger-Pin ist ein Ausgang
  pinMode(ECHO_PIN, INPUT); //Echo-Pin ist ein Eingang
}

void loop()
{
  digitalWrite(TRIGGER_PIN, LOW); //kurze Zeit Spannung weg vom Trigger-Pin. Damit später beim senden des Trigger-Signals ein rauschfreies Signal hat.
  delay(5); //Dauer: 5 Millisekunden
  digitalWrite(TRIGGER_PIN, HIGH); //Jetzt sendet man eine Ultraschallwelle los.
  delay(10); //Dieser „Ton“ erklingt für 10 Millisekunden.
  digitalWrite(TRIGGER_PIN, LOW); //Dann wird der „Ton“ abgeschaltet.
  dauer = pulseIn(ECHO_PIN, HIGH); //Mikrokontroller zählt Zeit in Mikrosekunden, bis der Schall zum Ultraschallsensor zurückkehrt.
  entfernung = (dauer/2) * 0.03432; //Entfernung berechnen in Zentimetern. Man teilt zunächst die Zeit durch zwei (Weil man ja nur eine Strecke berechnen möchte und nicht die Strecke hin- und zurück). Den Wert multipliziert man mit der Schallgeschwindigkeit in der Einheit Zentimeter/Mikrosekunde und erhält dann den Wert in Zentimetern.
  if (entfernung >= 500 || entfernung <= 0) 
   {
    Serial.println("Kein Messwert"); //Wenn Entfernung über 500cm oder unter 0cm liegt weil falsch oder ungenau
  }
  else
  {
    Serial.print(entfernung); //Falls nicht: Entfernung in serial monitor ausgegeben
    Serial.println(" cm"); // Hinter Entfernung im Serial Monitor Einheit "cm"
  }
  delay(1000); //Das delay von einer Sekunde
}
