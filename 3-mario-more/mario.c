#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for an int between 1 and 8
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Loop to print each row of the pyramid
    for (int i = 0; i < n; i++)
    {
        // Print the leading spaces
        for (int j = 0; j < n - (i + 1); j++)
        {
            printf(" ");
        }

        // Print left side of the pyramid
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        // Print the gap between the two sides of the pyramid
        printf(" ");

        // Print right side of the pyramid
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }
}

