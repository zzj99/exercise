/* Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion 
 */

#include <stdio.h>

float Fahr_to_Celsius(float Fahr);
float Celsius_to_Fahr(float Celsius);

main()
{
    float lower, upper, step;
    float fahr, celsius;

    lower = 0.0;
    upper = 300.0;
    step = 20.0;

    // test Fahr to Celsius
    fahr = lower;   
    while (fahr <= upper) {
        celsius = Fahr_to_Celsius(fahr);
        printf("%6.1f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    // test Celsius to Fahr
    celsius = lower;   
    while (celsius <= upper) {
        fahr = Celsius_to_Fahr(celsius);
        printf("%6.1f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}

float Fahr_to_Celsius(float Fahr)
{
    float Celsius;
    Celsius = (5.0/9.0)*(Fahr-32.0);
    return Celsius;
}
float Celsius_to_Fahr(float Celsius)
{
    float Fahr;
    Fahr = (9.0/5.0) * Celsius + 32.0;
    return Fahr;
}
