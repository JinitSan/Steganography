#include<stdio.h>
#include "bmp.h"
#include<stdint.h>
#include<errno.h>
int main(int argc, char *argv[]){
    FILE *fp;
    if(argc != 2){
            printf("Incorrect Input\n");
    }
    fp = fopen(argv[1], "rb");
    uint8_t pix;
    int c = 0;
    while(!feof(fp)){
        fread(&pix, 1, 1, fp);
        c++;
    }
    printf("%d\n", c);
    fclose(fp);
    return 0;
}