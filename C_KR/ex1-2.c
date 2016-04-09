#include <stdio.h>

main()
{
    /*
       ex1-2.c: In function ‘main’:
       ex1-2.c:5:13: warning: unknown escape sequence: '\w'
       printf ("Hello \w\orld!\n");
       ^
       ex1-2.c:5:13: warning: unknown escape sequence: '\o'
     */
    printf ("Hello \w\orld!\n");
}
