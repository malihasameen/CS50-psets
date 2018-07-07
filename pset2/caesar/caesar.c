 /**
  * Caesar is a popular Encryption Algorithm that uses a key
  * to cipher the message 
  */
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //ensure proper usage
    if (argc != 2){
        printf("Usage: %s <key>\n",argv[0]);
        return 1;
    }
    
    //key to cipher message
    int k = atoi(argv[1]);
    string p;
    
    //input message
    printf("plaintext: ");
    p = get_string();
    
    printf("ciphertext: ");
    for (int i = 0, n = strlen(p); i < n ; i++){
        //ciphering message
        if(isupper(p[i]))
            printf("%c",((p[i] -'A' + k) % 26) + 'A');
        else if (islower(p[i]))
            printf("%c",((p[i] -'a' + k) % 26) + 'a');
        else
            printf("%c",p[i]);
    }
    printf("\n");
    return 0;
}