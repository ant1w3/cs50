#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Function to calculate the number of digits in a given number
int calc_length(long n);

// Function to apply Luhn's algorithm to a valid credit card number
int luhn_algorithm(long n, int length);

int main(void)
{
    // Prompt the user to enter a credit card number
    long credit_card_number;
    do
    {
        credit_card_number = get_long("Number: ");
    }
    while (credit_card_number < 1); // Ensures a positive number is enter

    // Calculate the length of the credit card number
    int length = calc_length(credit_card_number);

    // Check for valid length
    if (length != 13 && length != 15 && length != 16)
    {
        printf("%s\n", "INVALID");
        return 0;
    }

    // Check for valid number
    if(!luhn_algorithm(credit_card_number, length))
    {
        printf("INVALID\n");
        return 0;
    }

    // Determine the credit card company
    int first_digit = credit_card_number / pow(10, length - 1);
    int first_two_digits = credit_card_number / pow(10, length - 2);
    string status;

    if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        status = "AMEX";
    }
    else if (length == 16 &&
            (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 ||
            first_two_digits == 54 || first_two_digits == 55))
    {
        status = "MASTERCARD";
    }
    else if ((length == 13 || length == 16) && first_digit == 4)
    {
        status = "VISA";
    }
    else
    {
        status = "INVALID";
    }

    // Print the credit card type
    printf("%s\n", status);
}



int calc_length(long n)
{
    int length = 0;

    if (n == 0)
    {
        length = 1;
    }

    while (n != 0)
    {
        n /= 10;
        length++;
    }

    return length;
}



int luhn_algorithm(long n, int length)
{
    int checksum = 0;
    int digit;

    for (int i = 0; i < length; i++)
    {

        // Extract the last digit of the number
        digit = n % 10;

        if (i % 2 == 0)
        {
            checksum += digit;
        }
        else
        {
            digit *= 2;

            if (digit > 9)
            {
                checksum += digit / 10 + digit % 10;
            }
            else
            {
                checksum += digit;
            }
        }

        n /= 10;
    }

    return (checksum % 10) == 0;
}

