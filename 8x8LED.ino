#include <FastLED.h>
//#include "types.h"
#include "letter_defs.h"

/* Changes based on LED matrix used */
#define X_PIXELS 32
#define Y_PIXELS 8
#define LED_PIN 5

/* Derived define types */
#define NUM_LEDS X_PIXELS * Y_PIXELS
#define MAX_X_ELEMENTS X_PIXELS - 1
#define MAX_Y_ELEMENTS Y_PIXELS - 1

/* Constant per encoding standard */
#define NUM_BITS_ENCODING 30
#define X_ENCODING_LENGTH 5
#define Y_ENCODING_LENGTH 6

CRGB leds [ NUM_LEDS ] ;
 
/* Writes a single pixel based on x and y input  */
static void writePixel(const byte x, const byte y )
{
    if ( (x > MAX_X_ELEMENTS) ||
         (y > MAX_Y_ELEMENTS) ||
         (x < 0) ||
         (y < 0))
    {
        return; // Ignore the write command if x and y are out of bounds. 
    }
//    leds[lookupArray[y*Y_PIXELS + x]] = CRGB(0,0,10);

    uint16_t assignment = ( ( 0 == ( x % 2)))? X_PIXELS*x+y : Y_PIXELS*x +( Y_PIXELS-1-y ) ;  
    leds[assignment] = CRGB(0,0,10);
}


void writeLetterTesting( Character * ct )
{
    // Ensure the letter input parameters are correct.
    
    uint8_t x_ct; // x counter
    uint8_t y_ct; // y counter
    const byte x_it = min( X_ENCODING_LENGTH, X_PIXELS - ct->x );
    const byte y_it = min( Y_ENCODING_LENGTH, Y_PIXELS - ct->y );
//    const byte x_clipped = min ( lt->x + (byte)X_ENCODING_LENGTH - (byte)X_PIXELS, X_ENCODING_LENGTH); 

    int x_c = ct->x +(byte)X_ENCODING_LENGTH - (byte)X_PIXELS;
    if (x_c <= 0)
    {
        x_c = 0;
    }
    const byte x_clipped = (uint8_t) x_c;

    Serial.print("\n X Iterations: ");
    Serial.print( x_it);
    Serial.print("     Y Iterations: ");
    Serial.print(y_it);
    Serial.print("     X Clippeed: ");
    Serial.print(x_clipped);
    
    uint32_t encodingVal = ct->encoding; // Copy of the encoding value, used to shift the encoding val that is const. 
    /* For loop starts with the y coordinate (1st row). */
    for (y_ct = 0; y_ct < y_it; y_ct++)
    {
        for (x_ct = 0; x_ct < x_it; x_ct++)
        {
            // If the encoding value equals 1, write the position to the current x y coordinate. 
            if ( (encodingVal) & 0x80000000)
            {
                writePixel ( ct->x + x_ct, ct->y + y_ct );
            }
            encodingVal = encodingVal << 1 ; // This will be zero in the case of no clipping. 
        }
        // Compensational shift to account for X clipping. 
        encodingVal = encodingVal << x_clipped;
    }
}


void setLetterCoordinate( Character * ct, byte x, byte y )
{
    if ( ( x > MAX_X_ELEMENTS ) ||
        (y > MAX_Y_ELEMENTS))
    {
        return;
    }
    
    ct->x = x;
    ct->y = y;
    return;
}


uint8_t testeCounter;

extern const Character lettArr[];
extern const Character numArr[];

void testAlphabet()
{
    for (testeCounter = 0; testeCounter < 26; testeCounter++)
    {
        writeLetterTesting ( &(lettArr[testeCounter]));
        FastLED.show();
        delay(1000);
        FastLED.clear();
        Serial.println("S");
    }
    delay(2000);
}

void testNumbers()
{
    for (testeCounter = 0; testeCounter < 10; testeCounter++) 
    {
        writeLetterTesting( &(numArr[testeCounter]));
        FastLED.show();
        delay(1000);
        FastLED.clear();
    }
}

void setup()
{
    Serial.begin(115200);
    FastLED.addLeds<WS2812, LED_PIN, GRB>( leds , NUM_LEDS );
    FastLED.setMaxPowerInVoltsAndMilliamps( 5, 500 );
    FastLED.clear();
    FastLED.show();
}

void testLetterScroll( Character * lt )
{
    uint8_t counter;
    for ( counter = 0; counter < 8; counter++ )
    {
        setLetterCoordinate(lt, 2, counter);
        writeLetterTesting (lt);
        FastLED.show();
        delay(500);
        FastLED.clear();
    }   
}

void testLetterScrollLR( Character * lt)
{

}

void loop()
{   
    Character * thisLetter = ( &(lettArr[0]));
    //testLetterScroll ( &_s);
    //setLetterCoordinate( )
    setLetterCoordinate(thisLetter, 2, 1);
    writeLetterTesting (thisLetter);
    FastLED.show();
 
}
