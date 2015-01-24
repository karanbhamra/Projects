/* =====================================================================================
 *       Filename:  Chapter11.c
 *    Description:  Chapter 11 Excercises
 *        Created:  01/25/2011 04:09:56 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>

int main ( int argc, char *argv[] )
{
    int count = 10, x;
    int *int_pointer;

    int_pointer = &count;
    x = *int_pointer;

    printf("count = %i, x = %i\n", count, x);

    /////////////////////////////////////////////////

    char c = 'Q';
    char *char_pointer = &c;

    printf("%c %c\n", c, *char_pointer);

    c = '/';
    printf("%c %c\n", c, *char_pointer);

    *char_pointer = '(';
    printf("%c %c\n", c, *char_pointer);

    //////////////////////////////////////////////

    int i1, i2;
    int *p1, *p2;

    i1 = 5;
    p1 = &i1;
    
    i2 = *p1/2 + 10;

    p2 = p1;

    printf("i1 = %i, i2 = %i, *p1 = %i, *p2 = %i\n", i1, i2, *p1, *p2);

    /////////////////////////////////////////////////

    struct date
    {
        int month;
        int day;
        int year;
    };

    struct date todaysDate;

    struct date *datePtr;

    datePtr = &todaysDate;

    todaysDate.month = 1, todaysDate.day = 25, todaysDate.year = 2011;

    printf("%i/%i/%i\n",(*datePtr).month, (*datePtr).day, (*datePtr).year);

    if ((*datePtr).month == 1)
        printf("It's January!\n");

    if (datePtr->year == 2011)
        printf("It's the year 2011!\n");

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
