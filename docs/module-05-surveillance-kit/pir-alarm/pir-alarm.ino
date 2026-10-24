// Module 5 — Surveillance Kit: PIR motion sensor.
// HC-SR501: power to 5V and GND, output to pin 7.
// Onboard LED on pin 13 lights when motion is detected.
const int pirPin = 7;
const int ledPin = 13;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);
  digitalWrite(ledPin, motion);
  if (motion == HIGH) {
    Serial.println("Motion detected");
    delay(500);
  }
}
