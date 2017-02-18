#include <Adafruit_DotStar.h>
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET
#define NUMPIXELS 8 // Number of LEDs in strip
// Here's how to control the LEDs from any two pins:
#define DATAPIN    2
#define CLOCKPIN   3
Adafruit_DotStar strip = Adafruit_DotStar(
                           NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_RGB);


void setup()
{
  strip.begin();
}


void loop()

{
  for (int i = 0; i < 10; i++)
  {
    for (int k = 0; k > -4; k--)
    {
      if (((i + k) >= 0) || ((i +k ) > 10))
      {

        int red = 255 + (k * 80);

        strip.setPixelColor((i + k), red, 0, 255);
       
        strip.show();

    {
      
        strip.show();
        
        delay(20);
        strip.setBrightness(100);
      }
    }
    }
  }
}
