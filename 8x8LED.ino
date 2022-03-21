#include <FastLED.h>
#include "types.h"
#include "letter_defs.h"

CRGB leds [ NUM_LEDS ] ;

/* Writes a single pixel white based on x and y input  */
static void writePixel(const byte x, const byte y )
{
    if ( (x > MAX_X_ELEMENTS) ||
         (y > MAX_Y_ELEMENTS) ||
         (x < 0) ||
         (y < 0))
    {
        return; // Ignore the write command if x and y are out of bounds. 
    }
    leds[lookupArray[y*Y_PIXELS + x]] = CRGB(0,0,10);
}


/* Writes a single letter based on a starting x and y coordinate. Will adjust the render commands
 * based on the total amount of possilbe x and y spots. If the full letter will not be rendered, the 
 * iteration will account for only those specified bounds and only render the relevant encoded bits. 
 */
//void writeSingleLetter( const Letter * const lr, 
//                        const byte x_start, 
//                        const byte y_start )
//{
//
//    byte colsToIterate;
//    byte rowsToIterate;
//    byte y_max;
//    uint32_t letter = lr->encoding;
//    colsToIterate = ( (x_start + X_ENCODING_LENGTH) > X_ELEMENTS )?  X_ELEMENTS - x_start :X_ENCODING_LENGTH;
//    rowsToIterate = ( (y_start + Y_ENCODING_LENGTH) > Y_ELEMENTS )?  Y_ELEMENTS - y_start :Y_ENCODING_LENGTH;
//    
//    // start: 0 1 2 3 4 5 6 7 
//    // clip:  0 0 0 0 1 2 3 4
//
//    byte clipped_columns = ( x_start > 3 )? x_start - 3: 0;
//    byte current_x;
//    byte current_y;
//    for ( current_y = 0; current_y < colsToIterate; current_y++ )
//    {
//        
//        for ( current_x = 0; current_x < rowsToIterate; current_x++ )
//        {
//            if ( letter & 0x20000000 )  
//            {
//                writePixel( current_x, current_y );
//            }
//            letter = (letter << 1) & 0x3FFFFFFF;
//        }
//        // Shift by the clipping value? 
//        letter = ( letter << clipped_columns );
//    }
//}

void writeLetterTesting( Letter * lt )
{

    // Ensure the letter input parameters are correct.
    
    uint8_t x_ct; // x counter
    uint8_t y_ct; // y counter
    const byte x_it = min( X_ENCODING_LENGTH, X_PIXELS - lt->x );
    const byte y_it = min( Y_ENCODING_LENGTH, Y_PIXELS - lt->y );
    const byte x_clipped = min ( lt->x + (byte)X_ENCODING_LENGTH - (byte)X_PIXELS, X_ENCODING_LENGTH); 

    Serial.print("\n X Iterations: ");
    Serial.print( x_it);
    Serial.print("     Y Iterations: ");
    Serial.print(y_it);
    Serial.print("     X Clippeed: ");
    Serial.print(x_clipped);
    
    uint32_t encodingVal = lt->encoding; // Copy of the encoding value, used to shift the encoding val that is const. 
    /* For loop starts with the y coordinate (1st row). */
    for (y_ct = 0; y_ct < y_it; y_ct++)
    {
        for (x_ct = 0; x_ct < x_it; x_ct++)
        {
            // If the encoding value equals 1, write the position to the current x y coordinate. 
            if ( (encodingVal) & 0x80000000)
            {
                writePixel ( lt->x + x_ct, lt->y + y_ct );
            }
            encodingVal = encodingVal << 1 ; // This will be zero in the case of no clipping. 
        }
        // Compensational shift to account for X clipping. 
        encodingVal = encodingVal << x_clipped;
    }
}


void setLetterCoordinate( Letter * lt, byte x, byte y )
{
    if ( ( x > MAX_X_ELEMENTS ) ||
        (y > MAX_Y_ELEMENTS))
    {
        return;
    }
    
    lt->x = x;
    lt->y = y;
}


uint8_t counter;
const Letter lettArr[] = {_a,_b,_c,_d,_e,_f,_g,_h,_i,_j,_k,_l,_m,_n,_o,_p,_q,_r,_s,_t,_u,_v,_w,_x,_y,_z  };
const Letter numArr[] = {_zero,_one,_two,_three,_four,_five,_six,_seven,_eight,_nine};

void testAlphabet()
{
    for (counter = 0; counter < 26; counter++)
    {
        writeLetterTesting ( &(lettArr[counter]));
        FastLED.show();
        delay(1000);
        FastLED.clear();
        Serial.println("S");
    }
    delay(2000);
}

void testNumbers()
{
    for (counter = 0; counter < 10; counter++) 
    {
        writeLetterTesting( &(numArr[counter]));
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
    setLetterCoordinate ( &_d, 4,4);
}


void testLetterScroll( Letter * lt )
{

    uint8_t counter;
    for ( counter = 0; counter < 8; counter++ )
    {
        setLetterCoordinate(lt, counter, counter);
        writeLetterTesting (lt);
        FastLED.show();
        delay(500);
        FastLED.clear();
    }
    
}

void loop()
{   


    testLetterScroll ( &_p);

 
}
