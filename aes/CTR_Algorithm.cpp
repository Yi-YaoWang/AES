#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Header.h"
#define MAX 1000


void CTR_Algorithm(byte * state, byte * key, unsigned char (*block)[16],int textlength,bool en_decrypt)
{
    unsigned char textintomatrix[MAX][MAX];
	//將plaintext分成許多block
	for (int i = 0; i < textlength / 16; i++) {
		for (int j = 0; j < 16; j++) {
			block[i][j] = state[j + i * 16];
		}
	}
	//初始化 初始向量
	byte iv[16] = { 0 };
	for (int i = 0; i < 8; i++)
	{
		iv[i] = i;
	}
	//將初始向量與Counter合併
	for (int i = 0; i < textlength / 16; i++)
	{
		iv[8] = (i / 256 / 256 / 256 / 256 / 256 / 256 / 256);
		iv[9] = (i / 256 / 256 / 256 / 256 / 256 / 256);
		iv[10] = (i / 256 / 256 / 256 / 256 / 256);
		iv[11] = (i / 256 / 256 / 256 / 256);
		iv[12] = (i / 256 / 256 / 256);
		iv[13] = (i / 256 / 256);
		iv[14] = (i / 256);
		iv[15] = i;

		//將初始向量與金鑰做加密
		Encryption(iv, key);

		//最後將block與做完加密的初始金鑰做exclusive or
		for (int j = 0; j < 16; j++) 
		{
			block[i][j] = block[i] [j] ^ iv[j];
		};
	}
    for(int i=0;i<textlength/16;i++){
        for(int j=0;j<16;j++){
            textintomatrix[i][j]=block[i][j];
        }
        TextIntoMatrix(*(textintomatrix+i));
    }
    
    if(en_decrypt==0){
        printf("\nAfter CTR Encryption:\n");
        
    }
    else{
        printf("\nAfter CTR Decryption:\n");}
    for(int i=0;i<textlength/16;i++){
        printf("\nBlock[%d] = \n",i);
        for(int j=0;j<16;j++){
            printf("%2x ",textintomatrix[i][j]);
            if((j+1)%4==0)
                printf("\n");
        }
        printf("\n");
    }

}
