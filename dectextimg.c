/*
 * This function takes an encrypted image, and retrieves the text in the binary 
 * 
 * format, i.e, the format it was encoded in. In order to know the length of the 
 * 
 * encoded text, in the "enctextimg" function, we added the length of the string 
 * 
 * in the header file of the encrypted image.
 * 
 * Thus, we shall find the length of the encoded data and iterate through the pixels
 * 
 * to find the binary representation of the text.
 * 
 */
#include<stdio.h>

#include "bmp.h"

#include<stdint.h>

#include<errno.h>

#include<string.h>

#include<stdlib.h>

char *dectextimg(char *fname){

    FILE *fp;

    fp = fopen(fname, "rb");

    if(fp == NULL){

        printf("Can't open file\n");

        return EINVAL;
    
    }

    char *decs = (char *)malloc(sizeof(char) * 2359296);

    uint8_t pix;

    int len;

    BMPImage bmp;

    fread(&bmp.header, 54, 1, fp);

    len  = bmp.header.num_colors;

    printf("Length is %d\n", len);

    int i = 0;

    while(i < len){

        fread(&pix, 1, 1, fp);

        if(pix % 2 == 1){

            decs[i++] = '1';
        
        }

        else{

            decs[i++] = '0';
        
        }
    
    }

    return decs;

}