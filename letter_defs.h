#ifndef LETTER_DEFS_H
#define LETTER_DEFS

typedef struct Letter_t // TODO rename this to character 
{
    const uint32_t encoding; 
    byte x;
    byte y;
} Letter;

typedef struct Letter_Array_t
{
    Letter * letterArray;
    size_t numElements;
} Letter_Array;

Letter test = 
{
    .encoding = 0xFC3FF87C
};

Letter _a = {
    .encoding = 0x22A3F8C4
};

Letter _b = {
    .encoding = 0xF47DE8F8
};

Letter _c = {
    .encoding = 0x7C21083C
};

Letter _d = {
    .encoding = 0xF46318F8
};

Letter _e = {
    .encoding = 0xFC3FF87C
};

Letter _f = {
    .encoding = 0xFC3D0840
};

Letter _g = {
    .encoding = 0x7C3D18B8
};

Letter _h = {
    .encoding = 0x8C7FF8C4
};

Letter _i = {
    .encoding = 0xF908427C
};

Letter _j = {
    .encoding = 0xF8842170
};

Letter _k = {
    .encoding = 0x8CA9C944
};

Letter _l = {
    .encoding = 0x8421083C
};

Letter _m = {
    .encoding = 0x8EEB18C4
};

Letter _n = {
    .encoding = 0x8E6B38C4
};

Letter _o = {
    .encoding = 0x746318B8
};

Letter _p = {
    .encoding = 0xF463E840
};

Letter _q = {
    .encoding = 0x746319BC
};

Letter _r = {
    .encoding = 0xF463E944
};

Letter _s = {
    .encoding = 0x7C3C10F8
};

Letter _t = {
    .encoding = 0xF9084210
};

Letter _u = {
    .encoding = 0x8C6318B8
};

Letter _v = {
    .encoding = 0x8C631510
};

Letter _w = {
    .encoding = 0x8C6B5AA8
};

Letter _x = {
    .encoding = 0x8A884544
};

Letter _y = {
    .encoding = 0x8A884210
};

Letter _z = {
    .encoding = 0xF888887C
};

/* Number Encodings */
Letter _zero = 
{
    .encoding = 0x746318B8
};
Letter _one = 
{
    .encoding = 0x2328427C
};

Letter _two = 
{
    .encoding = 0x744C887C
};

Letter _three = 
{
    .encoding = 0xF043F0F8
};

Letter _four = 
{
    .encoding = 0x8C62F084
};

Letter _five = 
{
    .encoding = 0x7C20E0F8
};

Letter _six = 
{
    .encoding = 0x743D18B8
};

Letter _seven = 
{
    .encoding = 0xF0444440
};

Letter _eight = 
{
    .encoding = 0x7462E8B8
};

Letter _nine = 
{
    .encoding = 0x7462F084
};


 

#endif 
