#include <stdio.h>
#include <stdlib.h>
#include "Header.h"



//®œword∏Ã™∫byteªP®‰•Lword∏Ã™∫byte∞µassign∞ ß@™∫®Á¶° 
word ByteOperation_Assign(word L_Value, word R_Value) 
{
	for (int i = 0; i < 4; i++) {
		L_Value.Byte[i] = R_Value.Byte[i];
	}
	return L_Value;
}



//®œword∏Ã™∫byteªP®‰•L™∫byte∞µXOR∞ ß@™∫®Á¶° 
word ByteOperation_ExclusiveOr(word L_Value, word R_Value)
{
	for (int i = 0; i < 4; i++) {
		L_Value.Byte[i] = L_Value.Byte[i] ^ R_Value.Byte[i];
	}
	return L_Value;
}
