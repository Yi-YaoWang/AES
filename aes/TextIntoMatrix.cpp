#include<stdio.h>
#include<stdlib.h>
#include"Header.h"

void TextIntoMatrix(unsigned char* state){
	unsigned char temp[16];
	//printf("\nAfter TextIntoMatrix:\n");
	for(int i=0;i<16;i++){
		temp[i]=state[i];
	}
	*(state+0)=*temp;
	*(state+4)=*(temp+1);
	*(state+8)=*(temp+2);
	*(state+12)=*(temp+3);
	*(state+1)=*(temp+4);
	*(state+5)=*(temp+5);
	*(state+9)=*(temp+6);
	*(state+13)=*(temp+7);
	*(state+2)=*(temp+8);
	*(state+6)=*(temp+9);
	*(state+10)=*(temp+10);
	*(state+14)=*(temp+11);
	*(state+3)=*(temp+12);
	*(state+7)=*(temp+13);
	*(state+11)=*(temp+14);
	*(state+15)=*(temp+15);
	/*for(int i=0;i<16;i++){
		printf("%2x ",*(state+i));
		if((i+1)%4==0){
			printf("\n");
		}
	}*/
}
