// Module 4 — Eyes and Ears: passive buzzer plays a scale.
// Passive buzzer: one side to pin 8, other side to GND.
// Do not use analogWrite for tones: its frequency is fixed at ~500 Hz.
const int buzzerPin = 8;
const int notes[] = {523, 587, 659, 698, 784, 880, 988, 1047};

void setup() {
}

void loop() {
  for (int i = 0; i < 8; i++) {
    tone(buzzerPin, notes[i]);
    delay(500);
  }
  noTone(buzzerPin);
  delay(1000);
}
