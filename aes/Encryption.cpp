#include<stdio.h>
#include<stdlib.h>
#include"Header.h"


void Encryption(unsigned char *state,unsigned char *key){
	unsigned char roundkey[16];
	TextIntoMatrix(state);
	AddRoundKey(state,key);
	for(int i=1;i<=9;i++){
		Roundkey(key, roundkey, i);
		SubBytes(state);
		ShiftRows(state);
		MixColumns(state);
		AddRoundKey(state, roundkey);
	}
	Roundkey(key, roundkey, 10);
	SubBytes(state);
	ShiftRows(state);
	AddRoundKey(state, roundkey);
}

