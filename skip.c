#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  string input = get_string("tell me!! ");
  int lengte = strlen(input);

  for (int count = 0; count < lengte; count = count + 2) {
    printf("%c", input[count]);
  }
  printf("\n");
}
