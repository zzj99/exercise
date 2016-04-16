/*Write a program to print a histogram of the frequencies of different characters*/

#include <stdio.h>

#define NCHAR 128
main()
{
    int c;
    int ch[NCHAR]; // 256 ASCII codes
    int i, j;

    // initialize
    for (i = 0; i < NCHAR; i++)
    {
        ch[i] = 0;
    }
    while ( (c=getchar()) != EOF ) { 
        ch[c] += 1;
    }

    /* Draw the histogram with the bars horizontal */
    for (j = 0; j < NCHAR; j++) {
        if (ch[j] > 0) {
            printf( "%c:   ", (char)j );
            for (i = 1; i <= ch[j]; i++)
                printf("=");
            printf("\n");
        }
    }
}
