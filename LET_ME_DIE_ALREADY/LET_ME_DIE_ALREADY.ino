
#include <Adafruit_DotStar.h>
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET
#define NUMPIXELS 18 // Number of LEDs in strip
// Here's how to control the LEDs from any two pins:
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
int a=0;
int b = 1;
int c= 2;
int d=3;
int e = 4;
int f= 5;
int g=6;
int h = 7;
int i= 8;
int j=9;
int k = 10;
int l= 11;
int m=12;
int n = 13;
int o= 14;
int p=15;
int q = 16;
int r= 17;

strip.setPixelColor(a,100,0,0);
strip.setPixelColor(b,0,100,0);

strip.setPixelColor(c,100,0,0);
strip.setPixelColor(d,0,100,0);

strip.setPixelColor(e,100,0,0);
strip.setPixelColor(f,0,100,0);

strip.setPixelColor(g,100,0,0);
strip.setPixelColor(h,0,100,0);

strip.setPixelColor(i,100,0,0);
strip.setPixelColor(j,0,100,0);

strip.setPixelColor(k,100,0,0);
strip.setPixelColor(l,0,100,0);

strip.setPixelColor(m,100,0,0);
strip.setPixelColor(n,0,100,0);

strip.setPixelColor(o,100,0,0);
strip.setPixelColor(p,0,100,0);

strip.setPixelColor(q,100,0,0);
strip.setPixelColor(r,0,100,0);

strip.show();

}
