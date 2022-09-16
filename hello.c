#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string ("Wat is je naam? ");
    printf("hello, %s", name);
}
