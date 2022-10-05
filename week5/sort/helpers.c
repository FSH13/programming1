// Helper functions
// loop van links naar rechts over de array
// kijk niet naar het laatste nummer, dat is al correct als de rest goed staat
// controleer voor alle nummers rechts van huidig of deze groter is of niet.
// is het huidig nummer groter swap the numbers



#include <cs50.h>
#include "helpers.h"

// Sorts array of n values
void sort(int values[], int n)
{
	int new_value;
    // implement an O(n^2) sorting algorithm
	for (int c = 0; c < n; c++)
	{
		for (int cn = c+1; cn < n; cn++)
		{
			if(values[c] > values[cn])
			{
				new_value = values[cn];
				values[cn] = values[c];
				values[c] = new_value;
			}
		}
	}
    return;
}
