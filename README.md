[![Heartbloom Lamp](https://i.imgur.com/TOn8VLo.png "Heartbloom Lamp")](http://i.imgur.com/TOn8VLo.png "Heartbloom Lamp")

Long-distance friendship lamps cost hundreds of dollars, just to light up an LED somewhere to let your loved one know you're thinking of them. We thought, why not spend hundreds of minutes building a work of art instead, to send a sentiment with more **heart**? And so heartbloom was born! By firing off a text message to Heartbloom Bot from anywhere in the world, you can let your special someone know that you're on their mind.



## How we built it
Your favourite person activates heartbloom by sending a text message to our Telegram bot, [Heartbloom Bot](http://t.me/heartbloombot "heartbloombot"). When heartbloombot receives a message, our Pipedream webhook (connected to the bot) is triggered, which then makes an HTTP request to a webserver running wirelessly on an ESP32 board on the heartbloom lamp. Upon reception of the request, the servo motor activates to momentarily "bloom", or open the petals of the stunning flower lamp we built completely from scratch.

## Circuit setup
The circuit is simple enough that a breadboard is unneeded -- simply wire the MS18 servo to an output pin, GND, and 3.3V in. We connected the VIN and ground on the ESP32 in parallel to the battery pack for our LEDs, which consisted of 3 lithium AA batteries.

## Port forwarding the ESP32 webserver from ngrok
Run `ngrok.exe http [ipAddress]:80` after opening ngrok, replacing `[ipAddress]` with the IP that is logged to the serial monitor when the Arduino program is run. Note that Arduino compiles all the .ino files, in lexicographical order, into one executable.

## What's next for heartbloom
- Sentiment analysis of the text message to change the colour of the LEDs
- Extend servo arm to increase degree of movement
- 3D printed lamp parts and a more elegant opening mechanism

## Resources used
Working with servos on the esp32: https://dronebotworkshop.com/esp32-servo/
