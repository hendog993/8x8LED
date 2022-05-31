/*************************************************************************
 *                               LED Screen
 *
 *
 **************************************************************************/
#ifndef LEDSCREEN_H
#define LEDSCREEN_H

#include <FastLED.h>
#include <stdint.h>
#include <stdlib.h>
#include "letter_defs.h"

extern const Character lettArr[];
extern const Character numArr[];

class LEDMatrix
{
private:
CRGB * leds;
inline void writePixel(const byte x, const byte y );

public:
  LEDMatrix::LEDMatrix( const size_t numRows, const size_t numCols );
  void writeLetterTesting( Character * ct );
  


};


#endif