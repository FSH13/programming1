
#include <stdio.h>
#include <cs50.h>

int main(void)
{
  //all soda = 50ct
  //mogelijke munten: 25ct, 10ct, 5ct 
  int price, coin, paid, owed, change;

  price = 50;
//  printf("50 cents owed \n");
//  printf("50 cents owed \n");
 // coin = get_int("Insert coins: ");
 // if (coin != 25 && coin != 10 && coin != 5) {coin = 0;}
  coin = 0;
  paid = coin;
  change = paid-price;
  owed = price-paid; 

  for (owed = price-paid; paid<price; paid=paid+coin)
  {
    owed = price-paid;
    printf("%i cents owed: \n", owed);
    coin = get_int("Insert coin: "); 
    while (coin != 25 && coin != 10 && coin != 5)
    {
      coin = get_int("%i cents owed: ", owed);
    }
  }
/*  while (paid < price) 
  {
    coin = get_int("%i cents owed: ", owed); 
    if (coin != 25 && coin != 10 && coin != 5) {coin = get_int("Insert valid coins: ");}
    owed = price - paid;
    paid = paid+coin;
  }*/

  change = paid - price;
  printf("%i cents change \n", change);
}
