/* =====================================================================================
 *       Filename:  main.c
 *    Description:  Chapter 15
 *        Created:  02/05/2011 04:44:43 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>
#include "foo.c"
int i = 5;

int main ( int argc, char *argv[] )
{
    printf("%i   ", i);
    
    foo();
    printf("%i\n", i);

    typedef struct
    {
        float x;
        float y;
    } Coord;

    Coord origin = {0, 0};

    printf("origin=%.1f,%.1f", origin.x, origin.y);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
