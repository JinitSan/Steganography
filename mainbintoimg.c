#include<stdio.h>

#include<errno.h>

#include<stdlib.h>
/*
 * This is the main function that decrypts the hidden data in the image.
 * 
 * First, it retrieves the binary representation of the data encrypted 
 * 
 * in the image. It then converts the binary representation into data
 *  
 * and writes it to a file.
 */

int main(int argc, char *argv[]){
        
    if(argc != 3){
            
        printf("In here\n");

        return EINVAL;
        
    }

    char *dec = dectextimg(argv[1]);

    bintoimg(dec, argv[2]);

    free(dec);

    return 0;
        
}