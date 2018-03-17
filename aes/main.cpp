#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Header.h"
#define MAX 1000

using namespace std;

int main(){
    unsigned char text[MAX];
    unsigned char key[16]={0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};
    unsigned long p;
    unsigned char block[MAX][16];
    bool en_decrypt;
    bool read_write;
    
    
    unsigned char state[16]={0x32,0x43,0xf6,0xa8,0x88,0x5a,0x30,0x8d,0x31,0x31,0x98,0xa2,0xe0,0x37,0x07,0x34};
    
    /*unsigned char (*block)[16]=&state;
   /* printf("Plain text:\n");
    for(int i=0;i<16;i++){
        printf("%2x ",*(state+i));
        if((i+1)%4==0)
            printf("\n");
    }
    printf("\nKey:\n");
    for(int i=0;i<16;i++){
        printf("%2x ",*(key+i));
        if((i+1)%4==0)
            printf("\n");
    }*/
    Interface(text, key, block, &p, en_decrypt, read_write);
    
    
    
    system("pause");
    
}
