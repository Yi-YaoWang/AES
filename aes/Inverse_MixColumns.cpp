#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void Inverse_MixColumns(unsigned char *state){
	unsigned char temp[16]={0};
	
	for(int i=0;i<4;i++){
		temp[i]=(GF8_Multiple(state[i],0x0e))^(GF8_Multiple(state[i+4],0x0b))^(GF8_Multiple(state[i+8],0x0d))^(GF8_Multiple(state[i+12],0x09));
		temp[i+4]=(GF8_Multiple(state[i],0x09))^(GF8_Multiple(state[i+4],0x0e))^(GF8_Multiple(state[i+8],0x0b))^(GF8_Multiple(state[i+12],0x0d));
		temp[i+8]=(GF8_Multiple(state[i],0x0d))^(GF8_Multiple(state[i+4],0x09))^(GF8_Multiple(state[i+8],0x0e))^(GF8_Multiple(state[i+12],0x0b));
		temp[i+12]=(GF8_Multiple(state[i],0x0b))^(GF8_Multiple(state[i+4],0x0d))^(GF8_Multiple(state[i+8],0x09))^(GF8_Multiple(state[i+12],0x0e));
	}
	//printf("\nAfter Inverse_MixColumns:\n");
     for(int i=0;i<16;i++){
		state[i]=temp[i];
		/*printf("%2x ",state[i]);
		if((i+1)%4==0)
			printf("\n");*/
	}
}

