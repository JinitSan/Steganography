#include<stdio.h>

#include<errno.h>

#include<stdint.h>

#include<string.h>

#include<stdlib.h>

#include<math.h>
/*
 * This function converts the binary representation of the image
 * 
 * into the image data and then writes it to a file.
 */

void bintoimg(char *s, char *fname){

    FILE *fp;

    fp = fopen(fname, "w+b");

    if(fp == NULL){

        printf("Can't open file\n");

        return EINVAL;
            
    }

    int i = 0;

    int j = 0;

    char bin[8];

    uint8_t num = 0;

    char ch;

    while(j < strlen(s)){

        while(i < 8){

            bin[i++] = s[j++];
        
        }

        i = 7;

        while(i >= 0){

            if(bin[i] == '1'){

                num += pow(2,7-i);

                i--;
            
            }

            else{

                i--;
            
            }

        }

        fwrite(&num, 1, 1, fp);

        i = 0;

        num = 0;

    }

    fclose(fp);

}