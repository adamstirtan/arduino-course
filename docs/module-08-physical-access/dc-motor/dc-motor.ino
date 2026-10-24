// Module 8 — Physical Access: DC motor via L293D.
// L293D: Enable -> pin 3 (PWM, speed), In1 -> pin 4, In2 -> pin 5.
// Motor power comes from a separate battery pack; tie its ground
// to the UNO's ground. Never power the motor from an UNO pin.
const int enablePin = 3;
const int in1Pin = 4;
const int in2Pin = 5;

void drive(int speed, bool forward) {
  digitalWrite(in1Pin, forward ? HIGH : LOW);
  digitalWrite(in2Pin, forward ? LOW : HIGH);
  analogWrite(enablePin, speed);
}

void setup() {
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
}

void loop() {
  drive(200, true);
  delay(2000);
  drive(0, true);
  delay(500);
  drive(200, false);
  delay(2000);
  drive(0, false);
  delay(500);
}
