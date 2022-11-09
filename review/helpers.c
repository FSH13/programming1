// Helper functions

#include <cs50.h>

#include "helpers.h"

// Sorts array of n values
void sort(int values[], int n)
{

    // assign integer for storing values
    int value_high = 0;

    // loops through all values from start to n-1
    for (int j = 0; j < (n - 1); j++)
    {

        // loops through all values that are on the right of j
        for (int i = j + 1; i < n; i++)
        {

            // switches values if i is lower than j
            if (values[j] > values[i])
            {
                value_high = values[j];
                values[j] = values[i];
                values[i] = value_high;
            }
        }
    }
    return;
}
