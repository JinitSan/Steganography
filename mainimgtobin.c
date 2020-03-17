#include<stdio.h>

#include<errno.h>

#include<stdlib.h>
/*
 * This is the main function that encrypts data into the image.
 * 
 * First, it converts the data to be encrypted into its binary
 * 
 * representation and then encrypts this binary representation into
 * 
 * the input image.
 */

int main(int argc, char *argv[]){
        
    if(argc != 4){
            
        return EINVAL;
        
    }

    char *enc = imgtobin(argv[1]);

    enctextimg(enc, argv[2], argv[3]);

    free(enc);

    return 0;
        
}