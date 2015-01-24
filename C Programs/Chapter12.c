/* =====================================================================================
 *       Filename:  Chapter12.c
 *    Description:  Chapter 12 Excercises
 *        Created:  01/30/2011 07:52:23 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>

int main ( int argc, char *argv[] )
{

    unsigned int w1 = 0525u, w2 = 0707u, w3 = 0122u;

    printf("%o  %o  %o\n", w1 & w2, w1 | w2, w1 ^ w2);
    printf("%o  %o  %o\n", ~w1, ~w2, ~w3);
    printf("%o  %o  %o\n", w1 ^ w1, w1 & ~w2, w1 | w2 | w3);
    printf("%o  %o\n", w1 | (w2 & w3), w1 | (w2 & ~w3));
    printf("%o  %o\n", ~(~w1 & ~w2), ~(~w1 | ~w2));

    w1 ^= w2;
    w2 ^= w1;
    w1 ^= w2;
    printf("w1 = %o, w2 = %o\n", w1, w2);

    unsigned int shift (unsigned int value, int n);

    printf("%i shifted left by 1 is %i, shifted right by 1 is %i\n",2, shift(2,1), shift(2,-1));

    unsigned int rotate (unsigned int value, int n);

    unsigned int a1 = 0x1;
    unsigned int a2 = 0xF0000000;
    printf("%i rotate right is %i\n", a1, rotate(a1, -1));
    printf("%i rotate left is %i\n", a2, rotate(a2, 1));
    
    struct packed_struct
    {
        unsigned int :3;
        unsigned int f1:1;
        unsigned int f2:1;
        unsigned int f3:1;
        unsigned int type:8;
        unsigned int index:18;
    };
    
    struct packed_struct packed_data;

    packed_data.type = 7;
    packed_data.f1 = 1;
    packed_data.f2 = 1;
    packed_data.f3 = 0;
    packed_data.index = 255;
    int n = packed_data.type;

    printf("packed_data.type is %i, packed_struct size is %li bytes.\n", n, sizeof(struct packed_struct));


    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

unsigned int shift (unsigned int value, int n)
{
    if (n > 0)
        value <<= n;
    else
        value >>= -n;

    return value;
}

unsigned int rotate (unsigned int value, int n)
{
    unsigned int result, bits;

    // scale down the shift to a defined range
    
    if (n > 0)
        n = n %32;
    else
        n = -(-n % 32);

    if ( n == 0)
        result = value;
    else if (n > 0) // left rotate
    {
        bits = value >> (32 - n);
        result = value << n | bits;
    }
    else
    {
        n = -n;
        bits = value << (32 -n);
        result = value >> n | bits;
    }

    return result;
}
