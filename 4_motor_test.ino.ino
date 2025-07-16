const int pumpPin = 7;

void setup() {
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, HIGH); // Pump ON
  delay(3000);
  digitalWrite(pumpPin, LOW);  // Pump OFF
}

void loop() {
  // Leave empty
}
