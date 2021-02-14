#include "ESPAsyncWebServer.h"

AsyncWebServer server(80);
const char HTML[] PROGMEM = "<h1>hello world, time to bloom!</h1>";


void runServer(){
  server.on("/bloom", HTTP_PUT, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Put route");
    openBloom();
  });

  server.on("/bloom", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", HTML);
  });
  
  server.begin();
  Serial.println("Running server...");
}
