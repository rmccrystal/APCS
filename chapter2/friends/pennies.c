#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long double calculate_pennies(int days, int starting_pennies);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Too little arguments. Usage: ./pennies <days> <pennies on first day>\n");
        return 1;
    }

    int days;
    int starting_pennies;

    days = atoi(argv[1]);
    starting_pennies = atoi(argv[2]);

    double dollars = calculate_pennies(days, starting_pennies);
    printf("$%.2f\n", dollars);
}


/// Returns the dollars after the `starting_pennies` double every day for `days` days
long double calculate_pennies(int days, int starting_pennies)
{
    // initialize a total
    long double total = 0;

    // for every day, add the correct amount to the total
    for (int i = 0; i < days; i++)
    {
        total += powl(2, i) * starting_pennies;
    }

    return total / 100.0f;
}

