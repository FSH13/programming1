#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int mm = 0, days = 0, gemiddeld;
  float totaal_mm = 0, gem = 0;

  while (mm != 999) {
    mm = get_int("milimeter regen vandaag: ");
    totaal_mm = totaal_mm + mm;
    days = days + 1;
    printf("dagen: %d mm totaal: %f\n", days, totaal_mm);
  }

  gem = (totaal_mm - 999) / days;
  gemiddeld = round(gem);
  printf("Gemiddeld %d millimeter/n", gemiddeld);
  return 0;
}
