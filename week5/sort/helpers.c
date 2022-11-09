// Helper functions
/****************************************************************************
 * helper.c
 *
 * programming1
 * Fleur
 *
 * - sorts a list of values from the sort.c file
 ***************************************************************************/

#include <cs50.h>
#include "helpers.h"

// sorts array of n values
void sort(int values[], int n)
{
    int new_value;

    // implement an O(n^2) sorting algorithm
    for (int c = 0; c < n; c++){

        //loop through all values that are to the right of c
        for (int cn = c + 1; cn < n; cn++){

            //if the value right (cn) is lower than c swap the values
            if (values[c] > values[cn]){
                new_value = values[cn];
                values[cn] = values[c];
                values[c] = new_value;
            }
        }
    }
    return;
}
