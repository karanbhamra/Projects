/* =====================================================================================
 *       Filename:  Chapter4.c
 *    Description:  Excercises from Chapter 4
 *        Created:  01/14/2011 09:31:45 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>

int main ( int argc, char *argv[] )
{
    int x = 50;

    printf("%d in octal is %#o \n", x, x);
    printf("%d in hex is %#x \n", x, x);


    unsigned char c = 0xFF;

    printf("%#x is  %i \n", c,c);

    printf("%li bytes\n", sizeof(char));
    
    int i = 5;

    printf("%i \n", ++i);
    printf("%i \n", i);
    int j = 5;

    printf("%i \n", j++);
    printf("%i \n", j);

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
