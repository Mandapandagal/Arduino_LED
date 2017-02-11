#include <Adafruit_DotStar.h>
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET
#define NUMPIXELS 8 // Number of LEDs in strip
// Here's how to control the LEDs from any two pins:
#define DATAPIN    2
#define CLOCKPIN   3
Adafruit_DotStar strip = Adafruit_DotStar(
                           NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);


void setup() {
 strip.begin();
}

int waitTime = 300;

void loop() {

for (int i = 0; i < NUMPIXELS / 2; i++)
{

   float blue = (i * (240 / ((NUMPIXELS - 2) / 2))) + 15;
//   int blue = (i * 80) + 15;
  // strip.Color(blue, green, red);  ==> max 255
  strip.setPixelColor(i, strip.Color(0, blue, 0));
  strip.setPixelColor(NUMPIXELS - i - 1, strip.Color( 0, blue, 0));
strip.show();
delay(350);
}
delay(waitTime * 5);
for (int i = 0; i < NUMPIXELS; i++)
{
  strip.setPixelColor(i, strip.Color(random(255), random(0), random(255)));
}
strip.setBrightness(255);
strip.show();
delay(waitTime);
  }

