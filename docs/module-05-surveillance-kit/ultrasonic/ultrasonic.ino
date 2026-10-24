// Module 5 — Surveillance Kit: HC-SR04 ultrasonic distance.
// Vcc -> 5V, Gnd -> GND, Trig -> pin 12, Echo -> pin 11.
const int trigPin = 12;
const int echoPin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distanceCm = duration / 58;
  Serial.print(distanceCm);
  Serial.println(" cm");
  delay(200);
}
