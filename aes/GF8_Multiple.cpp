#include <stdio.h>
#include <stdlib.h>
#include "Header.h"


unsigned char GF8_Multiple(unsigned char hex,int times){
	if(times==0x01){
		hex=hex;
	}
	else if(hex<0x80&&times==0x02){
		hex=hex<<1;
	}
	else if(hex>=0x80&&times==0x02){
		hex=hex<<1;
		hex=hex^0x1b;
	}
	else if(times==0x03){
		hex=GF8_Multiple(hex,0x02)^GF8_Multiple(hex,0x01);
	}
	else if(times==0x09){
		hex=GF8_Multiple(GF8_Multiple(GF8_Multiple(hex,0x02),0x02),0x02)^GF8_Multiple(hex,0x01);
	}
	else if(times==0x0b){
		hex=GF8_Multiple((GF8_Multiple(GF8_Multiple(hex,0x02),0x02)^GF8_Multiple(hex,0x01)), 0x02)^GF8_Multiple(hex, 0x01);
	}
	else if(times==0x0d){
		hex=GF8_Multiple(GF8_Multiple((GF8_Multiple(hex,0x02)^GF8_Multiple(hex,0x01)),0x02), 0x02)^GF8_Multiple(hex,0x01);
	}
	else if(times==0x0e){
		hex=GF8_Multiple(((GF8_Multiple((GF8_Multiple(hex, 0x02)^GF8_Multiple(hex,0x01)), 0x02))^GF8_Multiple(hex, 0x01)), 0x02);
	}
	return hex;
}
