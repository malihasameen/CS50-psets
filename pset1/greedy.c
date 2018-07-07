#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float n;
    int coins = 0;
    printf("O hai! ");
    do{
        printf("How much change is owed?\n");
        n = get_float();
    }while (n < 0);
    
    n = (int)round(n * 100);
    
    int quarters = 25;
    int dimes = 10;
    int nickles = 5;
    int pennies = 1;
    
    while (n >= quarters){
        n = n - quarters;
        coins++;
    }
    while (n >= dimes){
        n = n - dimes;
        coins++;
    }
    while (n >= nickles){
        n = n - nickles;
        coins++;
    }
    while (n >= pennies){
        n = n - pennies;
        coins++;
    }
    printf("%i\n",coins);
}