#ifndef LETTER_DEFS_H
#define LETTER_DEFS

#include <stdint.h>

typedef struct Letter_t // TODO rename this to character 
{
    const uint32_t encoding; 
    byte x;
    byte y;
} Character;


Character test = 
{
    .encoding = 0xFC3FF87C
};

Character _a = {
    .encoding = 0x22A3F8C4
};

Character _b = {
    .encoding = 0xF47DE8F8
};

Character _c = {
    .encoding = 0x7C21083C
};

Character _d = {
    .encoding = 0xF46318F8
};

Character _e = {
    .encoding = 0xFC3FF87C
};

Character _f = {
    .encoding = 0xFC3D0840
};

Character _g = {
    .encoding = 0x7C3D18B8
};

Character _h = {
    .encoding = 0x8C7FF8C4
};

Character _i = {
    .encoding = 0xF908427C
};

Character _j = {
    .encoding = 0xF8842170
};

Character _k = {
    .encoding = 0x8CA9C944
};

Character _l = {
    .encoding = 0x8421083C
};

Character _m = {
    .encoding = 0x8EEB18C4
};

Character _n = {
    .encoding = 0x8E6B38C4
};

Character _o = {
    .encoding = 0x746318B8
};

Character _p = {
    .encoding = 0xF463E840
};

Character _q = {
    .encoding = 0x746319BC
};

Character _r = {
    .encoding = 0xF463E944
};

Character _s = {
    .encoding = 0x7C3C10F8
};

Character _t = {
    .encoding = 0xF9084210
};

Character _u = {
    .encoding = 0x8C6318B8
};

Character _v = {
    .encoding = 0x8C631510
};

Character _w = {
    .encoding = 0x8C6B5AA8
};

Character _x = {
    .encoding = 0x8A884544
};

Character _y = {
    .encoding = 0x8A884210
};

Character _z = {
    .encoding = 0xF888887C
};

/* Number Encodings */
Character _zero = 
{
    .encoding = 0x746318B8
};
Character _one = 
{
    .encoding = 0x2328427C
};

Character _two = 
{
    .encoding = 0x744C887C
};

Character _three = 
{
    .encoding = 0xF043F0F8
};

Character _four = 
{
    .encoding = 0x8C62F084
};

Character _five = 
{
    .encoding = 0x7C20E0F8
};

Character _six = 
{
    .encoding = 0x743D18B8
};

Character _seven = 
{
    .encoding = 0xF0444440
};

Character _eight = 
{
    .encoding = 0x7462E8B8
};

Character _nine = 
{
    .encoding = 0x7462F084
};

const Character lettArr[] = {_a,_b,_c,_d,_e,_f,_g,_h,_i,_j,_k,_l,_m,_n,_o,_p,_q,_r,_s,_t,_u,_v,_w,_x,_y,_z  };
const Character numArr[] = {_zero,_one,_two,_three,_four,_five,_six,_seven,_eight,_nine};
 

#endif 
