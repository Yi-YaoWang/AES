
#include<stdio.h>
#include <stdlib.h>
#define MAX 15760

void Read_And_WriteJPG(unsigned char*text,unsigned char*key,unsigned char block[MAX][16],unsigned long *textlength,bool read_write){
    FILE *fp;
    size_t read_num;
    unsigned char input_buffer[MAX]={0};
    unsigned char output_buffer[MAX]={0};
    if(read_write==0){
        fp=fopen("/Users/awesome_wood/Documents/AESPROJECT/AESPROJECT/j1.jpg", "rb");
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
            for(int i=0;i<MAX;i++){
                for(int j=0;j<16;j++){
                    output_buffer[j+i*16]=block[i][j];
                    printf("%2x ",output_buffer[j+i*16]);
                }
            }
            
            fp=fopen("/Users/awesome_wood/Documents/AESPROJECT/AESPROJECT/j2.jpg","wb");
            fwrite(output_buffer,sizeof(unsigned char),MAX,fp);
            fclose(fp);
            
        }
}
