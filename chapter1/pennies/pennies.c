#include <cs50.h>
#include <stdio.h>
#include <math.h>

//#define DEBUG

long double calculate_pennies(int days, int starting_pennies);

int main(void)
{
    int days;

    // loop until we get valid input
    while (true)
    {
        // get input from user
        int input = get_int("Days in month: ");

        // if we're in debug mode don't check if the input is valid
#ifdef DEBUG
        days = input;
        break;
#endif

        // check if the input is valid
        if (input >= 28 && input <= 31)
        {
            days = input;
            break;
        }

        // if the input is not valid, continue
    }

    int starting_pennies;

    while (true)
    {
        int input = get_int("Pennies on first day: ");
        if (input > 0)
        {
            starting_pennies = input;
            break;
        }
    }

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

