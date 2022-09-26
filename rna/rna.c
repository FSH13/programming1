#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//DNA keten = ATGC
//RNA keten = UACG

int main (int rnac, string rnav[])
{
	if (rnac > 2) {printf("Usage: %s %s\n",rnav[0], rnav[1]); return 1;}
	if (rnac < 2) {printf("Usage: %s ATGC\n",rnav[0]); return 1;}
	if (rnac == 2)
	{
		int max = strlen(rnav[1]);
		string dna = rnav[1];
		string rna = dna;
		for (int c = 0; c < max; c++)
		{
			dna[c] = toupper(rnav[1][c]);
			if(dna[c] != 'A' && dna[c] != 'T' && dna[c] != 'G' && dna[c] != 'C')
			{
				rna = "Invalid DNA";
				printf("%s\n", rna);
				return 1;
			}
			else
			{
				if (dna[c] == 'A') {rna[c] = 'U';}
				else if (dna[c] == 'T') {rna[c] = 'A';}
				else if (dna[c] == 'G') {rna[c] = 'C';}
				else if (dna[c] == 'C') {rna[c] = 'G';}
			}
		}
		printf("%s\n", rna);
	}
}
