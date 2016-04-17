/*Revise the main routine of the longest-line program so it will correctly print
  the length of arbitrary long input lines, and as much as possible of the text.*/

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int gline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
main()
{
    int len; /* line of current length */
    int max; /* maximum length seen so far */
    char line[MAXLINE];/* current input line */
    char longest[MAXLINE];/* longest line saved here */
    int i;

    max = 0;
    while ((len = gline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
    {
        printf("%d\n",max);
        printf("%s\n",longest);
    }
    return 0;
}
/* gline: read a line into s, return length,
* if actual length is longer than limit, return the actural length, 
* but line only contains limited length of characters 
*/
int gline(char s[],int lim)
{
    int c, i, len;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    {
        s[i] = c;
    }
    len = i;
    if (c == '\n') {
        s[i] = c;
        ++i;
    } else {
        while ( (c=getchar())!=EOF ) 
            ++len;
    }
    s[i] = '\0';
    return len;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
