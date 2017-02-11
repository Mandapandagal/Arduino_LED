#include <Adafruit_DotStar.h>
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET
#define NUMPIXELS 8 // Number of LEDs in strip
// Here's how to control the LEDs from any two pins:
#define DATAPIN    2
#define CLOCKPIN   3
Adafruit_DotStar strip = Adafruit_DotStar(
                           NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_RGB);

int colours[7][3] =
{
  {255, 0, 0},
  {200, 140, 0},
  {255, 221, 0},
  {8, 255, 0},
  {0, 255, 0},
  {255, 0, 255},
  {255, 255, 255},
};

void setup() {
  strip.begin();
}



void loop() {

// For every colour...
  for (int colourIndex = 0; colourIndex < 7; colourIndex ++)
  {
    // For every pixel
    for (int i = 0; i < 8; i++)
    {
      // Set the pixel colour
      strip.setPixelColor(i, colours[colourIndex][0], colours[colourIndex][1], colours[colourIndex][2]);
    }
    //    strip.setPixelColor(i, 10, 130, 100);
    // Show the strip (send output to strip) and wait
    strip.setBrightness(10);
    strip.show();
    delay(100);

// For every pixel...
//    for (int i = 0; i < 8; i++)
//    {
//      // Turn it off (set to black - 0, 0, 0)
//      strip.setPixelColor(i, 0, 0, 0);
//    }
//    strip.show();
//    delay(50);
  }

}

