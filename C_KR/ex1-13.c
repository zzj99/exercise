/*
 * A program to print a histogram of the lengths of words in its input.
 */

#include <stdio.h>

/* Draw the histogram with the bars horizontal */
void print_horizontal(int nw, int wl[])
{
    int i, j;
    for (j = 0; j < nw; j++) {
        for (i = 1; i <= wl[j]; i++)
            printf("=");
        printf("\n");
    }
}

/* a vertical orientation is more challenging */
void print_vertical(int nw, int wl[])
{
    int i, j;
    int maxlen = wl[0];
    for (j = 1; j < nw; j++) {
        if (wl[j] > maxlen)
            maxlen = wl[j];
    }
    for (i = maxlen; i >= 1; i--) {
        for (j = 0; j < nw; j++) {
            if (wl[j] >= i) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}


main()
{
    int c;
    int wl[100], nw; // assume no more than 100 words    
    int i;
    int is_word = 0;

    nw = 0;
    for (i = 0; i < 100; i++)
        wl[i] = 0;
    /* get the length of each word */
    while ( (c=getchar()) != EOF ) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (is_word == 1) {
                ++nw; // a word ends
            }
            is_word = 0;
        }
        else{ 
            wl[nw] += 1;  // increase length
            if (is_word == 0) {
                is_word = 1;
            }
        }
    }
    print_horizontal(nw, wl);
    print_vertical(nw, wl);
}

