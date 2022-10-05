#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// const int LENGTE;

int main(void) {
  string input = get_string("Wat wil je me vertellen? ");
  int count;
  for (count = 0; input[count] != '\0'; count++) {
    printf("%c\n", input[count]);
  }
}
