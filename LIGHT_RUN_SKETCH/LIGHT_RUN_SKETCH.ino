#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET

#define NUMPIXELS 16 // Number of LEDs in strip
#define DATAPIN    2
#define CLOCKPIN   3
Adafruit_DotStar strip = Adafruit_DotStar(
  NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);



void setup() {
  // put your setup code here, to run once:
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
}

void loop() {
  // put your main code here, to run repeatedly:
  int redslide = 0;
  strip.setPixelColor(redslide, 100, 0, 0);
{
for (int i = 0, 0<10; redslide++);
}
