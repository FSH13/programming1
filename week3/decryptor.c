#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

string cyphertext = get_string("Encripted text: ");
string plaintext = cyphertext;

string alfabet = "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z";

int a = 0 //alfabet
int c = 0; //tel aantal letters totaal strlen
int high = 0; //hoogste aantal tot nu
int count = 0; //telling huidige aantal letters
char letter_high; //letter met hoogste telling
char letter; //huidige letter

while(c < strlen(cyphertext)
{
	for(c = 0; alfabet[a] == cyphertext[c]; c++)
	{
		count++
		letter = alfabet[a]
	}

}

