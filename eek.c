#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  string input = get_string("input: ");
  int count;
  int letters = 0;
  for (count = 0; count < strlen(input); count++) {
    if (input[count] == 'e' || input[count] == 'E') {
      letters++;
    }
  }
  if (letters == 1) {
    printf("The text %s contains %i e\n", input, letters);
  } else {
    printf("The text %s contains %i e's\n", input, letters);
  }
}
