#include <ESP32Servo.h>
#define SERVO_PIN 18

Servo bloomerServo;
int bloomerPosition = 0;

void setup() {
  Serial.begin(115200);
  bloomerServo.attach(SERVO_PIN, 500, 2400);
  bloomerPosition = 10;
  bloomerServo.write(10);
}
 
void loop() {
 
  for (bloomerPosition = 0; bloomerPosition <= 180; bloomerPosition += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    bloomerServo.write(bloomerPosition);    // tell servo to go to bloomerPositionition in variable 'bloomerPosition'
    delay(15);             // waits 15ms for the servo to reach the bloomerPositionition
  }
  for (bloomerPosition = 180; bloomerPosition >= 0; bloomerPosition -= 1) { // goes from 180 degrees to 0 degrees
    bloomerServo.write(bloomerPosition);    // tell servo to go to bloomerPositionition in variable 'bloomerPosition'
    delay(15);             // waits 15ms for the servo to reach the bloomerPositionition
  }
}
