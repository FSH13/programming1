#include <stdio.h>
#include <cs50.h>
int main(void)
{
  int start = get_int("Hoeveel lama's zijn er nu? ");
  int eind = get_int("Hoeveel lama's wil je totaal? ");

  while (start < 9) {start = get_int("Minimum is 9 lama's. Nieuw aantal: ");}
  while (eind <= start) {eind = get_int("Het gewenste aantal lama's dient groter te zijn dan huidig. Nieuw gewenst totaal: ");}

  int huidig = start;
  int jaren = 0;
  while (huidig < eind)
  {
    huidig = huidig + (huidig/3) - (huidig/4);
    jaren = jaren + 1;
  }
  printf("start: %i\n", start);
  printf("eind: %i\n", eind);
  printf("huidig: %i\n", huidig);
  printf("jaren: %i\n", jaren);
}
