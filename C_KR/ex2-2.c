/* Exercise 2-2. Write a loop equivalent to the for loop above without using && or || .
 */
  
#include <stdio.h>

#define MAXLINE 1000
main() 
{
    int i;
    int lim;
    char c;
    char s1[MAXLINE];
    char s2[MAXLINE];
    lim = MAXLINE;
    int l1, l2;
    printf("Please input some characters, end with Ctrl-D:\n");
    for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) {
        s1[i] = c;
        l1 = i;
    }    

    printf("Please input same characters as above, end with Ctrl-D:\n");
    i=0;   
    while( c=getchar() )
    {
        if ( i >= lim-1) 
            break;

        if ( c=='\n')
            break;

        if ( c==EOF )
            break;
        s2[i]=c;
        l2 = i;
        ++i;
    }
    if (l1 != l2) {
        printf ("Different loop, ends with different length\n");
        return 0;
    }

    // compare s1 and s2
    int VALID = 0;
    for (i=0; i < l1; ++i)
        if (s1[i] != s2[i])  
            VALID = 1;        
         
    if (VALID == 0)
        printf("Same loop!\n");
    else
        printf("Different loop, ends with different characters!\n");
    return 0;
}
