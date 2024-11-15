#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int ALPHA_LEN = 26;

bool is_unique(string s);

int main(int argc, string argv[])
{
    // Prompt for a single CLI argument
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    string key = argv[1];

    // Check length
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    // Key must contain each letter only once and only alphabetical char
    for (int i = 0, l = strlen(key); i < l; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only alphabetical characters\n");
            return 1;
        }
    }

    // Check for unique characters
    if (!is_unique(key))
    {
        printf("Key must contain unique characters\n");
        return 1;
    }

    // Prompt for plaintext
    string plaintext = get_string("plaintext:  ");
    int plaintext_len = strlen(plaintext);

    // Encrypt plaintext
    char ciphertext[plaintext_len];
    for (int i = 0; i < plaintext_len; i++)
    {
        if (islower(plaintext[i]))
        {
            int index = plaintext[i] - 'a';
            ciphertext[i] = tolower(key[index]);
        }
        else if (isupper(plaintext[i]))
        {
            int index = plaintext[i] - 'A';
            ciphertext[i] = toupper(key[index]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    // Add NUL char to end the array
    ciphertext[plaintext_len] = '\0';

    // Print ciphertext
    printf("ciphertext: %s\n", ciphertext);
}

bool is_unique(string s)
{
    // Initialize all values
    bool seen[ALPHA_LEN] = {false};

    for (int i = 0, l = strlen(s); i < l; i++)
    {
        int index = toupper(s[i]) - 'A';

        if(seen[index])
        {
            return false;
        }

        seen[index] = true;
    }

    return true;
}

