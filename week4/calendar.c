*****************************************
/* Program to print a requested calendar.
*  By: FSH
*  variables used:
*  strings: months
*  int: date, month, year
*  int functions: first_day_years, first_day_month, days_month, leap_year, 
*                 display_header, display_grid
*/
*****************************************

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int days_years(int year);
int days_months(int month, int year);
int leap_year(int year);

int display_header(int month, int year);
int display_grid(int month, int year);

int DAYS = 0;
int COUNT_YEAR = 1800;

int main (int argc, string argv[])
{

	// if the user didn't provide month and year, inform them
	if (argc !=3)
	{
		printf("Usage: ./calendar month year");
		return 1;
	}
	// change the argv string to an month and year integer !!MOET HIER BIJ CIJFER CHECK?!!
	int month = atoi(argv[1]);
	int year = atoi(argv[2]);

//Tel aantal jaren tussen 1800 en year
//bereken hoeveel schrikkeljaren er tussen 1800 en year zitten. tel voor elk jaar er 1 bij de dagen tenzij huidige maand <2
// komt voor als het jaartal restloos deelbaar is door 4, maar niet door 100 – tenzij het jaartal restloos deelbaar door 400

}

// bereken dagen van tussenliggende jaren rekening houdend met schrikkeljaren
// kan hier ook gebruik maken van leap_year ipv de twee if's
int days_years(int year)
{
	for (COUNT_YEAR = 1800; COUNT_YEAR < year; COUNT_YEAR++)
	{
		if (COUNT_YEAR%4 == 0 && COUNT_YEAR%100 != 0)
		{
			if (COUNT_YEAR%400 == 0)
			{
				DAYS = DAYS + 366;
			}
			else
			{
                        	DAYS = DAYS + 365;
	                }
		}
		else
		{
			DAYS = DAYS + 365;
		}
	}
}

int days_months(int month, int year)
{
	for (int count_month = 0; count_month <= month; count_month++)
	{
		if(count_month == 1 || count_month == 3 || count_month == 5 || count_month == 7 || count_month == 8 || count_month == 10 || count_month == 12)
		{
			DAYS = DAYS + 31;
		}
		else if (count_month == 2 || count_month == 4 || count_month == 6 || count_month == 9 || count_month == 11)
		{
			DAYS = DAYS + 30;
		}

		if (leap_year == 1 && month >= 2)
		{
			DAYS = DAYS + 1;
		}
	}
	printf("$i\n", DAYS);
}

int leap_year(int year)
{
	//is huidig jaar een leap year en >= 2month
	if (COUNT_YEAR%4 == 0 && COUNT_YEAR%100 != 0)
        {
                if (COUNT_YEAR%400 == 0)
                {
			return 1;
		}
	}
}

//int display_header(int month, int year)
//{
//	
//}

int display_grid(int month, int year)
{
	string months[] = {"Jan,Feb,Mrt,Apr,May,Jun,Jul,Aug,Sep,Okt,Nov,Dec"};
	printf("      %s %i\n", months[month], year);
}

