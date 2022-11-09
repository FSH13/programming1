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

void main (void)
{
    int height = get_int("provide triangle hight: ");
    char *s = get_string("provide something: ");
//    if (argc < 2){
//        height = get_int("provide triangle hight: ");
//    }
//    else {
//        height = argv[1];
//    }

    //loop overeach row to determine where the # needs to be on that row
    for (int row = 0; row < height; row++){
        for (int column = 0; column < height - 1; column++){
            printf(" ");
        }
        printf("#");
    }
//    void print(height);
}

/*void print (int height)
{
    int base = height * 2;
    for (int row = 0; row < height; row++){
        for (int column = 0; column < height - 1; column++){
            printf(" ");
        }
        printf("#");
    }
}*/
