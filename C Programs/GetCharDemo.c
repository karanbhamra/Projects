/* =====================================================================================
 *       Filename:  GetCharDemo.c
 *    Description:  Testing out getchar()
 *        Created:  01/19/2011 08:51:09 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>

int main ( int argc, char *argv[] )
{
    printf("Enter a string (<= 80 chars) (Enter to exit):");
    char c;
    char buffer[81];
    int i = 0;
    while(1)
    {
        if (i > 80)     // prevent buffer overflow
            break;
        c = getchar();

        if (c == '\n')
            break;
        if (c == EOF)
            break;
        buffer[i++] = c;
    }
    buffer[i] = '\0'; // null terminate the string on the 81st character

    printf("\aYou typed in: %s\n", buffer);

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
