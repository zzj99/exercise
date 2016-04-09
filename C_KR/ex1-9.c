#include <stdio.h>

main()
{
    int c, nblank;
    
    nblank = 0;
    while( (c=getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
            nblank = 0;
        }
        else {
            ++nblank;
            if (nblank == 1)
                putchar(c);
        } 
    }
}
