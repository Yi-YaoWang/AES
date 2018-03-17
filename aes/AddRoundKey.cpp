#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void AddRoundKey(unsigned char *state,unsigned char *key){
	unsigned char temp[16];
	
	temp[0]=state[0]^key[0];
	temp[4]=state[4]^key[1];
	temp[8]=state[8]^key[2];
	temp[12]=state[12]^key[3];
	temp[1]=state[1]^key[4];
	temp[5]=state[5]^key[5];
	temp[9]=state[9]^key[6];
	temp[13]=state[13]^key[7];
	temp[2]=state[2]^key[8];
	temp[6]=state[6]^key[9];
	temp[10]=state[10]^key[10];
	temp[14]=state[14]^key[11];
	temp[3]=state[3]^key[12];
	temp[7]=state[7]^key[13];
	temp[11]=state[11]^key[14];
	temp[15]=state[15]^key[15];
	
     //printf("\nAfter AddRoundKey:\n");
     for(int i=0;i<16;i++){
		state[i]=temp[i];
		/*printf("%2x ",state[i]);
		if((i+1)%4==0){
			printf("\n");
		}*/
	}
	
}
