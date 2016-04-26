/*Write a function reverse(s) that reverses the character string s . 
 * Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAXLINE 1000

int gline(char s[], int lim);
void reverse(char s[]);

main()
{
    char line[MAXLINE];
    int len;
    while((len=gline(line,MAXLINE))>0)
        reverse(line);

    return;
}

void reverse(char s[])
{
    int i, n;

    /** get length */  
    n = 0;
    while ( s[n] != '\0')
        ++n;

    for (i=0;i<n;++i)
        printf("%c",s[n-1-i]);

    return;
}
int gline(char s[], int lim)
{
    int i, c;
    for (i=0; i< lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
