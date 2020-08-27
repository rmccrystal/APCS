// Implement a program that calculates the minimum number of coins required to give a user change.

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int calculateChangeCoins(int totalCents, const int *coinAmounts, size_t coinAmountsLen);

// Must be sorted by greatest to least
int CoinAmounts[4] = {25, 10, 5, 1};

int main(void)
{
    // Get input until it's valid
    float dollars;
    while (true)
    {
        dollars = get_float("Change owed: ");
        if (dollars > 0)
            break;
    }

    float cents = roundf(dollars * 100);
    int coins = calculateChangeCoins((int) cents, CoinAmounts, 4);
    printf("%d\n", coins);
}

int calculateChangeCoins(int totalCents, const int *coinAmounts, size_t coinAmountsLen)
{
    // The total amount that our coins are adding up to
    int amount = 0;

    // The index of the coinAmounts
    int index = 0;

    // The amount of coins that we used
    int coinsUsed = 0;

    while (amount < totalCents)
    {
        int amountLeft = totalCents - amount;

        if (amountLeft == 0)
        {
            break;
        }

        // If the current coin we're on is smaller than the amount left
        if (coinAmounts[index] <= amountLeft)
        {
            coinsUsed++;
            amount += coinAmounts[index];
        } else
        {
            index++;

            // If there is no smaller coin that we can check, return an error
            if (index >= coinAmountsLen)
            {
                printf("Unable to calculate the amount of coins\n");
                return -1;
            }
        }
    }

    return coinsUsed;
}
