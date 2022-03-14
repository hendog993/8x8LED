#define NUM_LEDS 64
#define Y_ELEMENTS 8
#define X_ELEMENTS 8
#define MAX_X_ELEMENTS 7
#define MAX_Y_ELEMENTS 7
#define LED_PIN 4
#define NUM_BITS_ENCODING 30
#define X_ENCODING_LENGTH 5
#define Y_ENCODING_LENGTH 6

//const uint8_t lookupTable[X_ELEMENTS][Y_ELEMENTS] = 
//{
//    {0,15,16,31,32,47,48,63},
//    {1,14,17,30,33,46,49,62},
//    {2,13,18,29,34,45,50,61},
//    {3,12,19,28,35,44,51,60},
//    {4,11,20,27,36,43,52,59},
//    {5,10,21,26,37,42,53,58},
//    {6, 9,22,25,38,41,54,57},
//    {7, 8,23,24,39,40,55,56}
//};

const uint8_t lookupArray[NUM_LEDS] = 
{
    0,15,16,31,32,47,48,63, // (x,y) = y*8 + x
    1,14,17,30,33,46,49,62, // 9th index: 0,1 -> 8+0 = 8.   
    2,13,18,29,34,45,50,61,
    3,12,19,28,35,44,51,60, 
    4,11,20,27,36,43,52,59,
    5,10,21,26,37,42,53,58,
    6, 9,22,25,38,41,54,57,
    7, 8,23,24,39,40,55,56
};


