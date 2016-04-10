/* A program that prints its input one word per line. */

#include <stdio.h>

#define IS_WORD 1
#define NOT_WORD 0

main()
{
    int c;
    int status = NOT_WORD;

    /* word */
    while ( (c=getchar()) != EOF ) {
        if ( c == ' ' || c == '\t' || c == '\n' )
            status = NOT_WORD;
        else {
            if (status == NOT_WORD) {
                status = IS_WORD;
                putchar('\n');
            }
            putchar(c);
        }
    }
}
