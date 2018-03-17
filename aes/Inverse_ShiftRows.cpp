#include<stdio.h>
#include<stdlib.h>
#include"Header.h"


void Inverse_ShiftRows(unsigned char *state){
	unsigned char temp[16];
	
	for(int i=0;i<16;i++){
		if(i<4){
			temp[i]=state[i];
		}
		else if(4<=i&&i<8){
			temp[i]=state[4+(i-1)%4];}
		else if(8<=i&&i<12){
			temp[i]=state[8+(i-2)%4];
		}
		else if(12<=i&&i<16){
			temp[i]=state[12+(i-3)%4];
		}
		
		
	}
	//printf("\nAfter Inverse_ShiftRows:\n");
     for(int i=0;i<16;i++){
		state[i]=temp[i];
		/*printf("%2x ",state[i]);
		if((i+1)%4==0){
			printf("\n");
		}*/
	}
}

