#include <math.h>
#include <stdio.h>
#include <cs50.h>

int main(void)
{
// espresso = 70mg
// black tea = 30mg
// green tea = 20mg
// cocoa = 10mg
// stuk choco = 1mg

float intake = get_float("Minimaal noodzakelijke hoeveelheid caffeine vandaag: ");

int milligram = round(intake * 1000);
int aantal = 0; //kopjes per drankje
int totaal = 0; //kopjes totaal

//Indien minder dan 0.001 ingevoerd, vraag intake opnieuw.
while (intake <= 0.001)
{
	intake = get_float("Met zo weinig kom je nooit je nest uit. More please: "); 
	milligram = round(intake * 1000);
}

//bepaal of er nog een kopje gedronken kan worden per type en print het aantal en type
//espresso
while (milligram >= 70)
{
	aantal++;
	milligram = milligram - 70;
	printf("%i, %s\n", aantal, " espresso");
}
totaal = totaal + aantal;
aantal = 0;

//Black tea
while (milligram >= 30)
{
	aantal++;
	milligram = milligram - 30;
	printf("%i, %s\n", aantal, " black tea");
}
totaal = totaal+aantal;
aantal = 0;

//Green tea
while (milligram >= 20) 
{
	aantal++;
	milligram = milligram - 20;
	printf("%i, %s\n", aantal, " green tea");
}
totaal = totaal + aantal;
aantal = 0;

//cocoa
while (milligram >= 10)
{
	aantal++;
	milligram = milligram - 10;
	printf("%i, %s\n", aantal, " cocoa");
}
totaal = totaal + aantal;
aantal = 0;

//Choolade
while (milligram >= 1)
{
	aantal++;
	milligram = milligram - 1;
	printf("%i, %s\n", aantal, " chocolate");
}
aantal = 0; //hier wordt het totaal niet meegenomen omdat het geen drankje is

//print het totaal aantal drankjes
if (totaal == 1) {printf("That makes 1 drink in total\n");}
else {printf("That makes %i drinks in total\n", totaal);}

}
