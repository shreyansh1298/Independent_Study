const int mocPin = 9;

void setup() {
  pinMode(mocPin, OUTPUT);
  digitalWrite(mocPin, LOW);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Bulb ON");
  digitalWrite(mocPin, HIGH);  // Fire TRIAC
  delay(5000);

  Serial.println("Bulb OFF");
  digitalWrite(mocPin, LOW);   // Stop firing
  delay(5000);
}
