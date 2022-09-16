
#include <stdio.h>
#include <cs50.h>

int main(void)
{
  int Height, CountH, CountW, Width, Left;
  Height = get_int("Hoe hoog wordt de pyramide? ");
  while (Height < 1 || Height > 8 ){Height = get_int("Kies een hoogte tussen 1 en 8: ");}

  for (CountH = 0;CountH < Height ; CountH++)
  {
    Left = Height-CountH; 

    for (CountW = 1; CountW < Left; CountW++)
    {
	printf(" ");
    }
    for (CountW = 0; CountW <= CountH; CountW++)
    {
	printf("#");
    }
    printf("\n");
  }

}
