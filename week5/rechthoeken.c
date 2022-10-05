//opvragen van de lengte rechthoek 1
// opvragen breedte rechthoek 1
// opvragen lengte rechthoek 2
// opvragen breedte rechthoek 2
// opcragen gewenste informatie: oppervlakte rechthoek 1 of 2; verschil oppervlakte rechthoeken; som oppervlakte beide rechthoeken
// invoer opties:

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calc_opp (int lengte, int breedte);

int main (void)
{
	int verschil;
	int l1 = get_int("Lengte 1: \n");
	int b1 = get_int("Breedte 1: \n");
	int l2 = get_int("Lengte 2: \n");
        int b2 = get_int("Breedte 2: \n");
	char berekening = get_char("Wil je de oppervlakte van rechthoek (1) of (2), of de (S)om of het (V)erschil weten? ");
//	if (berekening != 1 || berekening != 2 || berekening != 'S' || berekening != 'V')
//	{
//		printf("Dit is geen geldige keuze");
//		return 0;
//	}

	//berekenen oppervlakte van 1
	if (berekening == '1')
	{
		printf("Oppervlakte rechthoek 1 = %i\n", calc_opp (l1, b1));
	}

	else if (berekening == '2')
        {
                printf("Oppervlakte rechthoek 2 = %i\n", calc_opp (l2, b2));
        }
	else if (berekening == 'S')
        {
		int som = calc_opp(l1,b1) + calc_opp(l2,b2);
                printf("Som van beide opp = %i\n", som);
        }
	else if (berekening == 'V')
        {
		if (calc_opp(l1,b1) > calc_opp(l2,b2))
		{
			verschil = calc_opp(l1,b1)-calc_opp(l2,b2);
		}
		else {
			verschil = calc_opp(l2,b2)-calc_opp(l1,b1);
		}
                printf("Verschil opp rechthoeken = %i\n", verschil);
        }
	else{
		printf("Dit is geen geldige keuze");
		return 0;
	}
}

int calc_opp (int lengte, int breedte)
{
	int opp = lengte * breedte;
	return opp;
}

