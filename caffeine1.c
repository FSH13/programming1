
#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void) {
  // espresso = 70mg
  // black tea = 30mg
  // green team = 20mg
  // cocoa = 10mg
  // stuk choco = 1mg;

  float intake =
      get_float("Minimaal noodzakelijke hoeveelheid caffeine vandaag: ");

  int milligram = round(intake * 1000);
  int aantal = 0;
  int totaal = 0;
  int count = 0;

  while (intake <= 0.001) {
    intake = get_float("Met zo weinig kom je nooit je nest uit. More please: ");
    milligram = round(intake * 1000);
  }

  while (milligram >= 70) {
    aantal++;
    milligram = milligram - 70;
  }
  totaal = totaal + aantal;
  printf("%i, %s\n", aantal, " espresso");
  aantal = 0;
  count = count + aantal;

  while (milligram >= 30) {
    aantal++;
    milligram = milligram - 30;
  }
  totaal = totaal + aantal;
  printf("%i, %s\n", aantal, " black tea");
  aantal = 0;
  count = count + aantal;

  while (milligram >= 20) {
    aantal++;
    milligram = milligram - 20;
  }
  totaal = totaal + aantal;
  printf("%i, %s\n", aantal, " green tea");
  aantal = 0;
  count = count + aantal;

  while (milligram >= 10) {
    aantal++;
    milligram = milligram - 10;
  }
  totaal = totaal + aantal;
  printf("%i, %s\n", aantal, " cocoa");
  aantal = 0;
  count = count + aantal;

  /* while (milligram >=1)
   {
    aantal++;
    milligram = milligram-1;
   }
    totaal = totaal+aantal;
    printf("%i, %s\n", aantal, " black tea");
    aantal = 0; count = count+aantal;
  */

  if (count == 1) {
    printf("That makes 1 drink in total");
  }

  else {
    printf("That makes %i drinks in total\n", totaal);
  }
}
