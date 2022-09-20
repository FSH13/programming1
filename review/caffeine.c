#include <stdio.h>
#include <cs50.h>
#include <math.h>

// amount of caffeine in each drink
int mg_caffeine_in_espresso = 70;
int mg_caffeine_in_black_tea = 30;
int mg_caffeine_in_green_tea = 20;
int mg_caffeine_in_cocoa = 10;
int mg_caffeine_in_piece_of_chocolate = 1;

// amount of drinks you should consume to reach the desired caffeine amount that the user gives as input
int amount_of_espressos_to_drink = 0;
int amount_of_black_tea_to_drink = 0;
int amount_of_green_tea_to_drink = 0;
int amount_of_cocoa_to_drink = 0;
int amount_of_chocolate_to_eat = 0;

// given an amount of caffeine, this function returns the heighest amount of caffeine you can subtract
int get_max_subtractable_caffeine_amount(caffeine_amount) {
  if (caffeine_amount - mg_caffeine_in_espresso >= 0) {
    return mg_caffeine_in_espresso;
  } else if (caffeine_amount - mg_caffeine_in_black_tea >= 0) {
    return mg_caffeine_in_black_tea;
  } else if (caffeine_amount - mg_caffeine_in_green_tea >= 0) {
    return mg_caffeine_in_green_tea;
  } else if (caffeine_amount - mg_caffeine_in_cocoa >= 0) {
    return mg_caffeine_in_cocoa;
  } else if(caffeine_amount - mg_caffeine_in_piece_of_chocolate >= 0) {
    return mg_caffeine_in_piece_of_chocolate;
  }
  return 0;
}
  
int main () {

  // get caffeine input from user higher than 0.001 //put in main
  float input1 = get_float("Amount in grams: ");
  while (input1 < 0.001) {
    input1 = get_float("Amount in grams: ");
  }

  // convert g to mg
  int input = round (input1 * 1000);
  int max;

  while (input > 0) {
    max = get_max_subtractable_caffeine_amount(input);

    if (max == mg_caffeine_in_espresso) {
      amount_of_espressos_to_drink += 1;
    }
    else if (max == mg_caffeine_in_black_tea) {
      amount_of_black_tea_to_drink += 1;
    }
    else if (max == mg_caffeine_in_green_tea) {
      amount_of_green_tea_to_drink += 1;
    }
    else if(max == mg_caffeine_in_cocoa) {
      amount_of_cocoa_to_drink += 1;
    }
    else if(max == mg_caffeine_in_piece_of_chocolate) {
      amount_of_chocolate_to_eat += 1;
    }
    input = input - max;
  }

    
  if (amount_of_espressos_to_drink > 0) {
    printf("%i espresso\n", amount_of_espressos_to_drink);
  }
  if (amount_of_black_tea_to_drink > 0) {
    printf("%i black tea\n", amount_of_black_tea_to_drink);
  }
  if (amount_of_green_tea_to_drink > 0) {
    printf("%i green tea\n", amount_of_green_tea_to_drink);
  }
  if (amount_of_cocoa_to_drink > 0) {
    printf("%i cocoa\n", amount_of_cocoa_to_drink);
  }
  if (amount_of_chocolate_to_eat > 0) {
    printf("%i chocolate\n", amount_of_chocolate_to_eat);
  }

  int drinks_total =  amount_of_espressos_to_drink +amount_of_black_tea_to_drink + amount_of_green_tea_to_drink + amount_of_cocoa_to_drink + amount_of_chocolate_to_eat;
  if(drinks_total == 1) {
    printf("That makes %i drink in total\n", drinks_total);
  }
  else {
    printf("That makes %i drinks in total\n", drinks_total);
  }
  return 0; 
}
  
