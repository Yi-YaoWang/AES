#include<stdio.h>
#include <stdlib.h>
#define MAX 1000
#define Textinput_before_encrypt "/Users/awesome_wood/Documents/AESPROJECT/AESPROJECT/Input.txt"
#define TextOutput_after_encrypt "/Users/awesome_wood/Documents/AESPROJECT/AESPROJECT/output1.txt"
#define Textinput_before_decrypt "/Users/awesome_wood/Documents/AESPROJECT/AESPROJECT/output1.txt"
#define TextOutput_after_decrypt "/Users/awesome_wood/Documents/AESPROJECT/AESPROJECT/output2.txt"

void Read_And_Write(unsigned char*text,unsigned char*key,unsigned char block[MAX][16],unsigned long *textlength,bool en_decrypt,bool read_write){
    FILE *fp;
    size_t read_num;
    unsigned char input_buffer[MAX]={0};
    unsigned char output_buffer[MAX]={0};
    if(read_write==0){
        if(en_decrypt==0){
            fp=fopen(Textinput_before_encrypt, "rb");}
        else{
           fp=fopen(Textinput_before_decrypt, "rb");
        }
    if(fp==NULL){
        printf("no file exist\n");
    }else{
    fread(input_buffer,sizeof(unsigned char),MAX,fp);
    for(int i=0;i<MAX;i++){
        if(input_buffer[i]==0){
            break;
        }
        else{
            text[i]=input_buffer[i];
            printf("%02x ",input_buffer[i]);
            if((i+1)%4==0)
                printf("\n");
        }
    }
        fclose(fp);
    
    }}else{
        for(int i=0;i<1;i++){
            for(int j=0;j<16;j++){
                output_buffer[j+i*16]=block[i][j];
                printf("%2x ",output_buffer[j+i*16]);
            }
        }
        if(en_decrypt==0){
            fp=fopen(TextOutput_after_encrypt,"wb");}
        else{
            fp=fopen(TextOutput_after_decrypt,"wb");
        }
                 fwrite(output_buffer,sizeof(unsigned char),MAX,fp);
                 fclose(fp);
    
                 }
}
