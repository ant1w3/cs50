#include <cs50.h>
#include <stdio.h>

int calculate_coins(int cents, int coin_value);

int main(void)
{
    int cents;


    const int QUARTER = 25;
    const int DIME = 10;
    const int NICKEL = 5;
    const int PENNY = 1;

    // Prompt the user for a positive integer
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Calculate quarters and rest
    int quarters = calculate_coins(cents, QUARTER);
    cents -= (QUARTER * quarters);

    // Calculate dimes and rest
    int dimes = calculate_coins(cents, DIME);
    cents -= (DIME * dimes);

    // Calculate nickels and rest
    int nickels = calculate_coins(cents, NICKEL);
    cents -= (NICKEL * nickels);

    // Calculate pennies
    int pennies = calculate_coins(cents, PENNY);

    // Print coins total
    printf("%i\n", quarters + dimes + nickels + pennies);
}

int calculate_coins(int cents, int coin_value)
{
    int coins = 0;
    while (cents >= coin_value)
    {
        coins++;
        cents -= coin_value;
    }

    return coins;
}

