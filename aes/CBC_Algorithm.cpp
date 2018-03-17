#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include "Header.h"

void CBC_Algorithm(unsigned char*text,unsigned char*key,unsigned char (*block)[16],int textlength,bool en_decrypt){
    unsigned char IV[16]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10,0x11,0x12,0x13,0x14,0x15};
    unsigned char chipertext[textlength/16][16];
   // for(int i=0;)
    for(int i=0;i<textlength/16;i++){
        for(int j=0;j<16;j++){
            block[i][j]=text[j+i*16];
        }
    }
    
    //encryption
    if(en_decrypt==0){
    for(int i=0;i<textlength/16;i++){
        if(i==0){
        for(int j=0;j<16;j++){
                block[i][j]=block[i][j]^IV[j];
            }
        Encryption(*(block+i),key);
        }
        else{
            Encryption(*(block+i),*(block+i-1));}
    }
        printf("\nAfter CBC Encryption:\n");
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
    //store ciphertext
    else{
    for(int i=0;i<textlength/16;i++){
        for(int j=0;j<16;j++){
            chipertext[i][j]=block[i][j];
        }
    }
    //decryption
    for(int i=0;i<textlength/16;i++){
        if(i==0){
            Decryption(*(block+i),key);
            AddRoundKey(*(block+i),IV);
            
                }
        else{
            Decryption(*(block+i),key);
            AddRoundKey(*(block+i),*(chipertext+i-1));
    }
    }
        printf("\nAfter CBC Decryption:\n");
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
