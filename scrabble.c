#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string lower_str(string s);
int calc_score(string s);

const int VALUES[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Prompt for words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calculate word scores
    int score1 = calc_score(lower_str(word1));
    int score2 = calc_score(lower_str(word2));

    // Print result
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

string lower_str(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if(isupper(s[i]))
        {
            s[i] = tolower(s[i]);
        }
    }

    return s;
}

int calc_score(string s)
{
    int score = 0;

    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]))
        {
            int index = s[i] - 'a';
            score += VALUES[index];
        }
    }

    return score;
}

