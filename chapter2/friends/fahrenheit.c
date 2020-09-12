#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

float c_to_f(float celsius);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Too little args. Usage: ./fahrenheit <celsius>\n");
        return 1;
    }

    float celsius = atof(argv[1]);
    float fahrenheit = c_to_f(celsius);

    printf("F: %.1f\n", fahrenheit);
}

/// Converts Celsius to Fahrenheit
float c_to_f(float celsius)
{
    return ((celsius * 9) / 5) + 32;
}
