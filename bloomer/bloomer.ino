// The numbers on the other files indicate the order of compilation. 
// This file is compiled first.
#include <WiFi.h> // ESP32 Wifi include

void setup() {
  Serial.begin(115200);
  connectToWiFi();
  setupServo();
}

void loop(){
  runServer();
}
