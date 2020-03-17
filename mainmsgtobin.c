#include<stdio.h>

#include<errno.h>

#include<stdlib.h>
/*
 * This main function converts the text file to be encrypted into its
 * 
 * binary representation and then, encrypts the binary representation
 * 
 * into the input image.
 */

int main(int argc, char *argv[]){
        
    if(argc != 4){
            
        return EINVAL;
        
    }

    char *enc = msgtobin(argv[1]);

    printf("%s\n", enc);

    enctextimg(enc, argv[2], argv[3]);

    free(enc);

    return 0;
        
}