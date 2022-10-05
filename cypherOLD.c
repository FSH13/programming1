
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char REVERSE[] = {"Z", "Y", "X", "W", "V", "U", "T", "S", "R",
                    "Q", "P", "O", "N", "M", "L", "K", "J", "I",
                    "H", "G", "F", "E", "D", "C", "B", "A"};
  char REVLOW[] = {"z", "y", "x", "w", "v", "u", "t", "s", "r",
                   "q", "p", "o", "n", "m", "l", "k", "j", "i",
                   "h", "g", "f", "e", "d", "c", "b", "a"};
  string plaintext = get_string("Provide plain text: ");
  string text = plaintext;
  string capstext = plaintext;
  string cyphertext;
  int count = 0;

  for (count = 0; count < strlen(plaintext); count++) {
                if(islower(plaintext[count] )
		{
      // text[count] = toupper(plaintext[count]);
      cyphertext[count] = REVERSE[count];
		}
		else if(isupper(plaintext[count])
		{
      //	text[count] = tolower(plaintext[count]);
      cyphertext[count] = REVLOW[count];
		}
  }
  printf("cyphertext: %s\n", cyphertext);
}
