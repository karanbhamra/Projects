/* =====================================================================================
 *       Filename:  Chapter13.c
 *    Description:  Chapter 13 Excercises
 *        Created:  01/31/2011 07:27:51 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>
#include    "metric.h"

#define YES 1
#define show(y) printf(y)
#define cube(y) y*y*y
#define debugPrintf(...) printf("DEBUG: " __VA_ARGS__);
#define printx(n) printf("%i\n", x ## n)
int main ( int argc, char *argv[] )
{
    if ( YES )
        printf("YES\n");
    
    show("LOL\n");

    printf("%i\n",cube(5));
    
    debugPrintf("Hello, World!");

    int x1 = 5;
    printx(1);

    float liters, gallons;

    printf("\nEnter number of liters: ");
    scanf("%f", &liters);

    gallons = liters * QUARTS_PER_LITER / 4.0;

    printf("%g liters = %g gallons\n", liters, gallons);

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
