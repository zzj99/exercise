#include <stdio.h>
/* print Celsius-Fahrenheit table
   for celsius = 0, 20, ..., 300; floating-point version */
main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;

    /* print heading over table*/
    printf("Celsius Fahr\n");
    /* lower limit of temperatuire scale */
    /* upper limit */
    /* step size */
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
