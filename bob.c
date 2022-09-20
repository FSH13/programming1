#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	string input = get_string("input: ");
	int count=0;

	for (count = 0; count < strlen(input); count=count+2)
	{
		if (input[count] >= 'a' && input[count]<= 'z')
		{input[count] = toupper(input[count]);}
	}
	printf("%s\n", input);
}
