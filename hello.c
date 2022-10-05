#include <cs50.h>
#include <stdio.h>

int main(void) {
  string name = get_string("Wat is je naam? ");
  printf("hello, %s", name);
}
