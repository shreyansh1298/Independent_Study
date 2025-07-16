const int lm35Pin = A1;       // Temperature sensor
const int mocPin = 9;         // IR Bulb (MOC3083)
const int peltierPin = 8;     // Peltier (MOSFET)
// const int pumpPin = 7;     // Optional: Water Pump

const float targetTemp = 35.0; // Desired temp in Celsius
const float hysteresis = 1.0;  // ±1°C hysteresis

void setup() {
  Serial.begin(9600);
  pinMode(mocPin, OUTPUT);
  pinMode(peltierPin, OUTPUT);
  // pinMode(pumpPin, OUTPUT);

  digitalWrite(mocPin, LOW);
  digitalWrite(peltierPin, LOW);
  // digitalWrite(pumpPin, LOW);
}

void loop() {
  int temp_adc_val = analogRead(lm35Pin);
  float temp_val = (temp_adc_val * 4.88) / 10.0;

  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.print(" °C\t");

  // Control Logic
  if (temp_val < targetTemp - hysteresis) {
    digitalWrite(mocPin, HIGH);
    digitalWrite(peltierPin, HIGH);
    // digitalWrite(pumpPin, HIGH);
    Serial.println("Heating ON");
  } else if (temp_val > targetTemp + hysteresis) {
    digitalWrite(mocPin, LOW);
    digitalWrite(peltierPin, LOW);
    // digitalWrite(pumpPin, LOW);
    Serial.println("Heating OFF");
  }

  delay(1000);
}
