// Module 5 — Surveillance Kit: the surveillance post.
// PIR output -> pin 7. HC-SR04: Trig -> pin 12, Echo -> pin 11.
// Passive buzzer -> pin 8 (tone()).
// Alarm sounds only when motion is detected AND the object is
// closer than 50 cm.
const int pirPin = 7;
const int trigPin = 12;
const int echoPin = 11;
const int buzzerPin = 8;

long measureDistanceCm() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration / 58;
}

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  if (digitalRead(pirPin) == HIGH) {
    long distance = measureDistanceCm();
    Serial.print("Motion at ");
    Serial.print(distance);
    Serial.println(" cm");
    if (distance > 0 && distance < 50) {
      tone(buzzerPin, 880);
      delay(1000);
      noTone(buzzerPin);
    }
  }
  delay(200);
}
