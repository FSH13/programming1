#include <cs50.h>
#include <stdio.h>

int main(void) {
  char Eenheid = get_char("Wat is de eenheid? ");
  while (Eenheid != 'F' && Eenheid != 'f' && Eenheid != 'C' && Eenheid != 'c') {
    Eenheid = get_char("Eenheid kan enkel F of C zijn: ");
  }

  int Start = get_int("Wat is de start temperatuur? ");
  int Interval = get_int("Wat is de stap grootte? ");
  while (Interval <= 0) {
    Interval = get_int("Minimale interval is 1. Nieuwe waarde: ");
  }
  int Eind = get_int("Wat is de gewenste eind temperatuur? ");
  // Eenheid towupper(Eenheid);

  // while (Start <= 0) { Start = get_int("Minimale temperatuur is 1. Nieuwe
  // waarde: ");} while (Eind < Start) {Eind = get_int("Eind temperatuur dient
  // gelijk of hoger te zijn dan de Start temperatuur: ");}

  if (Eenheid == 'F' || Eenheid == 'f') {
    int TempCalc = (Start + 320) / 10;
    printf(" F  |  C \n");
    while (Start < Eind) {
      printf("%3i | %3i\n", Start, TempCalc);
      Start = Start + Interval;
      TempCalc = (Start + 320) / 10;
    }
  } else {
    int TempCalc = (Start - 320) / 18;
    printf(" C |  F \n");
    while (Start < Eind) {
      printf("%3i | %3i\n", Start, TempCalc);
      Start = Start + Interval;
      TempCalc = (Start - 320) / 18;
    }
  }
}
