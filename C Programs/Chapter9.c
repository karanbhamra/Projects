/* =====================================================================================
 *       Filename:  Chapter9.c
 *    Description:  Chapter 9 Excercises
 *        Created:  01/17/2011 08:50:30 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>
#include    <stdbool.h>

int main ( int argc, char *argv[] )
{
    struct date
    {
        int month;
        int day;
        int year;
        char name[3];
    };

    struct date today;
    
    today.month = 1;
    today.day = 17;
    today.year = 2011;
    today.name[0]= 'J';
    today.name[1]= 'a';
    today.name[2]= 'n';

    struct date tomorrow;

    tomorrow = (struct date) { today.month, today.day+1, today.year};

    printf("Today's date is %i/%i/%.2i- Month: %c%c%c.\n", today.month, today.day, today.year%100, today.name[0], today.name[1], today.name[2]);
    printf("Tomorrow's date is %i/%i/%.2i.\n", tomorrow.month, tomorrow.day, tomorrow.year%100);    
    printf("The size of the date struct is %li bytes.\n", sizeof(today));

    bool test = true;
    char name[3];

    printf("%li bytes.", sizeof(name));

    if (test)
        printf("TRUE");
        else
            printf("FALSE");

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
