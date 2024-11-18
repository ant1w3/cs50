#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Function to calculate total or average hours
float calc_hours(int w, int h[], string op);

int main(void)
{
    // Prompt for a number of weeks
    int num_of_weeks;
    do
    {
        num_of_weeks = get_int("Number of weeks taking CS50: ");
    }
    while (num_of_weeks < 1);

    // Store hours in an array
    int hours[num_of_weeks];
    for (int i = 0; i < num_of_weeks; i++)
    {
        do
        {
            hours[i] = get_int("Week %i HW hours: ", i);
        }
        while (hours[i] < 0);
    }

    // Prompt the user for T (total) or A (average)
    string operation = " ";

    do
    {
        operation = get_string("Enter T for total hours, A for average hours per week: ");
    }
    while (strcmp(operation, "T") != 0 && strcmp(operation, "A") != 0);

    // Print result
    printf("%.1f hours\n", calc_hours(num_of_weeks, hours, operation));
}

// Function to calculate total or average hours
float calc_hours(int w, int h[], string op)
{
    float output = 0.0;
    int total = 0;

    // Calculate total hours
    for (int i = 0; i < w; i++)
    {
        total += h[i];
    }

    // Determine output based on operation
    if (strcmp(op, "T") == 0)
    {
        output = total;
    }
    else if (strcmp(op, "A") == 0)
    {
        output = total / (float) w;
    }

    return output;
}

