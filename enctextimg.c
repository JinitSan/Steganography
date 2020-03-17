/* This module takes text(converted into its binary representation), and
 * 
 * a BMP image, and encrypts the text data into the image using the 
 * 
 * LSB algorithm.
 * 
 * LSB stands for Least Bit algorithm and since we will be altering the 
 * 
 * least significant bit of the pixels contained in these images, the 
 * 
 * change in appearance of the image would be unnoticeable to the human
 * 
 * eye, making it an efficient technique to encrypt data.
 * 
 * Note, the user should be careful that the number of characters present
 *
 * in the text data should not exceed the number of pixel bits in the
 * 
 * input BMP image. 
 */
#include<stdio.h>

#include "bmp.h"

#include<stdint.h>

#include<errno.h>

#include<string.h>

void enctextimg(char *s, char *file1, char *file2){

    FILE *fp;

    FILE *fd;

    int width;

    int height;

    uint8_t pix;

    fp = fopen(file1, "rb");

    fd = fopen(file2, "w+");

    if(fp == NULL){

            printf("Can't open file\n");

            return EINVAL;
    
    }
    BMPImage bmp;

    fseek(fp, 0x12, SEEK_SET);

	fread(&width, sizeof(int), 1, fp);
	
    fread(&height, sizeof(int), 1, fp);	
    
    fseek(fp, 0L, SEEK_SET);
    
    fread(&(bmp.header), 0x36, 1, fp);

    bmp.header.num_colors = strlen(s);

    printf("Length is %d\n", bmp.header.num_colors);
    
    fwrite(&(bmp.header), 0x36, 1, fd);
    /*
     * From the original image, we have read the header file or the header structure and
     * 
     * written it to a new file, which will be the image with the encrypted text.
     * 
     * We can do so because the information contained by the header file will not change
     * 
     * as the format and dimensions of the steganographic image will be similar to that of
     * 
     * the input image.
     */
    printf("The width and the height of the input BMP image: %dX%d\n", width, height);

    int counter = 0;

    while(!feof(fp) && counter < strlen(s)){

        fread(&pix, 1, 1, fp);

        if((pix % 2 == 1) && s[counter] == '1' ){
                    
            fwrite(&pix, 1, 1, fd);

            counter++;
                    
            continue;
            
        }

        else if((pix % 2 == 0) && s[counter] == '1' ){
                    
            pix = pix + 1;

            fwrite(&pix, 1, 1, fd);

            counter++;
                                
            continue;
            
        }

        else if((pix % 2 == 1) && s[counter] == '0' ){
                    
            pix = pix + 1;

            fwrite(&pix, 1, 1, fd);

            counter++;
                    
            continue;
            
        }

        else if((pix % 2 == 0) && s[counter] == '0' ){
                    
            fwrite(&pix, 1, 1, fd);

            counter++;
                    
            continue;
            
        }
    
    }
    /*
     * What the above loop does is that reads individual characters from the binary representation of the text to be 
     * 
     * encrypted and conceals these characters in the b,g,r values of the pixels.
     * 
     * The logic we are using here revolves around the fact that if a pixel value is even, its LSB will be 0 and
     * 
     * if the pixel value is odd, its LSB will be 1. 
     * 
     * Thus, if the character read from the string is 1, we change the corresponding pixel into an odd number by adding
     * 
     * 1 to it if it is an even number, and if it is an odd number, we continue.
     * 
     * We do the vice-versa if the character read is 0.
     * 
     */

    if(counter != strlen(s)){
            
        printf("Image cannot accomodate the text to be encrypted, reduce the number of characters to be encrypted or increase image size\n");

        return EINVAL;
    
    }

    else if(!feof(fp) && counter == strlen(s)){

        while(!feof(fp)){
        
            fread(&pix, 1, 1, fp);

            fwrite(&pix, 1, 1, fd);

        }
    }

    fclose(fd);

    fclose(fp);

}