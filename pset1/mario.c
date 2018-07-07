#include <stdio.h>
#include <cs50.h>

int main(void)
{
   int n;
   do{
       printf("Height: ");
       n = get_int();
   }while (n < 0 || n > 23);
   
   for (int i = 1; i <= n; i++){
        for (int j = 0; j < n+1; j++){
            if(j < n-i)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
   
}