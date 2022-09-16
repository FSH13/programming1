#include <stdio.h>
#include <cs50.h>
#include <wctype.h>

int main(void)
{
  string Eenheid = get_string("Wat is de eenheid? ");
  int Start = get_int("Wat is de start temperatuur? ");
  int Interval = get_int("Wat is de stap grootte? ");
  int Eind = get_int("Wat is de gewenste eind temperatuur? ");
  //Eenheid towupper(Eenheid);

  if (Eenheid == "F" || Eenheid == "f" || Eenheid == "C" || Eenheid == "c")
  {
    Eenheid = Eenheid;
  }
  else {Eenheid = get_string("Eenheid kan enkel F of C zijn: ");}

  while (Start <= 0) { Start = get_int("Minimale temperatuur is 1. Nieuwe waarde: ");}
  while (Interval <= 0) { Interval = get_int("Minimale interval is 1. Nieuwe waarde: ");  }
  while (Eind < Start) {Eind = get_int("Eind temperatuur dient gelijk of hoger te zijn dan de Start temperatuur: ");}

  if(Eenheid = "F" || Eenheid = "f")
  {
    int TempCalc = (Start+320)/10;
    printf(" F  |  C ");
    while (Start < Eind)
    {
      printf("%3d","%3d", Start, TempCalc);
      Start = Start + Interval;
      TempCalc = (Start+320)/10;
    }
  }
  else
  {
    int TempCalc = (Start-320)/18;
    printf(" C %c", " F %c ");
    while (Start < Eind)
    {
      printf("%3d","%3d", Start, TempCalc);
      Start = Start + Interval;
      TempCalc = (Start-320)/18;
    }
  }

}
