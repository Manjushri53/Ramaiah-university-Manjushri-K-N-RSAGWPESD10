const float TEMP_THRESHOLD = 30.0; 
#define TMP36_PIN A0              

void setup() {
  Serial.begin(9600);
  Serial.println("Temperature Monitoring System Started");
}

void loop() {
  int sensorValue = analogRead(TMP36_PIN);

  float voltage = sensorValue * (5.0 / 1024.0);
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  float temperature = (voltage - 0.5) * 100.0;  // Adjusted for TMP36
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature > TEMP_THRESHOLD) {
    Serial.println("Warning: High Temperature Detected!");
  }

  delay(1000);  // Delay for readability in Serial Monitor
}
