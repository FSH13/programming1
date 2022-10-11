//*****************************************
/* Program to print a requested calendar.
*  By: FSH
*  variables used:
*  strings: months
*  int: date, month, year
*  int functions: first_day_years, first_day_month, days_month, leap_year,
*                 display_header, display_grid
* unable to find why the start date doesnt work
*/
//*****************************************

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int DAYS = 0;
int PRINT_DAY = 1;
int COUNT_YEAR = 1800;
int DAYS_MONTH = 30;
int MONTH;
int YEAR;

void days_years(int year);
void days_months(int month, int year);
bool leap_year(int years);
int start_day(void);
void max_days(int month, int year);

void display_header(int month, int year);
void display_grid(int dag);


string WEEK[7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

int main (int argc, string argv[])
{
	// if the user didn't provide month and year, inform them
	if (argc != 3){
		printf("Usage: ./calendar year month\n");
		return 1;
	}
	// change the argv string to an month and year integer !!MOET HIER BIJ CIJFER CHECK?!!
        MONTH = atoi(argv[2]);
        YEAR = atoi(argv[1]);


	//calculate the total days starting from 1800 till year/month provided
	days_years(YEAR);
	days_months(MONTH, YEAR);

	//print the calendar header
	display_header(MONTH, YEAR);

	//calculate the total days of the provided month
	max_days(MONTH, YEAR);

	// print the calendar
	display_grid(DAYS_MONTH);
}

// calculate the total days of the years between 1800 and year provided also counting leap years
void days_years(int year)
{
	for (COUNT_YEAR = 1800; COUNT_YEAR < year; COUNT_YEAR++){
		bool leap = leap_year(COUNT_YEAR);
		if(leap_year(COUNT_YEAR)){
			DAYS = DAYS + 366;
		}
		else{
			DAYS = DAYS + 365;
		}
	}
}

// calculate the dats of the months of the provided year also counting leap years
void days_months(int month, int year)
{
	for (int count_month = 0; count_month < month; count_month++){
		if (count_month == 1 || count_month == 3 || count_month == 5 || count_month == 7 || count_month == 8 || count_month == 10 || count_month == 12){
			DAYS = DAYS + 31;
		}
		else if (count_month == 4 || count_month == 6 || count_month == 9 || count_month == 11){
			DAYS = DAYS + 30;
		}

		if (count_month == 2){
			DAYS = DAYS + 28;
		}

		if (leap_year(year) && count_month == 2 ){
			DAYS = DAYS + 1;
		}
	}
}

bool leap_year(int years)
{
	//calculate if the current year is a leap year
	if (years%400 == 0){
		return true;
	}
	else if (years%4 == 0 && years%100 != 0){
		return true;
	}
	else{
	return false;
	}
}

// print the kalender header
void display_header(int month, int year)
{
        string months[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Okt","Nov","Dec"};
        printf("      %s %i\n", months[month-1], year);
	printf("---------------------------\n");
        printf("%s %s %s %s %s %s %s \n", WEEK[0], WEEK[1], WEEK[2], WEEK[3], WEEK[4], WEEK[5], WEEK[6]);
}

// on which day will the month start
int start_day(void)
{
	int dagen = DAYS;
        dagen = (dagen + 3) % 7;

	return dagen;
}

// calculate the days in the month provided also considering leap years
void max_days(int month, int year)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
		DAYS_MONTH = 31;
	}
	else if (month == 2){
		if (leap_year(year) == true){
			DAYS_MONTH = 29;
		}
		else {
			DAYS_MONTH = 28;
		}
	}
}

// print the calendar
void display_grid(int dag)
{
	int start_dag = start_day();
	int total_count_fields = 1;
	for (int row = 0; PRINT_DAY <= DAYS_MONTH; row++){
		for (int columns = 0; columns < 7; columns++){
			if (total_count_fields <= start_dag){
				printf("    ");
				total_count_fields++;
			}
			else if (PRINT_DAY <= DAYS_MONTH){
				printf("%3d ", PRINT_DAY);
	                        total_count_fields++;
				PRINT_DAY++;
			}
		}
		printf("\n");
	}
}
