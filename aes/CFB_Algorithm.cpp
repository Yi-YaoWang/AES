#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include "Header.h"

void CFB_Algorithm(unsigned char*text,unsigned char*key,unsigned char (*block)[16],int textlength,bool en_decrypt){
    unsigned char IV[16]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10,0x11,0x12,0x13,0x14,0x15};
    unsigned char temp[16];
    unsigned char chipertext[textlength/16][16];
    //divide plain text
    for(int i=0;i<textlength/16;i++){
        for(int j=0;j<16;j++){
            block[i][j]=text[j+i*16];
        }
    }
    //store initial vector to temp
    for(int i=0;i<16;i++){
        temp[i]=IV[i];
    }
    //cfb encryption
    if(en_decrypt==0){
    for(int i=0;i<textlength/16;i++){
        if(i==0){
            Encryption(temp, key);
            AddRoundKey(*(block+i),temp);
            for(int j=0;j<16;j++){
                chipertext[i][j]=block[i][j];
            }
        }
        else{
            Encryption(*(chipertext+i-1),key);
            AddRoundKey(*(block+i),*(chipertext+i-1));
            for(int j=0;j<16;j++){
                chipertext[i][j]=block[i][j];
            }
        }
    }
        printf("\nAfter CFB Encryption:\n");
        for(int i=0;i<textlength/16;i++){
            printf("\nBlock[%d] = \n",i);
            
            for(int j=0;j<16;j++){
                printf("%2x ",block[i][j]);
                if((j+1)%4==0)
                    printf("\n");
            }
            printf("\n");
        }
    }
    //cfb decryption
    else{
    for(int i=0;i<textlength/16;i++){
        if(i==0){
            Encryption(IV, key);
            for(int j=0;j<16;j++){
                chipertext[i][j]=block[i][j];
            }
            AddRoundKey(*(block+i),IV);
        }
        else{
            Encryption(*(chipertext+i-1), key);
            for(int j=0;j<16;j++){
                chipertext[i][j]=block[i][j];
            }
            AddRoundKey(*(block+i), *(chipertext+i));
            
        }
        TextIntoMatrix(*(block+i));
    }
        printf("\nAfter CFB Decryption:\n");
        for(int i=0;i<textlength/16;i++){
            printf("\nBlock[%d] = \n",i);
            
            for(int j=0;j<16;j++){
                printf("%2x ",block[i][j]);
                if((j+1)%4==0)
                    printf("\n");
            }
            printf("\n");
        }
    }
    
}
