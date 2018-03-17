#include<stdio.h>
#include<stdlib.h>
#include"Header.h"


void Decryption(unsigned char *state,unsigned char *key){
	unsigned char roundkey[16];
	Roundkey(key,roundkey,10);
	AddRoundKey(state, roundkey);
	Inverse_ShiftRows(state);
	Inverse_SubBytes(state);
	for(int i=9;i>=1;i--){
		Roundkey(key, roundkey,i);
		AddRoundKey(state, roundkey);
		Inverse_MixColumns(state);
		Inverse_ShiftRows(state);
		Inverse_SubBytes(state);
	}
	Roundkey(key,roundkey,0);
	AddRoundKey(state,roundkey);
}


