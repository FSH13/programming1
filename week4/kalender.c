
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	int row = 0;
	int column = 0;
	int r_max = 6;
	int c_max = 7;
	int days = 0;
	int days_max = 31;


	for (row = 0; row < r_max; row++)
	{
		for (column = 0; column < c_max; column++)
		{
			printf("%3d ", days);
			days++;
		}
		column = 0;
		printf("\n");
	}
}
