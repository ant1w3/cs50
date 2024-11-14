#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt for a text
    string text = get_string("Text: ");

    // Compute Coleman-Liau index
    int letters = 0;
    int words = 1;
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

        if (isblank(text[i]))
        {
            words++;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?' )
        {
            sentences++;
        }
    }

    float letters_avg = ((float) letters / words) * 100;
    float sentences_avg = ((float) sentences / words) * 100;

    float grade = (0.0588 * letters_avg) - (0.296 * sentences_avg) - 15.8;
    int rounded_grade = round(grade);

    // Print result
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rounded_grade);
    }

}

