/**
 * Vigenere is also an Encryption Algorithm using key 
 * to cipher message
 */
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void cipherMessage(string p,string k);//function defined below main

int main(int argc, string argv[])
{
    //ensure proper usage
    if (argc != 2){
        printf("Usage: %s <key>\n",argv[0]);
        return 1;
    } 
    
    string p;
    string k = argv[1];
    int nk = strlen(k);
    //iterates over key
    for (int i = 0; i < nk; i++){
        //if key contains only alphabets
        if (!isalpha(k[i])){
            printf("Usage: %s <key>\n",argv[0]);
            return 2;
        }
    }
    //get user input
    printf("plaintext: ");
    p = get_string();
    
    //display ciphertext
    printf("ciphertext: ");
    cipherMessage(p,k);
    return 0;
}
void cipherMessage(string p,string k){
    
    int nk = strlen(k);
    //iterates over the plain text
    for (int i = 0,j = 0, np = strlen(p); i < np ; i++){
        
        if(isupper(p[i])){
            printf("%c",((p[i] -'A' + (toupper(k[j]) - 'A')) % 26) + 'A');
            //cycling around the key
            j = (j + 1) % nk;
        }
        else if (islower(p[i])){
            printf("%c",((p[i] -'a' + (tolower(k[j]) - 'a')) % 26) + 'a');
            //cycling around the key
            j = (j +1) % nk;
        }
        else//words other than alphabets remain unchanged
            printf("%c",p[i]);
    }
    printf("\n");
}