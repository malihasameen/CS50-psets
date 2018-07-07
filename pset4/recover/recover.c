/**
 * Recovers all the photos from memory card
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]){
    
    //proper usage
    if (argc != 2){
        fprintf(stderr,"Usage: ./recover image\n");
        return 1;
    }
    
    //open card
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL){
        fprintf(stderr,"Couldn't open memory card");
        return 2;
    }
    
    int jpeg_count = 0;
    int open = 0;
    
    uint8_t buffer[512];
    FILE *img = NULL;
    char filename[8];
    
    while (fread(buffer, 512, 1, inptr) > 0){ //read until end of file
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            ((buffer[3] & 0xf0) == 0xe0)){ //starting of jpeg
                if(img != NULL){ //file already opened
                    fclose(img); //close file
                }
                
                sprintf(filename,"%03i.jpg",jpeg_count);//assigning filenames
                jpeg_count++;
                img = fopen(filename, "w");//open a new file
                open = 1;
            }
            
        if(open == 1) //jpeg started
            fwrite(buffer, 512, 1, img);
            
    }//end while
    
    fclose(img);//close any remaining files
    
    return 0;
}









