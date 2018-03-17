#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include "Header.h"
#define MAX 1000


void CFB8_Algorithm(byte * state, byte * key,unsigned char (*block)[16], int textlength,bool en_decrypt)
{
	//將plaintext分成 8 Byte Block
	unsigned char textintomatrix[MAX][MAX];
    if(en_decrypt==0){
	for (int i = 0; i < textlength / 8; i++) {
		for (int j = 0; j < 8; j++) {
			block[i][j] = state[j + i * 8];
		}
	}
	//初始化 初始向量
	byte iv[16] = { 0 };
	for (int i = 0; i < 16; i++)
	{
		iv[i] = i;
	}
	for (int i = 0; i < textlength / 8; i++)
	{
		//將初始向量與金鑰做加密
		Encryption(iv, key);

		//將加過密的iv跟8 byte block 做 exclusive or 
		for (int j = 0; j < 8; j++)
		{
			block[i][j] = block[i][j] ^ iv[j];
		}

		//左移IV並用剛剛異或的密文補上
		for (int j = 0; j < 8; j++)
		{
			iv[j] = iv[j + 8];
			iv[j + 8] = block[i][j];
		}
	}

	//將 8 byte block轉回ciphertext
	for (int i = 0; i < textlength / 8; i++) {
		for (int j = 0; j < 8; j++) {
			state[j + i * 8] = block[i][j];
		}
        
	}
    }else{
	//將Ciphertext分成 8 Byte Block
	byte temp[8] = { 0 };
	for (int i = 0; i < textlength / 8; i++) {
		for (int j = 0; j < 8; j++) {
			block[i][j] = state[j + i * 8];
		}
	}
	//初始化 初始向量
	byte iv[16] = { 0 };
	for (int i = 0; i < 16; i++)
	{
		iv[i] = i;
	}
	for (int i = 0; i < textlength / 8; i++)
	{
		//將初始向量與金鑰做加密
		Encryption(iv, key);

		//將加過密的iv跟8 byte block 做 exclusive or 
		for (int j = 0; j < 8; j++)
		{
			temp[j] = block[i][j];
			block[i][j] = block[i][j] ^ iv[j];
		}

		//左移IV並用本來的密文補上
		for (int j = 0; j < 8; j++)
		{
			iv[j] = iv[j + 8];
			iv[j + 8] = temp [j];
		}
	}

	//將 8 byte block轉回ciphertext
	for (int i = 0; i < textlength / 8; i++) {
		for (int j = 0; j < 8; j++) {
			state[j + i * 8] = block[i][j];
		}
	}

}
    for(int i=0;i<textlength/16;i++){
        for(int j=0;j<16;j++){
            textintomatrix[i][j]=block[i][j];
        }
        TextIntoMatrix(*(textintomatrix+i));
    }
    
    if(en_decrypt==0){
        printf("\nAfter CFB8 Encryption:\n");
        
    }
    else{
        printf("\nAfter CFB8 Decryption:\n");}
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
