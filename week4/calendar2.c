
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
#include <stdlib.h>
#include <string.h>

int DAYS = 0;
int PRINT_DAY = 1;
int COUNT_YEAR = 1797;
int DAYS_MONTH = 30;

void days_years(int year);
void days_months(int month, int year);
int leap_year(int years);
int start_day(void);
void draw_days(int row, int column);
void max_days(int month, int year);

void display_header(int month, int year);
void init_grit(void);
void draw_calendar(int value);
void display_grid(int dag);
void display_week(void);

string WEEK[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int main(int argc, string argv[]) {
  // if the user didn't provide month and year, inform them
  if (argc != 3) {
    printf("Usage: ./calendar month year\n");
    return 1;
  }
  // change the argv string to an month and year integer !!MOET HIER BIJ CIJFER
  // CHECK?!!
  int month = atoi(argv[1]);
  int year = atoi(argv[2]);
  // bereken het totaal aantal dagen van 1800 tot opgegeven datum
  days_years(year);
  days_months(month, year);
  // print de header van de kalender
  display_header(month, year);
  // bereken aantal dagen van de gekozen maand
  max_days(month, year);
  // print de kalender
  display_grid(DAYS);
}

// bereken dagen van tussenliggende jaren rekening houdend met schrikkeljaren
void days_years(int year) {
  bool leap = leap_year(COUNT_YEAR);
  for (COUNT_YEAR = 1797; COUNT_YEAR < year; COUNT_YEAR++) {
    if (leap_year(COUNT_YEAR)) {
      DAYS = DAYS + 366;
      //			printf("days: %i en jaren leapyear: %i\n", DAYS,
      //COUNT_YEAR);
    } else if (leap == false) {
      DAYS = DAYS + 365;
      //			printf("days: %i en jaren: %i\n", DAYS,
      //COUNT_YEAR);
    } else {
      printf("hoipippoloi");
    }
  }
}

// bereken het aatal dagen van de maanden tot opgegeven maand van het opgegeven
// jaar
void days_months(int month, int year) {
  for (int count_month = 0; count_month < month; count_month++) {
    if (count_month == 1 || count_month == 3 || count_month == 5 ||
        count_month == 7 || count_month == 8 || count_month == 10 ||
        count_month == 12) {
      DAYS = DAYS + 31;
    } else if (count_month == 2 || count_month == 4 || count_month == 6 ||
               count_month == 9 || count_month == 11) {
      DAYS = DAYS + 30;
    }

    if (leap_year(year) && count_month == 3) {
      DAYS = DAYS + 1;
    }
  }
}

int leap_year(int years) {
  // bereken of het huidig jaar een leap year is
  if (years % 400 == 0) {
    return true;
  } else if (years % 4 == 0 && years % 100 != 0) {
    return true;
  } else {
    return false;
  }
}

// print de kalender header
void display_header(int month, int year) {
  string months[12] = {"Jan", "Feb", "Mrt", "Apr", "May", "Jun",
                       "Jul", "Aug", "Sep", "Okt", "Nov", "Dec"};
  printf("      %s %i\n", months[month - 1], year);
  printf("---------------------------\n");
  printf("%s %s %s %s %s %s %s \n", WEEK[0], WEEK[1], WEEK[2], WEEK[3], WEEK[4],
         WEEK[5], WEEK[6]);
}

// op welke weekdag starten we de kalender
int start_day(void) {
  int dagen = DAYS;
  dagen = dagen % 7;
  //	if (dagen > 7){dagen = dagen-7;}
  //	if (dagen > 4){
  //		while (dagen > 700){
  //			dagen = dagen - 700;
  //		}
  //		while (dagen > 70){
  //			dagen = dagen - 70;
  //		}
  //		while (dagen > 7){
  //			dagen = dagen -7;
  //		}
  //	}
  //	printf("dagen %i\n", dagen);
  return dagen;
  printf("dagen: %i", dagen);
}

// bereken hoeveel dagen de gekozen maand heeft
void max_days(int month, int year) {
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
      month == 10 || month == 12) {
    DAYS_MONTH = 31;
  } else if (month == 2) {
    if (leap_year(year) == true) {
      DAYS_MONTH = 29;
    } else {
      DAYS_MONTH = 28;
    }
  }
}
void init_grit(void) {
  int row = 0;
  int column = 0;
  int day = 1;
  for (row = 0; day < DAYS_MONTH; row++) {
    for (int days = 0; days < 7; days++) {
      printf("%3d ", day);
      column++;
      day++;
    }
    column = 0;
    printf("\n");
  }
}
void display_grid(int dag) {
  int day = 1;
  for (int row = 0; day < DAYS_MONTH; row++) {
    for (int days = 0; days < 7; days++) {
      draw_calendar(day);
      day++;
    }
    printf("\n"); // printf("day: %i\n", day);
  }
}

void draw_calendar(int value) {
  if (value < start_day()) {
    printf("    ");
  } else if (PRINT_DAY <= DAYS_MONTH) {
    printf("%3d ", PRINT_DAY);
    PRINT_DAY++;
  } else {
    printf("    ");
  }
}
