const int peltierPin = 8;

void setup() {
  pinMode(peltierPin, OUTPUT);
  digitalWrite(peltierPin, HIGH);
  delay(5000);
  digitalWrite(peltierPin, LOW);
}

void loop() {
  // Do nothing
}
