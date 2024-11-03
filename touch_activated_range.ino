// Pin Definitions
const int trigPin = 9;         
const int echoPin = 10;        
const int touchPin = 2;      
const int segmentPins[] = {3, 4, 5, 6, 7, 8}; 

// 7-segment display digit representation
const byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 0, 0, 1, 1}  // 9
};

void setup() {
  // Initialize pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(touchPin, INPUT);
  
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(touchPin) == HIGH) {
    long duration, distance;

    // Trigger ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the echo
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2; // Calculate distance in cm

    // Display the distance
    displayNumber(distance);

    // Wait for 5 seconds before clearing the display
    delay(5000);
    clearDisplay();
  }
}

void displayNumber(long num) {
  if (num < 0 || num > 9) return; // Adjust based on your display (0-99 for two digits)

  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[num][i]);
  }
}

void clearDisplay() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], LOW);
  }
}
