
/******************************
 * Fleur
 * Driehoek
*****************************/
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//void print (int height);
void blanks (int height, int row);
void btween (int height, int row);

int main (void)
{
    int height = get_int("provide triangle hight: ");
    int tussen = 0;
    int blank = height - 1;
    int count = 0;
    //loop overeach row to determine where the # needs to be on that row
    for (int row = 0; row < height - 1; row++){
        blanks (height, row);
        printf("\n");
    }

    for (int base = height * 2; base > 0; base--){
        printf("#");
    }
    printf("\n");
}

// bereken tussen
void btween (int height, int row){
    int base = height * 2;
    int tussen = row * 2;
    int count = tussen;
    while (tussen <= base - 4 && count > 0){
        printf(" ");
        count--;
    }
    printf("#");
}

// bereken leading zero's
void blanks (int height, int row){
    int blanco = height - row;
    int count = 1;

    while (count < blanco){
        printf(" ");
        count++;
    }
    printf("#");

    btween(height, row);
}

