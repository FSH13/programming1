/****************************************************************************
 * cypher.c
 *
 * Programming1
 *
 * - changes user provided plaintext to a specific cypher
 * - output is cyphertext
 ***************************************************************************/#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
	// set all variables
	char ALPHABET[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char ALPHLOW[] = {"abcdefghijklmnopqrstuvwxyz"};
	char REVERSE[] = {"ZYXWVUTSRQPONMLKJIHGFEDCBA"};
	char REVLOW[] = {"zyxwvutsrqponmlkjihgfedcba"};

	string plaintext = get_string("Provide plain text: ");
	string text = plaintext;
	string cyphertext = plaintext;
	string l = "-l";
	int count = 0, lower = 1;

	// if the user entered -l in the command line, set lower
	if(argc > 1) {lower = strcmp(argv[1],l);}

	// adjust the uppers to lowers and visa versa if it's not a letter
	for (count = 0; count < strlen(plaintext); count++)
	{
		if (islower(plaintext[count])&& lower != 0)
		{
			text[count] = toupper(plaintext[count]);
		}
		else if (isupper(plaintext[count]))
		{
			text[count] = tolower(plaintext[count]);
		}
		// if it's not a letter take the character as is
		else
		{
			text[count] = plaintext[count];
		}
	}

	count = 0;
	int c = 0;
	// loop over the replaced letters and replace with opposite letter of alphabet
	while (c < strlen(plaintext))
	{
		if (islower(text[c]))
		{
			if (text[c] == ALPHLOW[count])
			{
				cyphertext[c] = REVLOW[count];
				count = 0;
				c++;
			}
			else {count++;}
		}
		else if( isupper(text[c]))
		{
			if(text[c] == ALPHABET[count])
                        {
				cyphertext[c] = REVERSE[count];
				count = 0;
				c++;
                        }
			else {count++;}
		}
		// if the character is not a letter, replace as is
		else
		{
			cyphertext[c] = text[c];
			count = 0;
			c++;
		}
	}
	printf("cyphertext: %s\n", cyphertext);
}
