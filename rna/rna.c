#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//DNA keten = ATGC
//RNA keten = UACG

int main (int rnac, string rnav[])
{
	if (rnac == 2)
	{
		string rna;
		for (int c = 0; c < strlen(rnav[1]); c++)
		{
			if(rnav[1][c] != "A" || rnav[1][c] != "T" || rnav[1][c] != "G" || rnav[1][c] != "C")
			{
				rna = "Invalid DNA";
			}
			else
			{
				string rna;
				if (rnav[1][c] == "A") {printf("U");}
				else  if (rnav[1][c] == "T") {printf("A");}
				else if (rnav[1][c] == "G") {printf("C");}
				else  if (rnav[1][c] == "C") {printf("G");}
			}
//		if (rna == "Invalid") {printf("Invalid DNA");}
//		else {Printf("%s\n", rna);}
		}
	}
}
