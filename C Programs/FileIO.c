/* =====================================================================================
 *       Filename:  FileIO.c
 *    Description:  Chapter 16 Excercises
 *        Created:  02/08/2011 05:52:54 PM
 *         Author:  Karan Bhamra , karan.bhamra@gmail.com
 * ===================================================================================== */

#include	<stdlib.h>
#include    <stdio.h>

int main ( int argc, char *argv[] )
{

    char inName[64], outName[64];
    FILE *in, *out;
    int c;
    //get file names from user

    printf("Enter name of the file to be copied: ");
    scanf("%63s", inName);
    printf("Enter name of the output file: ");
    scanf("%63s", outName);

    // open input and output files
    
    if ((in = fopen(inName, "r")) == NULL)
    {
        printf("Can't open %s for reading.\n", inName);
        return 1;
    }

    if ((out=fopen(outName,"w")) == NULL)
    {
        printf("Can't open %s for writing.\n", outName);
        return 2;
    }

    

    // copy in to out
    while((c=getc(in)) != EOF)
        putc(c, out);

    fprintf(out, "File copied successfully.\n");

    fclose(in);
    fclose(out);
    printf("File has been copied.\n");

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
