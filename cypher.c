#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
	char ALPHABET[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char ALPHLOW[] = {"abcdefghijklmnopqrstuvwxyz"};
	char REVERSE[] = {"ZYXWVUTSRQPONMLKJIHGFEDCBA"};
	char REVLOW[] = {"zyxwvutsrqponmlkjihgfedcba"};
	string plaintext = get_string("Provide plain text: ");
	string text = plaintext;
	string cyphertext = plaintext;

	string l = "-l";
	int count = 0;
	int lower = 1;
	if(argc > 1) {lower = strcmp(argv[1],l);}
	printf("%i\n", lower);
//	if(argc > 1) {lower = 1;}

	while( count < strlen(plaintext))
	{
		if(islower(plaintext[count])&& lower != 0)
		{
			text[count] = toupper(plaintext[count]);
			count++;
		}
		else if(isupper(plaintext[count]))
		{
			text[count] = tolower(plaintext[count]);
			count++;
		}
		else
		{
			text[count] = plaintext[count];
			count++;
		}
//	printf("%s lower: %i\n",text, lower);
	}

	count = 0;
	int c = 0;

	while(c < strlen(plaintext))
		if(islower(text[c]))
		{
			if(text[c] == ALPHLOW[count])
			{
				cyphertext[c] = REVLOW[count];
				c++; count = 0;
			}
			else {count++;}
 			//printf("%s\n", text);
		}
		else if( isupper(text[c]))
		{
			if(text[c] == ALPHABET[count])
                        {
				cyphertext[c] = REVERSE[count];
				c++; count = 0;
                        }
			else {count++;}
		}
		else
		{
			cyphertext[c] = text[c];
			c++; count =0;
		}

	printf("cyphertext: %s\n", cyphertext);
}

