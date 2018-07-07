#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //get string from user
    string s = get_string();
    //check if user returned a string
    if (s != NULL){
        //print first character of string
        printf("%c",toupper(s[0]));
        //iterating over string
        for (int i = 1, n = strlen(s); i < n; i++){
            //print initials of every word in a string
            if (s[i] == ' '){
                printf("%c",toupper(s[i+1]));
            }
        }
        printf("\n");
    }
}