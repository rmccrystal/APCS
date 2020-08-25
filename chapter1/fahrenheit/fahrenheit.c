#include <cs50.h>
#include <stdio.h>

float c_to_f(float);

int main(void)
{
    // get the celsius input
    float celsius = get_float("C: ");
    // convert it to fahrenheit
    float fahrenheit = c_to_f(celsius);

    // print out the result
    printf("F: %.1f", fahrenheit);
}

/// Converts Celsius to Fahrenheit
float c_to_f(float celsius)
{
    return ((celsius * 9) / 5) + 32;
}