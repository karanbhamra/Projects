/* =====================================================================================
 *       Filename:  Chapter5.c
 *    Description:  Chapter 5 Excercises
 *        Created:  01/15/2011 07:57:36 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>

int main ( int argc, char *argv[] )
{
    int n, triangularNumber, number;

    triangularNumber = 0;

    printf("Whhat triangular number do you want? ");
    scanf("%i", &number);

    for (n =1; n<=number; n++)
        triangularNumber += n;

    printf("The %i triangular number is %i \n", number, triangularNumber);

    int x = 1;

    int s = (x) ? 1 : 0;

    printf("%i", s);

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
