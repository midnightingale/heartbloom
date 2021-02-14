#include <Arduino.h>
#include <ESP32Servo.h>

#define SERVO_PIN 18
#define BLOOM_DURATION 1000 //low number for testing purposes, change later

Servo bloomerServo;
int bloomerPosition = 0;

void closeBloom() {
  for (bloomerPosition = 0; bloomerPosition <= 180; bloomerPosition += 1) { 
    bloomerServo.write(bloomerPosition);
    delay(15);
  }
}

void openBloom() {
  for (bloomerPosition = 180; bloomerPosition >= 0; bloomerPosition -= 1) { 
    bloomerServo.write(bloomerPosition);
    delay(15);
  }
  delay(BLOOM_DURATION);
  closeBloom();
}

void setupServo() {
  bloomerServo.attach(SERVO_PIN, 500, 2400);
  bloomerPosition = 0;
  bloomerServo.write(0);
}
