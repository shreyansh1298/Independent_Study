const int lm35Pin = A1;
const int mocPin = 9;
const int peltierPin = 8;

const float targetTemp = 35.0;
const float hysteresis = 1.0;

unsigned long startTime;

void setup() {
  Serial.begin(9600);
  pinMode(mocPin, OUTPUT);
  pinMode(peltierPin, OUTPUT);
  digitalWrite(mocPin, LOW);
  digitalWrite(peltierPin, LOW);
  startTime = millis();

  Serial.println("Time (s),Temperature (C),IR Bulb Status");
}

void loop() {
  int temp_adc_val = analogRead(lm35Pin);
  float temp_val = (temp_adc_val * 4.88) / 10.0;
  int status = 0;

  if (temp_val < targetTemp - hysteresis) {
    digitalWrite(mocPin, HIGH);
    digitalWrite(peltierPin, HIGH);
    status = 1;
  } else if (temp_val > targetTemp + hysteresis) {
    digitalWrite(mocPin, LOW);
    digitalWrite(peltierPin, LOW);
    status = 0;
  }

  float elapsed = (millis() - startTime) / 1000.0;
  Serial.print(elapsed, 2); Serial.print(",");
  Serial.print(temp_val, 2); Serial.print(",");
  Serial.println(status);

  delay(1000);
}
