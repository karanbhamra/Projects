/* =====================================================================================
 *       Filename:  BaseConverter.c
 *    Description:  Converts one base to another
 *        Created:  01/16/2011 07:56:08 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>

int main ( int argc, char *argv[] )
{
    const char baseDigits[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

    int convertedNumber[64];
    long int numberToConvert;
    int nextDigit, base, index = 0;

    // Get the number and the base
    
    printf("Number to be converted? ");
    scanf("%ld", &numberToConvert);
    printf("Base? ");
    scanf("%i", &base);

    // Convert to the indicated base

    do {
        convertedNumber[index] = numberToConvert % base;
        ++index;
        numberToConvert = numberToConvert / base;
    } while ( numberToConvert != 0);

    // Display the results in reverse order

    printf("Converted number = ");
    for (--index; index >= 0; -- index)
    {
        nextDigit = convertedNumber[index];
        printf("%c", baseDigits[nextDigit]);
    }

    printf("\n");

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
