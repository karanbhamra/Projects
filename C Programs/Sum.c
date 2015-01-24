/* =====================================================================================
 *       Filename:  Sum.c
 *    Description:  Sum using pointers
 *        Created:  01/26/2011 03:59:19 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>

int arraySum(int *array, const int n)
{
    int sum = 0;
    int * const arrayEnd = array + n;
    
    for (;array<arrayEnd; ++array)
        sum += *array;

    return sum;
}

void copyString(char to[], char from[])
{
    int i;
    
    for(i =0; from[i] != '\0'; ++i)
        to[i] = from[i];

    to[i] = '\0';

}

int stringLength(const char *string)
{
    const char *cptr = string;

    while (*cptr)
        ++cptr;
    return cptr - string;
}

int main ( int argc, char *argv[] )
{
    int values[10]= {3,7,-9,3,6,-1,7,9,1,-5};

    printf("The sum is %i\n", arraySum(values, 10));

    char string1[] = "A string to be copied.";
    char string2[50];

    copyString(string2, string1);
    printf("%s\n", string2);

    char *textPtr;
    char *textPtr2;
    textPtr = "My name is karan";
    textPtr2 = "BLAH BLAH BLAH";
    printf("%s\n", textPtr);

    int p =textPtr2-textPtr;    // number of elements between two pointers
    
    int x[99];

    int n = &x[99]-&x[0];

    printf("%p\t%p\n", textPtr, textPtr2);
    printf("%i\n", p);
    printf("%i\n", n);
    printf("%i\n", stringLength(textPtr));
////////////////////////////////////////////////////////////////////////
int lookup(void);   // function prototype
int (*fnPtr) (void);
fnPtr = lookup;

int entry = fnPtr();
printf("%i", entry);

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

int lookup(void)
{
    return 666;
}
