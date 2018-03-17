#include <stdio.h>
#include "Header.h"

void Roundkey(unsigned char *key,unsigned char *roundkey,int round){
	word w[44];
	KeyExpanasion(w,key);
	//printf("\nRoundKey[%d]:\n",round);
	for(int i=0;i<16;i++){
		roundkey[i]=(w+4*round+(i/4))->Byte[i%4];
		/*printf("%2x ",roundkey[i]);
		if((i+1)%4==0){
			printf("\n");
	}*/
}
}


