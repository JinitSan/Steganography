/*
 * This is the final step, this module takes the binary string as input, and
 * 
 * writes the decoded text to a file.
 * 
 */

#include<stdio.h>

#include<errno.h>

#include<stdint.h>

#include<string.h>

#include<stdlib.h>

#include<math.h>
/*
 * This function converts the binary representation of the encrypted text
 * 
 * file into text.
 * 
 */

void bintomsg(char *s, char *fname){

    FILE *fp;

    fp = fopen(fname, "w+");

    if(fp == NULL){

        printf("Can't open file\n");

        return EINVAL;
            
    }

    int i = 0;

    int j = 0;

    char bin[8];

    printf("%s\n", s);

    int num = 0;

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

        ch = (char)num;

        fwrite(&ch, 1, 1, fp);

        i = 0;

        num = 0;

    }

    fclose(fp);

}