const int soundSensorPin = A0; // Analog pin connected to the sound sensor
const int ledPin = 13;         // Pin connected to the LED
const int buzzerPin = 8;       // Pin connected to the buzzer
const int threshold = 30;     // Sound threshold value (adjust as needed)
const int buzzerFrequency = 2000; // Frequency in Hertz
const int buzzerDuration = 100;   // Duration in milliseconds

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  int soundValue = analogRead(soundSensorPin);
  Serial.println(soundValue); // Print the analog value of the sound sensor to the Serial Monitor

  if (soundValue > threshold) { // If sound intensity exceeds the threshold
    for (int i = 0; i < 15; i++) { // Flash the LED and buzz rapidly 10 times
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, buzzerFrequency, buzzerDuration); // Produce sound at specified frequency and duration
      delay(buzzerDuration);
      digitalWrite(ledPin, LOW);
      noTone(buzzerPin); // Stop the buzzer sound
      delay(buzzerDuration); // Off for 100 milliseconds
    }
    Serial.println("Sound detected! LED flashing and buzzer buzzing.");
  } else {
    digitalWrite(ledPin, LOW); // Ensure LED is off if no sound is detected
    noTone(buzzerPin); // Ensure buzzer is off if no sound is detected
  }
}
