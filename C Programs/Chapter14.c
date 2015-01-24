/* =====================================================================================
 *       Filename:  Chapter14.c
 *    Description:  Chapter 14 Excercises
 *        Created:  02/01/2011 08:01:47 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>

int main ( int argc, char *argv[] )
{
    enum primaryColor { red, yellow, blue };

    enum primaryColor myColor, gregsColor;

    myColor = red;
    gregsColor = blue;

    if ( myColor == red)
        printf("My color is red!\n");

    enum month { january=1, february, march, april, may, june, july, august, september, october, november, december };

    enum month aMonth;
    int days;
    int input;
    printf("Enter month number: ");
    scanf("%i", &input);

    aMonth = (enum month) input;
    switch(aMonth)
    {
        case january:
        case march:
        case may:
        case july:
        case august:
        case october:
        case december:
            days = 31;
            break;
        case april:
        case june:
        case september:
        case november:
            days = 30;
            break;
        case february:
            days = 28;
            break;
        default:
            printf("Bad month number\n");
            days = 0;
            break;
    }

    if ( days != 0)
        printf("Number of days is %i\n", days);

    if ( aMonth == february)
        printf("... or 29 if it's a leap year\n");

    typedef int Counter;

    Counter j = 0, n = 1;

    printf("%i  %i\n", j, n);

    typedef char Linebuf [81];

    Linebuf text;

    scanf("%s", text);

    text[80] = '\0';
    printf("%s\n", text);

    typedef char *string;

    string test = "My name is karan";

    printf("%s\n", test);

    typedef struct
    {
        int month;
        int day;
        int year;
    } Date;

    Date today = {2,1,2011};

    printf("%i/%i/%i\n",today.month,today.day,today.year);

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
