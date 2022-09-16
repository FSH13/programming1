
#include <stdio.h>
#include <cs50.h>

int main(void)
{
  char Eenheid = get_char("Wat is de eenheid? ");
  while (Eenheid != 'F' && Eenheid != 'f' && Eenheid != 'C' && Eenheid != 'c')
  {Eenheid = get_char("Eenheid kan enkel F of C zijn: ");}

  int Start = get_int("Wat is de start temperatuur? ");
  int Eind = get_int("Wat is de gewenste eind temperatuur? ");
  int Interval = get_int("Wat is de stap grootte? ");
  while (Interval <= 0) { Interval = get_int("Minimale interval is 1. Nieuwe waarde: ");  }

  int TempCalc;
  int Celsius;
  int Fahrenheit;
  //while (Start <= 0) { Start = get_int("Minimale temperatuur is 1. Nieuwe waarde: ");}
  //while (Eind < Start) {Eind = get_int("Eind temperatuur dient gelijk of hoger te zijn dan de Start temperatuur: ");}

  if(Eenheid == 'F' || Eenheid == 'f')
  {
    printf("  F |   C\n");
    for (Fahrenheit = Start; Fahrenheit <= Eind; Fahrenheit+=Interval)
    {
      Celsius = (10*Fahrenheit-320)/18;
      printf("%3i | %3i\n", Fahrenheit, Celsius);
    }
  }
  else
  {
    TempCalc = (18*Start+320)/10;
    printf("  C |   F\n");
    printf("%3i | %3i\n", Start, TempCalc);
    while (Start < Eind)
    {
      Start = Start + Interval;
      TempCalc = (18*Start+320)/10;
      printf("%3i | %3i\n", Start, TempCalc);
    }
  }

}
