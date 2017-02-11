#include <Adafruit_DotStar.h>
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET
#define NUMPIXELS 8 // Number of LEDs in strip
// Here's how to control the LEDs from any two pins:
#define DATAPIN    2
#define CLOCKPIN   3
Adafruit_DotStar strip = Adafruit_DotStar(
                           NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_RGB);


void setup() {
  strip.begin();
}

int waitTime = 200;



void loop()
{
  // Attempt to move the RED forward
  for (int i = 0 ; i <= 8 ; i++)
  {
    for (int j = 0; j <= 8; j++)
    {

      if (j == i)
      {
        // the color red
        strip.setBrightness(255);
        strip.setPixelColor (j, 0, 0,255);
      }
      else
      {
        // the color green
        strip.setBrightness(255);
        strip.setPixelColor (j,  255 + j * 8, 0, 0);
      }

      strip.show();
      delay(10);

    }
  }

  // Attempt to Move RED backwards
  for (int i = 7 ; i>=0 ; i--)
  {
    for (int j = 0; j <= 8; j++)
    {

      if (j == i)
      {
        // the color red
        strip.setBrightness(255);
        strip.setPixelColor (j, random(255), random(255), random(255));
      }
      else
      {
        // the color green
        strip.setBrightness(255);
        strip.setPixelColor (j,  255 + j * 8, 0, 0);
      }

      strip.show();
      delay(10);

    }
  }
}

