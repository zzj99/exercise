/* Write a program to remove trailing blanks and tabs from each line of input,
   and to delete entirely blank lines.*/

#include <stdio.h>

#define MAXLINE 1000

int getline_without_blank(char s[], int lim);

main()
{
    int len;
    char line[MAXLINE];
    while( (len=getline_without_blank(line, MAXLINE)))
    {
        if (len > 1)     
            printf("%s",line);
    }
}

int getline_without_blank(char s[], int lim)
{
    int i, c;
    i = 0;
    while( (c=getchar())!=EOF && c!= '\n' && i < lim-1 )
    {
        if (c != ' ' && c!= '\t'){
            s[i] = c;
            ++i;
        }
    }
    if (c == '\n')
    {
        s[i]=c;
        ++i;
    }

    s[i] = '\0';
    return i;
}
