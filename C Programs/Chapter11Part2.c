/* =====================================================================================
 *       Filename:  Chapter11Part2.c
 *    Description:  Chapter 11 part 2 excercises
 *        Created:  01/25/2011 04:55:12 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>

int main ( int argc, char *argv[] )
{
    struct intPtrs
    {
        int *p1;
        int *p2;
    };
    
    struct intPtrs pointers;
    
    int i1 = 100, i2;

    pointers.p1 = &i1;
    pointers.p2 = &i2;
    
    *pointers.p2 = -97;

    printf("i1 = %i, *pointers.p1 = %i\n", i1, *pointers.p1);
    printf("i2 = %i, *pointers.p2 = %i\n", i2, *pointers.p2);




    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
