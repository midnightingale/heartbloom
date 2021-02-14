#define SERVO_PIN 18
#define BLOOM_DURATION 5000 //low number for testing purposes, change later

Servo bloomerServo;
int bloomerPosition = 0;
bool bloomOpen = false;

void closeBloom() {
  for (bloomerPosition = 180; bloomerPosition >= 0; bloomerPosition -= 1) { // goes from 180 degrees to 0 degrees
    bloomerServo.write(bloomerPosition);
    delay(15);
  }
}

void openBloom() {
  for (bloomerPosition = 0; bloomerPosition <= 180; bloomerPosition += 1) { // goes from 0 degrees to 180 degrees
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
