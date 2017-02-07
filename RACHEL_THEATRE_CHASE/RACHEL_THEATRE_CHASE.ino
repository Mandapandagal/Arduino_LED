#include <Adafruit_DotStar.h>
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET
#define NUMPIXELS 18 // Number of LEDs in strip
// Here's how to control the LEDs from any two pins:
#define DATAPIN    2
#define CLOCKPIN   3
Adafruit_DotStar strip = Adafruit_DotStar(
NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

 int delayTime = 75; // Delay time
 
 void setup() {
   strip.begin(); // initialize the strip
 }
 
 void loop() {
   colorWipe();
   rainbowTheaterChase();
 }
 
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void rainbowTheaterChase()
 {
   theaterChase(strip.Color(255, 0, 0), delayTime - 5); //folly: 255, 0, 79 (red)
   theaterChase(strip.Color(255, 100, 0), delayTime - 10); //amber: 255, 191, 0 (orange)
   theaterChase(strip.Color(150, 200, 0), delayTime - 15); //gold: 255, 215, 0 (yellow)
   theaterChase(strip.Color(59, 255, 52), delayTime - 20); //screaming green: 118, 255, 122 (light green)
   theaterChase(strip.Color(0, 123, 167), delayTime - 25); //cerulean: 0, 123, 167
   theaterChase(strip.Color(110, 80, 110), delayTime - 30); //plum: 221, 160, 221
 }
 void theaterChase(uint32_t color, uint8_t wait) { 
   for (int j = 0; j < 2; j++) { //do 10 cycles of chasing
     for (int q = 0; q < 4; q++) {
       for (int i = 0; i < strip.numPixels(); i = i + 4) {
         strip.setPixelColor(q + i, color);  //turn every fourth pixel on
       
       }
       strip.show();
       delay(wait);
       for (int i = 0; i < strip.numPixels(); i = i + 4) {
         strip.setPixelColor(q + i, 0);      //turn every fourth pixel off
       }
     }
   }
 }
 
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 void colorWipe()
 {
   
   for (uint16_t i = 0; i < strip.numPixels(); i++) {
     strip.setPixelColor(i, 110, 80, 110);
     strip.setBrightness(255);
     strip.show();
     delay(delayTime);
   }
 
     for (uint16_t i = 0; i < strip.numPixels(); i++) {
       strip.setPixelColor(i, 0, 123, 167);
       strip.setBrightness(100);
       strip.show();
       delay(delayTime - 5);
     }
       for (uint16_t i = 0; i < strip.numPixels(); i++) {
         strip.setPixelColor(i, 59, 255, 52);
         strip.setBrightness(100);
         strip.show();
         delay(delayTime - 10);
       }
         for (uint16_t i = 0; i < strip.numPixels(); i++) {
           strip.setPixelColor(i, 150, 200, 0);
           strip.setBrightness(100);
           strip.show();
           delay(delayTime - 15);
         }
           for (uint16_t i = 0; i < strip.numPixels(); i++) {
             strip.setPixelColor(i, 255, 100, 0);
             strip.setBrightness(100);
             strip.show();
             delay(delayTime - 20);
           }
             for (uint16_t i = 0; i < strip.numPixels(); i++) {
               strip.setPixelColor(i, 255, 0, 0);
               strip.setBrightness(100);
               strip.show();
               delay(delayTime - 25);
             }
 }
