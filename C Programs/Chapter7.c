/* =====================================================================================
 *       Filename:  Chapter7.c
 *    Description:  Chapter 7 Excercises
 *        Created:  01/16/2011 07:21:21 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>

int main ( int argc, char *argv[] )
{
    // Testing variable size arrays in C99
    int i;
    printf("Enter array size: ");
    scanf("%i", &i);
    
    char c[i];

    for (int x= 0; x< i; x++)
    {
        if (c[x])
            printf("NOT NULL\t %p\n", &c[x]);
            else
                printf("NULL\t\t %p\n", &c[x]);
    }

    char word[] = "hello";

    int j =0;
    while (word[j])
    {
        printf("%c", word[j++]);
    }

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
