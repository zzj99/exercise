/*Write a program to print all input lines that are longer than 80 characters.*/
#include <stdio.h>

#define MAXLINE 1000

int gline(char s[], int lim);

main()
{
    int len;
    char line[MAXLINE];
    while ((len=gline(line, MAXLINE)))
    {
        if (len > 80) {
            printf("%s",line);
        }
    }
    return 0;
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
