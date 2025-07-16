const int lm35_pin = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int temp_adc_val;
  float temp_val;

  temp_adc_val = analogRead(lm35_pin);
  temp_val = (temp_adc_val * 4.88) / 10.0;  // Convert ADC to °C

  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.println(" °C");

  delay(1000);
}
