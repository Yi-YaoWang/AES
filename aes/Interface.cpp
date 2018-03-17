#include<stdio.h>
#include<stdlib.h>
#include"Header.h"

void Interface(unsigned char*text,unsigned char*key,unsigned char block[MAX][16],unsigned long *textlength,bool en_decrypt,bool read_write){
    int option,mode;
    unsigned long p;
    printf("Welcome to the AES Encryption/Decryption Operator!\n\nPlease select the following option to Encrypt or Decrypt:");
    printf("\n\n(1.)Encryption\n\n(2.)Decryption\n\n=>");
    scanf("%d",&option);
    switch(option){
        case 1:
            printf("\n\nSelect the following option to operate:\n\n(1.)ECB Encryption");
            printf("\n\n(2.)CBC Encryption");
            printf("\n\n(3.)OFB Encryption");
            printf("\n\n(4.)CFB Encryption");
            printf("\n\n(5.)CTR Encryption");
            printf("\n\n(6.)CFB 8 Encryption");
            printf("\n\n=>");
            scanf("%d",&mode);
            switch(mode){
                case 1:
                    Read_And_Write(text, key, block, &p,0,0);
                    ECB_Algorithm(text, key, block, 16, 0);
                    Read_And_Write(text, key, block, &p,0,1);
                    break;
                case 2:
                    Read_And_Write(text, key, block, &p,0,0);
                    CBC_Algorithm(text, key, block, 16, 0);
                    Read_And_Write(text, key, block, &p,0,1);
                    break;
                case 3:
                    Read_And_Write(text, key, block, &p,0,0);
                    OFB_Algorithm(text, key, block, 16, 0);
                    Read_And_Write(text, key, block, &p,0,1);
                    break;
                case 4:
                    Read_And_Write(text, key, block, &p,0,0);
                    CFB_Algorithm(text, key, block, 16, 0);
                    Read_And_Write(text, key, block, &p,0,1);
                    break;
                case 5:
                    Read_And_Write(text, key, block, &p,0,0);
                    CTR_Algorithm(text, key, block, 16, 0);
                    Read_And_Write(text, key, block, &p,0,1);
                    break;
                case 6:
                    Read_And_Write(text, key, block, &p,0,0);
                    CFB8_Algorithm(text, key, block, 16, 0);
                    Read_And_Write(text, key, block, &p,0,1);
                    break;
            }
            break;
    
        case 2:
            printf("\n\nSelect the following option to operate:\n\n(1.)ECB Decryption");
            printf("\n\n(2.)CBC Decryption");
            printf("\n\n(3.)OFB Decryption");
            printf("\n\n(4.)CFB Decryption");
            printf("\n\n(5.)CTR Decryption");
            printf("\n\n(6.)CFB 8 Decryption");
            printf("\n\n=>");
            scanf("%d",&mode);
            switch(mode){
                case 1:
                    Read_And_Write(text, key, block, &p, 1, 0);
                    ECB_Algorithm(text, key, block, 16, 1);
                    Read_And_Write(text, key, block, &p, 1, 1);
                    break;
                case 2:
                    Read_And_Write(text, key, block, &p, 1, 0);
                    CBC_Algorithm(text, key, block, 16, 1);
                    Read_And_Write(text, key, block, &p, 1, 1);
                    break;
                case 3:
                    Read_And_Write(text, key, block, &p, 1, 0);
                    OFB_Algorithm(text, key, block, 16, 1);
                    Read_And_Write(text, key, block, &p, 1, 1);
                    break;
                case 4:
                    Read_And_Write(text, key, block, &p, 1, 0);
                    CFB_Algorithm(text, key, block, 16, 1);
                    Read_And_Write(text, key, block, &p, 1, 1);
                    break;
                case 5:
                    Read_And_Write(text, key, block, &p, 1, 0);
                    CTR_Algorithm(text, key, block, 16, 1);
                    Read_And_Write(text, key, block, &p, 1, 1);
                    break;
                case 6:
                    Read_And_Write(text, key, block, &p, 1, 0);
                    CFB8_Algorithm(text, key, block, 16, 1);
                    Read_And_Write(text, key, block, &p, 1, 1);
                    break;
            }
            break;
}
   
}
