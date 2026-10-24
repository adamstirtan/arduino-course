// The Finale — The Job: vault door system.
// PIR output -> pin 2. HC-SR04: Trig -> pin 3, Echo -> pin 4.
// Servo (bolt) -> pin 5, powered from a separate pack (grounds tied).
// LCD: RS -> pin 6, EN -> pin 7, D4 -> A0, D5 -> A1, D6 -> A2, D7 -> A3,
// plus 5V, GND, contrast pot on VO.
// Passive buzzer -> pin 8.
// RC522: SS -> pin 10, RST -> pin 9, MOSI -> pin 11, MISO -> pin 12,
// SCK -> pin 13, VCC -> 3.3V (NOT 5V), GND -> GND.
// RTC: SDA -> A4, SCL -> A5, VCC -> 5V, GND -> GND.
// Libraries: RTClib, MFRC522, LiquidCrystal, Servo.
// Replace ALLOWED_UID with your own card's UID (Module 7 reader sketch).
// Set the RTC once with rtc.adjust(), then comment it out and re-upload.
#include <Wire.h>
#include <RTClib.h>
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9

RTC_DS1307 rtc;
MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal lcd(6, 7, A0, A1, A2, A3);
Servo bolt;

const int pirPin = 2;
const int trigPin = 3;
const int echoPin = 4;
const int servoPin = 5;
const int buzzerPin = 8;

byte allowedUid[4] = {0xDE, 0xAD, 0xBE, 0xEF};

bool uidMatches() {
  if (rfid.uid.size != 4) return false;
  for (byte i = 0; i < 4; i++) {
    if (rfid.uid.uidByte[i] != allowedUid[i]) return false;
  }
  return true;
}

long measureDistanceCm() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) / 58;
}

void showTime(DateTime now) {
  lcd.setCursor(0, 0);
  lcd.print("ARMED ");
  if (now.hour() < 10) lcd.print('0');
  lcd.print(now.hour());
  lcd.print(':');
  if (now.minute() < 10) lcd.print('0');
  lcd.print(now.minute());
  lcd.print(':');
  if (now.second() < 10) lcd.print('0');
  lcd.print(now.second());
  lcd.print("  ");
  lcd.setCursor(0, 1);
  lcd.print("Present card    ");
}

void logEvent(const char *msg, DateTime now) {
  Serial.print(now.hour());
  Serial.print(':');
  Serial.print(now.minute());
  Serial.print(':');
  Serial.print(now.second());
  Serial.print(" - ");
  Serial.println(msg);
}

void grant(DateTime now) {
  logEvent("Access granted", now);
  lcd.setCursor(0, 1);
  lcd.print("GRANTED         ");
  tone(buzzerPin, 880);
  delay(300);
  noTone(buzzerPin);
  bolt.write(90);  // unlock
  delay(5000);
  bolt.write(0);   // relock
}

void deny(DateTime now) {
  logEvent("Access denied", now);
  lcd.setCursor(0, 1);
  lcd.print("DENIED          ");
  tone(buzzerPin, 220);
  delay(500);
  noTone(buzzerPin);
}

void alarm(DateTime now) {
  logEvent("ALARM: motion + close object", now);
  lcd.setCursor(0, 1);
  lcd.print("ALARM!          ");
  tone(buzzerPin, 1000);
  delay(1000);
  noTone(buzzerPin);
}

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  rtc.begin();
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  lcd.begin(16, 2);
  bolt.attach(servoPin);
  bolt.write(0);  // locked
  pinMode(pirPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  DateTime now = rtc.now();
  showTime(now);

  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    bool ok = uidMatches() && now.hour() >= 9 && now.hour() < 17;
    if (ok) grant(now); else deny(now);
    rfid.PICC_HaltA();
    delay(500);
    return;
  }

  if (digitalRead(pirPin) == HIGH) {
    long distance = measureDistanceCm();
    if (distance > 0 && distance < 50) {
      alarm(now);
    }
  }
  delay(200);
}
