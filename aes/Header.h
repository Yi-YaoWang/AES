#pragma once

#define byte unsigned char
#define MAX 1000
struct word
{
	byte Byte[4] = {0};
};
void Interface(unsigned char*text,unsigned char*key,unsigned char block[MAX][16],unsigned long *textlength,bool en_decrypt,bool read_write);
void Read_And_Write(unsigned char*text,unsigned char*key,unsigned char block[MAX][16],unsigned long *textlength,bool en_decrypt,bool read_write);

word *KeyExpanasion (word *w, byte key[16]);
word ByteOperation_Assign(word L_Value, word R_Value);
word ByteOperation_ExclusiveOr(word L_Value, word R_Value);
word function_g(word w, word Rcon );
word RotWord(word w);
word SubWord(word w);
void TextIntoMatrix(unsigned char* state);
void AddRoundKey(unsigned char *state,unsigned char *roundkey);
void SubBytes(unsigned char *state);
void ShiftRows(unsigned char*state);
void Encryption(unsigned char*state,unsigned char*key);
void MixColumns(unsigned char*state);
unsigned char GF8_Multiple(unsigned char hex,int times);
void Roundkey(unsigned char *key,unsigned char *roundkey,int round);
void Decryption(unsigned char *state,unsigned char *key);
void Inverse_SubBytes(unsigned char *state);
void Inverse_ShiftRows(unsigned char *state);
void Inverse_MixColumns(unsigned char *state);
void ECB_Algorithm(unsigned char*text,unsigned char*key,unsigned char (*block)[16],int textlength,bool en_decrypt);
void CBC_Algorithm(unsigned char*text,unsigned char*key,unsigned char (*block)[16],int textlength,bool en_decrypt);
void CTR_Algorithm(byte * state, byte * key, unsigned char (*block)[16],int textlength,bool en_decrypt);
void OFB_Algorithm(unsigned char*text,unsigned char*key,unsigned char (*block)[16],int textlength,bool en_decrypt);
void CFB_Algorithm(unsigned char*text,unsigned char*key,unsigned char (*block)[16],int textlength,bool en_decrypt);
void CFB8_Algorithm(byte * state, byte * key,unsigned char (*block)[16], int textlength,bool en_decrypt);
