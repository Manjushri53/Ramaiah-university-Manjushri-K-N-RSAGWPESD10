#define PIR_PIN 2         // Digital pin for PIR sensor
#define BUZZER_PIN 3      // Digital pin for buzzer

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);       // Set PIR sensor as input
  pinMode(BUZZER_PIN, OUTPUT);   // Set buzzer as output
  Serial.println("Motion-Activated Alarm System Initialized");
}

void loop() {
 
  if (digitalRead(PIR_PIN) == HIGH) {
    
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);                   
    digitalWrite(BUZZER_PIN, LOW);

    // Log the timestamp in Serial Monitor
    Serial.print("Motion detected at: ");
    Serial.println(millis() / 1000); 
  }

  delay(1000); 
}
