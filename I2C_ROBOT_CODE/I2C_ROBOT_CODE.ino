
#include <Adafruit_DotStar.h>
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET
#define NUMPIXELS 18 // Number of LEDs in strip
// Here's how to control the LEDs from any two pins:
#define DATAPIN    2
#define CLOCKPIN   3
Adafruit_DotStar strip = Adafruit_DotStar(
NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

#include <Wire.h>
#include <LPD8806.h>



// This will use the following pins (SPI):
// Data (SDA):  11
// Clock (SCL): 13
LPD8806 strip = LPD8806(STRIP_LENGTH);


static const byte i2cAddress = 82;


// This boolean gets set when we have new data that has been verified to be correct following our checks
boolean dataChanged = false;


// Create the variables that are used for raw data packets
// These should not be altered as they are handled internally by the recieveData function
unsigned char dataByte1 = 0;
unsigned char dataByte2 = 0;
unsigned char dataByte3 = 0;
unsigned char dataByte4 = 0;

// Create the variables that are actually used within the light functions.
// These are the actual variables that should be compared with but they should not be manually altered
unsigned char currentPattern = 0;
unsigned char redValue = 0;
unsigned char greenValue = 0;
unsigned char blueValue = 0;

void setup()
{
     // Start the LED strip
     strip.begin();

     // Update the strip to ensure that all the LEDs are all off at the beginning
     strip.show();

     // Begin I2C communications as a SLAVE. receiveData() will be called when new data arrives.
     // We call this last to avoid a nasty bug involving the LED initialization code
     Wire.begin(i2cAddress);
     Wire.onReceive(receiveData);

}



void loop()
{
     if (currentPattern == 0x02)
     {
        dataChanged = false;
        autonomous();
     }
     else if (currentPattern == 0x05)
     {
        dataChanged = false;
        shoot(10, 1000);
     }

}

// This blinks all the LEDs to the rgb values passed in. Time can be changed for on and off with onWait and offWait when calling.
void colorBlink(unsigned long onWait, unsigned long offWait, byte r, byte g, byte b)
{
  unsigned int i;
  // First Pulse
  for (i=0; i < strip.numPixels(); i++)
  {

     strip.setPixelColor(i, strip.Color(r,g,b));
  }
  strip.show();

  if (timedWait(onWait))
  {
     return;
  }

  for (i=0; i < strip.numPixels(); i++)
  {
     strip.setPixelColor(i, 0);
  }
  strip.show();
  // Wait function with interrupt
  if (timedWait(offWait))
  {
     return;
  }
}

// Sets all pixels off to blank the entire strip.
void blankStrip()
{
   for (unsigned int i = 0; i < strip.numPixels(); i++)
   {
      strip.setPixelColor(i, 0);
   }
   strip.show();
}

// Turns off a specified range of pixels
void blankRange(unsigned int p_start, unsigned int p_end)
{
   for (unsigned int i = p_start; i < p_end; i++)
   {
      strip.setPixelColor(i, 0);
   }
   strip.show();
}

// This gets called every time we receive new data over the I2C lines
// See I2Cdesign.md for a complete explanation of our utilization
void receiveData(int byteCount)
{
  // Check the byte count to ensure that we are recieving a 5 byte packet
  if (byteCount == 4)
  {
    // Strip off the last byte and read the value
    dataByte1 = (0x000000FF & Wire.read()); // Pattern
    dataByte2 = (0x000000FF & Wire.read()); // Red
    dataByte3 = (0x000000FF & Wire.read()); // Green
    dataByte4 = (0x000000FF & Wire.read()); // Blue

       // Finally set the data to the variables we actually use in loop()
       currentPattern = dataByte1;
       redValue = dataByte2;
       greenValue = dataByte3;
       blueValue = dataByte4;

       // Set the flag to say that we have new data
       dataChanged = true;
  }
  // This should clear out any packets that are bigger than the required 5 bytes
  else if (byteCount > 4)
  {
    // Keep on reading the bytes from the buffer until they are gone. They are simply not used and thus
    // will be thrown away.
    while (Wire.available() > 0)
    {
      Wire.read();
    }
  }
}

// Wait function (Specified Time)
// This is called when we wait to wait in between events that are occuring in our functions.
// Much better than using delay() because we can interrupt the parent function when new data is received.
boolean timedWait(unsigned int waitTime)
{
   unsigned long previousMillis = millis();
   unsigned long currentMillis = millis();

   for(previousMillis; (currentMillis - previousMillis) < waitTime; currentMillis = millis())
   {
      // This may appear to have to effect and the compiler will even throw a warning about it.
      // However, dataChanged is set even when in this loop by the receiveData() function
      if(dataChanged)
      {
         return true;
      }
   }
   return false;
}

// Wait function (infinite)
// This is called when we wait to wait in between events that are occuring in our functions.
// Much better than using delay() because we can interrupt the parent function when new data is received.
// We sit in this function until dataChanged becomes true.
boolean infiniteWaitFunction()
{
   while (!dataChanged)
   {
      // Do nothing. We just sit in here until new data is recieved.
   }
   // If we break out of the while loop, then dataChanged must be true so we can return true
   return true;
}

