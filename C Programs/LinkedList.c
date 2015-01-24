/* =====================================================================================
 *       Filename:  LinkedList.c
 *    Description:  Linked List
 *        Created:  01/25/2011 05:20:38 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>

int main ( int argc, char *argv[] )
{
    struct entry
    {
        int value;
        struct entry *next;
    };

    struct entry n1, n2, n3;
    int i;
    struct entry *list_pointer = &n1;   // mark beginning of list

    n1.value = 100;
    n2.value = 200;
    n3.value = 300;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;   // mark list end with null pointer

    i = n1.next->value;

    while ( list_pointer != NULL) {   // traverse through the list
        printf("%i\n", list_pointer->value);
        list_pointer = list_pointer->next;
    }
   
/////////////////////////////////////////////////////////////////
   struct Person
   {
       char *name[80];
       int age;
   };

   struct Person karan, *guru;  // pointer to person struct and a person struct variable
   guru = &karan;   // guru pointer points to the same memory location as karan variable
   
   *guru->name = "guru";    // the pointer guru is changing the name pointer field in karan to "guru"
   guru->age = 18;      // guru pointer is setting the karan age field to 18

    printf("%s  %i\n", *guru->name, guru->age);
    int m;      // int variable
   int *k;      // int pointer

   k = &m;  // pointer will point to same place as the m variable
   *k = 19; // set the m variable to 19

   karan.age = *k;  // change the age variable from 18 to 19
   *karan.name = "karan";   // the name pointer field in karan is set to "karan"
   
    printf("%s  %i\n", *karan.name, karan.age);
/////////////////////////////////////////////////////////////////////

    char c = 'X';
    //char *charPtr = &c;
    char const *charPtr = &c;      // char pointer is a constant pointer to a character

    printf("%c\n", c);
    printf("%c\n", *charPtr);

    char x = 'C';
    printf("%c\n", x);

    charPtr = &x;
    printf("%c\n", *charPtr);

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
