#include <stdio.h>

/* program to count blanks, tabs and newlines 
 * 
 * I learned from this exercise 
 *   + '\t' not "\t"
 *   + EOF is Ctrl+D on Linux, Ctrl+Z on Windows
 */
main()
{
    int nblank , ntab, nline;
    int c;

    nblank = 0;
    ntab = 0;
    nline = 0;    
    while ( (c=getchar()) != EOF ) {
        if (c == ' ') {
            ++nblank;
        } else if (c == '\t') {
            ++ntab;
        } else if (c == '\n') {
            ++nline;
        }
    }
    printf("blanks: %d, tabs: %d, newlines: %d\n",nblank, ntab, nline);
}
