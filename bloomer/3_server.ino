/*
 WiFi Web Server 

 A simple web server that lets us control the servo via the web.
 If the IP address of your shield is myAddress:
 http://myAddress/bloom opens the flower

 Based on the Wifi Web Server code by Tom Igoe, created for arduino 2012/11/25,
 and ported by Jan Hendrik Berlin for sparkfun esp32 2017/01/31 
 and modified by Sophie Liu for the heartbloom project, 2021/02/13
 */

WiFiServer server(80);

void setup()
{
    delay(10); 
    server.begin();
}

void readClient(){
  String currentLine = ""; 
  char c = client.read();             
  Serial.write(c);
  
  if (c == '\n') {                    
    if (currentLine.length() == 0) {
      // an empty currentLine indicates the end of the request, so we send a response
      client.println("HTTP/1.1 200 OK\n");
      break;
    } else { // clear currentLine:
      currentLine = "";
    }
  } 
  else if (c != '\r') {    // received anything but a carriage return character,
    currentLine += c;      // add it to the end of the currentLine
  }
  
  if (currentLine.endsWith("GET /bloom")) {
    openBloom();
  }
}


void loop(){
 WiFiClient client = server.available();   // listen for incoming clients
 if (client) {                             
    Serial.println("New client!");
    while (client.connected()) {            
      if (client.available()) {             
        readClient();
      }
    }
    
    client.stop(); // close the connection:
    Serial.println("Client disconnected.");
  }
}
