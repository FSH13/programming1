/*********************************************************************
* cypher.c

* Mirthe Koerts

* - Encrypts messages using a two cyphers:
* - Switching each letter's casing
* - Replacing each letter with matching letters on other end of alphabet
* Usage of -l as command line argument results in all lower case
*********************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // ask the user for a text message
    string text = get_string("plaintext: ");

    // make a variable for the length of the message
    int length = strlen(text);

    // store all lower and upper case letters of the alphabet in a string
    char low_letters[] = {"abcdefghijklmnopqrstuvwxyz"};
    char up_letters[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    // store the length of both alphabet strings in a variable
    int low_length = strlen(low_letters);
    int up_length = strlen(up_letters);

    // check for the command line argument "-l"
    if (argc > 1 && strcmp(argv[1], "-l") == 0)
    {
        for (int i = 0; i < length; i++)
        {
            // check for every character that is not a letter
            if (!isalpha(text[i]))
            {
                // go to next character
                i++;
            }
            // make every letter lower case
            text[i] = tolower(text[i]);

            // replace letter with letter on other side of the alphabet
            text[i] = low_letters[(low_length - 1) - (text[i] - 'a')];
        }
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            // check for every character that is not a letter
            if (!isalpha(text[i]))
            {
                // go to next character
                i++;
            }

            if (islower(text[i]))
            {
                // replace lower case letter in opposite letter & make upper case
                text[i] = low_letters[(low_length - 1) - (text[i] - 'a')];
                text[i] = toupper(text[i]);
            }
            else
            {
                // replace upper case letter in opposite letter & make lower case
                text[i] = up_letters[(up_length - 1) - (text[i] - 'A')];
                text[i] = tolower(text[i]);
            }
        }
    }
    // show the message after cypher is applied
    printf("cyphertext: %s", text);
    printf("\n");
    return 0;
}
