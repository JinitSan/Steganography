#include<stdio.h>

#include<errno.h>

#include<stdlib.h>
/*
 * This is the main function that decrypts image files into text files.
 * 
 * First, the binary representation of the text is recovered from these
 * 
 * image files.
 * 
 * After that, this binary representation is converted into text format
 * 
 * and the text is written to a new file.
 * 
 */

int main(int argc, char *argv[]){
        
    if(argc != 3){
            
        printf("In here\n");

        return EINVAL;
        
    }

    char *dec = dectextimg(argv[1]);

    bintomsg(dec, argv[2]);

    free(dec);

    return 0;
        
}