#include "WiFi.h" // ESP32 Wifi include
#include "WiFiConfig.h" // Angela's network config

void connectToWiFi(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, WiFiPassword);
  Serial.print("Connecting to wifi network: "); Serial.println(SSID);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(500);
  }
 
  Serial.print(F("Connected to wifi network. My IP address is: "));
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  connectToWiFi();
}

void loop() {
  //Serial.println("Hello, world!");
}
