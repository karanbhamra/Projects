/* =====================================================================================
 *       Filename:  LinkedList2.c
 *    Description: More linked list stuff
 *        Created:  01/26/2011 02:18:02 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>
struct entry *findEntry( struct entry *listPtr, int match);     // function prototype

struct entry { int value; struct entry *next; };

int main ( int argc, char *argv[] )
{
    struct entry n1, n2, n3;
    struct entry *listPtr, *listStart; 
    listStart = &n1;
    
    int search;

    n1.value = 100;
    n1.next = &n2;

    n2.value = 200;
    n2.next = &n3;

    n3.value = 300;
    n3.next = NULL;

    printf("Enter the value to locate: ");
    scanf("%i", &search);

    listPtr = findEntry(listStart, search);

    if (listPtr != NULL)
        printf("Found %i.\n", listPtr->value);
    else
        printf("Not found.\n");

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

struct entry *findEntry(struct entry *listPtr, int match)
{
    while (listPtr != NULL)
    {
        if (listPtr->value == match)
            return listPtr;
        else
            listPtr = listPtr->next;
    }
    
    return NULL;
}
