/*
 * Function to convert a text file containing a message to be encrypted
 * 
 * into its binary representation
 * 
 */
#include<stdio.h>

#include<errno.h>

#include<stdint.h>

#include<string.h>

#include<stdlib.h>

char  *msgtobin(char *fname){

    FILE *fp;

    fp = fopen(fname, "r");

    if(fp == NULL){
        
        printf("Can't open file\n");

        return EINVAL;
    
    }
    
    char ch;

    int num;

    char *rets = (char *)malloc(sizeof(char) * 2359296);

    if(rets == NULL){
        
        printf("Can't allocate memory\n");

        return EINVAL;
    
    }

    int counter = 0;

    strcpy(rets, "");

    int j = 0;
    
    int i;

    char bin[8];
    /* Procedure followed by the following loop:
     * 
     * 1)Checks if the file has reached its end.
     * 
     * 2)Initializes string "bin"
     * 
     * 3)Reads a character from the loop
     * 
     * 4)Converts the ascii value of the character in its binary form and stores it in "bin"
     * 
     * 5)Pads "bin" if necessary to convert into an 8 bit binary number
     * 
     * 6)Concatenates "bin" to the main string, "rets"
     * 
     */

    while(!feof(fp)){
            
        for(j = 0; j < 8; j++){

            bin[j] = ' ';
        
        }

        fread(&ch, 1, 1, fp);

        num = (int)ch;

        itoa(num, bin, 2);

        int len = strlen(bin);

        while(len != 8){

            for(i = len; i > 0; i--){
                
                bin[i] = bin[i - 1];
            
            }
            
            bin[0] = '0';

            len++;
        
        }

        for(i = 0; i < 8; i++){

                rets[counter++] = bin[i];

        }

    }

    fclose(fp);

    return rets;

}

