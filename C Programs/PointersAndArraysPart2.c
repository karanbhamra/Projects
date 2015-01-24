/* =====================================================================================
 *       Filename:  PointersAndArraysPart2.c
 *    Description:  Part two of pointers
 *        Created:  01/26/2011 03:52:30 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>

int arraySum(int array[], const int n)
{
    int sum =0, *ptr;
    int * const arrayEnd = array + n;

    for (ptr = array; ptr < arrayEnd; ++ptr)
        sum += *ptr;

    return sum;
}

int main ( int argc, char *argv[] )
{
    int values[10] = {3,7,-9,3,6,-1,7,9,1,-5};
    
    printf("The sum is %i\n", arraySum(values, sizeof(values)/sizeof(int)));

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
