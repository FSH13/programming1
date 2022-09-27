
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main (void)
{
        int mm = 0, days = 0, gemiddeld;
        float totaal_mm = 0, gem = 0;

        while (mm != 999)
        {
                mm = get_int("milimeter regen vandaag: ");
                totaal_mm = totaal_mm + mm;
                days = days + 1;
                printf("dagen: %d mm totaal: %f\n", days, totaal_mm);
        }

	if( totaal_mm <= 999)
	{printf("Dat kan niet");}
	else {
	        gem = (totaal_mm-999)/(days-1);
	        gemiddeld = round(gem);
	        printf("Gemiddeld %d millimeter/n", gemiddeld);
	}
}
