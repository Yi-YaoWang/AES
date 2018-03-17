#include <stdio.h>
#include <stdlib.h>
#include "Header.h"



word *KeyExpanasion (word *w, byte key [16] )
{
	 word temp = {0};
	 word Rcon[14] = {0};
	 //™Ï©l§∆Rcon[j]
	 {
	 Rcon[0].Byte[0] = { 0x01 };
	 Rcon[1].Byte[0] = { 0x02 };
	 Rcon[2].Byte[0] = { 0x04 };
	 Rcon[3].Byte[0] = { 0x08 };
	 Rcon[4].Byte[0] = { 0x10 };
	 Rcon[5].Byte[0] = { 0x20 };
	 Rcon[6].Byte[0] = { 0x40 };
	 Rcon[7].Byte[0] = { 0x80 };
	 Rcon[8].Byte[0] = { 0x1B };
	 Rcon[9].Byte[0] = { 0x36 };
	 }
	 //™Ï©l§∆§@∂}©l™∫keyØx∞}¶®¨∞wordØx∞}
	for ( int i = 0; i < 4; i++)
	{
		w[i].Byte[0] = key[4 * i];
		w[i].Byte[1] = key[4 * i+1];
		w[i].Byte[2] = key[4 * i+2];
		w[i].Byte[3] = key[4 * i+3];
	}

	//∂}©l¬X±i™˜∆_
	for (int i = 4; i < 44; i++)
	{
		temp = ByteOperation_Assign(temp, w[i - 1]);
		if (i % 4 == 0) {
			temp = function_g(temp, Rcon[(i / 4)-1]);
		}
		w[i] = ByteOperation_ExclusiveOr(w[i - 4], temp);
	}
	return w;
}



