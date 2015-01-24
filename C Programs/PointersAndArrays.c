/* =====================================================================================
 *       Filename:  PointersAndArrays.c
 *    Description:  Pointers and Arrays
 *        Created:  01/26/2011 02:34:01 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>

int main ( int argc, char *argv[] )
{
    int array[100];

    int *pointer = array;

    for (int x=0; x<100; x++)
        array[x] = x;   // populate the array with 0-99

    for (int i=0; i<100; i++)
        printf("%i ",*(pointer++));     // print out the array

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
