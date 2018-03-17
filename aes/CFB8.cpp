#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include "Header.h"
#define MAX 1000


void CFB8_Algorithm(byte * state, byte * key,unsigned char (*block)[16], int textlength,bool en_decrypt)
{
	//�Nplaintext���� 8 Byte Block
	unsigned char textintomatrix[MAX][MAX];
    if(en_decrypt==0){
	for (int i = 0; i < textlength / 8; i++) {
		for (int j = 0; j < 8; j++) {
			block[i][j] = state[j + i * 8];
		}
	}
	//��l�� ��l�V�q
	byte iv[16] = { 0 };
	for (int i = 0; i < 16; i++)
	{
		iv[i] = i;
	}
	for (int i = 0; i < textlength / 8; i++)
	{
		//�N��l�V�q�P���_���[�K
		Encryption(iv, key);

		//�N�[�L�K��iv��8 byte block �� exclusive or 
		for (int j = 0; j < 8; j++)
		{
			block[i][j] = block[i][j] ^ iv[j];
		}

		//����IV�åέ�貧�Ϊ��K��ɤW
		for (int j = 0; j < 8; j++)
		{
			iv[j] = iv[j + 8];
			iv[j + 8] = block[i][j];
		}
	}

	//�N 8 byte block��^ciphertext
	for (int i = 0; i < textlength / 8; i++) {
		for (int j = 0; j < 8; j++) {
			state[j + i * 8] = block[i][j];
		}
        
	}
    }else{
	//�NCiphertext���� 8 Byte Block
	byte temp[8] = { 0 };
	for (int i = 0; i < textlength / 8; i++) {
		for (int j = 0; j < 8; j++) {
			block[i][j] = state[j + i * 8];
		}
	}
	//��l�� ��l�V�q
	byte iv[16] = { 0 };
	for (int i = 0; i < 16; i++)
	{
		iv[i] = i;
	}
	for (int i = 0; i < textlength / 8; i++)
	{
		//�N��l�V�q�P���_���[�K
		Encryption(iv, key);

		//�N�[�L�K��iv��8 byte block �� exclusive or 
		for (int j = 0; j < 8; j++)
		{
			temp[j] = block[i][j];
			block[i][j] = block[i][j] ^ iv[j];
		}

		//����IV�åΥ��Ӫ��K��ɤW
		for (int j = 0; j < 8; j++)
		{
			iv[j] = iv[j + 8];
			iv[j + 8] = temp [j];
		}
	}

	//�N 8 byte block��^ciphertext
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
