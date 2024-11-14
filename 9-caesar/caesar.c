#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string rotate(string s, int k);

int main(int argc, string argv[])
{
    // Prompt for a single CLI argument containing only digits
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, l = strlen(argv[1]); i < l; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Prompt for plaintext
    string plaintext = get_string("plaintext:  ");

    // Encrypt plaintext to ciphertext
    string ciphertext = rotate(plaintext, atoi(argv[1]));

    // Print result
    printf("ciphertext: %s\n", ciphertext);
}

string rotate(string s, int k)
{
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        if (islower(s[i]))
        {
            int initial_index = s[i] - 'a';
            int new_index = (initial_index + k) % 26;
            s[i] = new_index + 'a';
        }
        else if (isupper(s[i]))
        {
            int initial_index = s[i] - 'A';
            int new_index = (initial_index + k) % 26;
            s[i] = new_index + 'A';
        }
    }

    return s;
}

