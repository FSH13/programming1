
#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void) {
  // espresso = 70mg
  // black tea = 30mg
  // green team = 20mg
  // cocoa = 10mg
  // stuk choco = 1mg;

  string drankje = "";
  int waarden[5] = {70, 30, 20, 10, 1};
  string drankjes[5] = {"espresso", "black tea", "green tea", "cocoa",
                        "piece of chocolate"};

  // een lijst die bijhoudt hoeveel van elk drankje je al hebt genomen
  int hoeveelheid[5] = {0, 0, 0, 0, 0};
  float intake =
      get_float("Minimaal noodzakelijke hoeveelheid caffeine vandaag: ");

  // we veranderen de gram input naar milligrammen
  int milligram = round(intake * 1000);

  int aantal = 0;
  int totaal = aantal;
  int count = 0;

  while (intake <= 0.001) {
    intake = get_float("Met zo weinig kom je nooit je nest uit. More please: ");
  }

  // we willen dat het programma stopt zodra je al je milligram hebt gedronken
  while (milligram > 0) {
    while (milligram >= waarden[count]) {
      hoeveelheid[count]++;
      milligram = milligram - waarden[count];
    }
    printf("%i, %s \n", hoeveelheid[count], drankjes[count]);
    count++;
  }
}
