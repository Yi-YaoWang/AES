#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include "Header.h"

void OFB_Algorithm(unsigned char*text,unsigned char*key,unsigned char (*block)[16],int textlength,bool en_decrypt){
    unsigned char IV[16]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10,0x11,0x12,0x13,0x14,0x15};
    unsigned char temp[16];
    unsigned char registtext[textlength/16][16];
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
    //ofb encryption
    if(en_decrypt==0){
    for(int i=0;i<textlength/16;i++){
        if(i==0){
            Encryption(temp,key);
            for(int j=0;j<16;j++){
                registtext[i][j]=temp[j];
            }
            AddRoundKey(*(block+i),*(registtext+i));
            
        }
        else{
            Encryption(*(registtext+i-1),key);
            for(int j=0;j<16;j++){
                registtext[i][j]=registtext[i-1][j];
            }
            AddRoundKey(*(block+i),*(registtext+i));
        }
    }
        printf("\nAfter OFB Encryption:\n");
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
    //decryption
    else{
    for(int i=0;i<textlength/16;i++){
        if(i==0){
            Encryption(IV, key);
            for(int j=0;j<16;j++){
            registtext[i][j]=IV[j];
        }
        AddRoundKey(*(block+i),*(registtext+i));
        
    }
        else{
            Encryption(*(registtext+i-1),key);
            for(int j=0;j<16;j++){
                registtext[i][j]=registtext[i-1][j];
            }
            AddRoundKey(*(block+i),*(registtext+i));
        }
        TextIntoMatrix(*(block+i));
    }
        printf("\nAfter OFB Decryption:\n");
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
