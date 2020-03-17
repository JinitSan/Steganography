#include<stdio.h>

#include<errno.h>

#include<stdint.h>

#include<string.h>

#include<stdlib.h>
/*
 * This function converts the data contained in the image into
 * 
 * its binary representation.
 * 
 */

char *dectobin(uint8_t a);

char *imgtobin(char *fname){
    
    FILE *fp;

    fp = fopen(fname, "rb");

    if(fp == NULL){
        
        printf("Can't open file\n");

        return EINVAL;
    
    }

    uint8_t pix;

    char *rets = (char *)malloc(sizeof(char) * 2359296);

    if(rets == NULL){
        
        printf("Can't allocate memory\n");

        return EINVAL;
    
    }

    int counter = 0;

    strcpy(rets, "");

    int j = 0;
    
    int i;

    char *bin;

    while(!feof(fp) && counter!=2359296){

        fread(&pix, 1, 1, fp);

        bin = dectobin(pix);

        for(i = 0; i < 8; i++){

            rets[counter++] = bin[i];

        }

        free(bin);

    }

    fclose(fp);

    return rets;

}

char *dectobin(uint8_t a){
    
    char *str = (char *)malloc(sizeof(char) * 8);
    
    int i = 7;
    
    int j;
    
    for(j = 0; j < 8; j++){
    
        str[j] = '0';
    
    }
    
    while(a > 0){
    
        if(a % 2 == 1){
    
            str[i--] = '1';
    
        }
    
        else{
    
            str[i--] = '0';
    
        }
    
        a = a/2;
    
    }
    
    return str;

}
