#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void MixColumns(unsigned char *state){
	unsigned char temp[16]={0};
	
	for(int i=0;i<4;i++){
		temp[i]=(GF8_Multiple(state[i],0x02))^(GF8_Multiple(state[i+4],0x03))^(GF8_Multiple(state[i+8],0x01))^(GF8_Multiple(state[i+12],0x01));
		temp[i+4]=(GF8_Multiple(state[i],0x01))^(GF8_Multiple(state[i+4],0x02))^(GF8_Multiple(state[i+8],0x03))^(GF8_Multiple(state[i+12],0x01));
		temp[i+8]=(GF8_Multiple(state[i],0x01))^(GF8_Multiple(state[i+4],0x01))^(GF8_Multiple(state[i+8],0x02))^(GF8_Multiple(state[i+12],0x03));
		temp[i+12]=(GF8_Multiple(state[i],0x03))^(GF8_Multiple(state[i+4],0x01))^(GF8_Multiple(state[i+8],0x01))^(GF8_Multiple(state[i+12],0x02));
	}
    
    //printf("\nAfter MixColumns:\n");
	for(int i=0;i<16;i++){
		state[i]=temp[i];
		/*printf("%2x ",state[i]);
		if((i+1)%4==0)
			printf("\n");*/
	}

}
