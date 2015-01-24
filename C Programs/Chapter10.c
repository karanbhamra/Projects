/* =====================================================================================
 *       Filename:  Chapter10.c
 *    Description:  Chapter 10 Excercises
 *        Created:  01/18/2011 08:45:47 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>
#include    <stdbool.h>

bool equalstrings(const char s1[], const char s2[])
{
    bool areEqual;
    int i = 0;

    while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
        ++i;

    if (s1[i] == '\0' && s2[i] == '\0')
        areEqual = true;
    else
        areEqual = false;

    return areEqual;
}

int stringlength(const char string[])
{
    int count = 0;

    while (string[count] != '\0')
        ++count;

    return count;
}

int main ( int argc, char *argv[] )
{
    const char word1[] = "karan";
    const char word2[] = "singh";
    const char word3[] = "bhamra";

    int size = printf("karan");

    printf("%i   %i  %i\n", stringlength(word1), stringlength(word2), stringlength(word3));
    printf("%s %s %s\n", word1, word2, word3);
    printf("%i\n", size);

    printf("%i\n", equalstrings(word1, word2));
    printf("%i\n", equalstrings(word2, word3));
    printf("%i\n", equalstrings(word1, word1));
    printf("%i\n", equalstrings(word1, "karan"));

    char buffer[81];

    printf("Enter a string (80 characters or less): ");
    scanf("%80s",buffer);   // to prevent buffer overflow, limit it to 80 and leave the extra for the null termination

    printf("%s\n", buffer);


    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
