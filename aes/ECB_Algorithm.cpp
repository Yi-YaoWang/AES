#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void ECB_Algorithm(unsigned char*text,unsigned char*key,unsigned char (*block)[16],int textlength,bool en_decrypt){
    
    
            
    
    
    for(int i=0;i<textlength/16;i++){
        for(int j=0;j<16;j++){
            block[i][j]=text[j+i*16];
        }
    }
    //ebc encryption
    if(en_decrypt==0){
        for(int i=0;i<textlength/16;i++){
        Encryption(*(block+i),key);
        }
        printf("\nAfter ECB Encryption:\n");
        for(int i=0;i<textlength/16;i++){
            printf("\nBlock[%d] = \n",i);
            
            for(int j=0;j<16;j++){
                printf("%2x ",block[i][j]);
                if((j+1)%4==0)
                    printf("\n");
            }
            printf("\n");
        }
        
    }else{
  //ebc decryption
    
        
        
        
        for(int i=0;i<textlength/16;i++){
        Decryption(*(block+i),key);
        }
        printf("\nAfter ECB Decryption:\n");
        for(int i=0;i<textlength/16;i++){
            printf("\nBlock[%d] = \n",i);
            for(int i=0;i<textlength/16;i++){
                for(int j=0;j<16;j++){
                    text[j+i*16]=block[i][j];
                }
                for(int k=0;k<4;k++){
                    for(int m=0;m<4;m++){
                        block[i][k+4*m]=text[4*k+m+16*i];
                    }
                }
            }
            for(int j=0;j<16;j++){
                printf("%2x ",block[i][j]);
                if((j+1)%4==0)
                    printf("\n");
            }
            printf("\n");
        }
    }
}
