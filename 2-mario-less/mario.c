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
    while(n < 1 || n > 8);

    // Loop to print each row oh the pyramid
    for(int i = 0; i < n; i++)
    {

        // Print leading spaces
        for(int j = 0; j < n - (i + 1); j++)
        {
            printf(" ");
        }

        // Print bricks
        for(int k = 0; k < i + 1;k++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }
}


