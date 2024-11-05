const int pirPin = 2;        // PIR sensor output pin
const int buzzerPin = 3;     // Buzzer pin

void setup() {
    // Initialize serial communication for logging timestamps
    Serial.begin(9600);

    // Set PIR sensor and buzzer pins
    pinMode(pirPin, INPUT);
    pinMode(buzzerPin, OUTPUT);

    // Initial message
    Serial.println("Motion-Activated Alarm System");
    Serial.println("Waiting for motion...");
}

void loop() {
    // Read the PIR sensor
    int motionDetected = digitalRead(pirPin);

    // Check if motion is detected
    if (motionDetected == HIGH) {
        // Activate the buzzer
        digitalWrite(buzzerPin, HIGH);

        // Log the timestamp to the Serial Monitor
        unsigned long timestamp = millis();  // Get current time in milliseconds
        Serial.print("Motion detected at: ");
        Serial.print(timestamp / 1000);  // Convert milliseconds to seconds
        Serial.println(" seconds");

        // Keep the buzzer on for a short duration
        delay(1000);  // Buzzer sounds for 1 second

        // Turn off the buzzer
        digitalWrite(buzzerPin, LOW);
    }

    // Small delay to prevent excessive triggering
    delay(200);
}
