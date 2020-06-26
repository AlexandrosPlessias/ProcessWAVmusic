#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void textArt (){
    printf("\n ¶¶¶¶                               ¶¶                      ¶¶                       ¶¶          ");
    printf("\n  ¶¶¶¶¶                             ¶¶        C             ¶¶         C             ¶¶        ");
    printf("\n  ¶¶  ¶¶                           ¶¶¶¶       S            ¶¶¶¶        S            ¶¶¶¶       ");
    printf("\n   ¶¶  ¶¶                          ¶¶¶¶¶      T            ¶¶¶¶¶       T            ¶¶¶¶¶     ");
    printf("\n    ¶¶ ¶¶¶                         ¶¶  ¶¶                  ¶¶  ¶¶                   ¶¶  ¶¶     ");
    printf("\n    ¶¶ ¶¶¶                         ¶¶  ¶¶     1            ¶¶  ¶¶      1            ¶¶  ¶¶         ");
    printf("\n     ¶¶¶¶¶                         ¶¶ ¶¶¶     1            ¶¶ ¶¶¶      2            ¶¶ ¶¶¶                        ¶¶¶ ");
    printf("\n     ¶¶¶¶                    ¶¶¶¶ ¶¶  ¶¶      0      ¶¶¶¶ ¶¶  ¶¶       0      ¶¶¶¶ ¶¶  ¶¶                     ¶¶¶¶¶¶ ");
    printf("\n    ¶¶¶¶                   ¶¶¶¶¶¶¶¶¶ ¶¶       6    ¶¶¶¶¶¶¶¶¶ ¶¶        7    ¶¶¶¶¶¶¶¶¶ ¶¶                   ¶¶¶¶¶¶¶¶¶   ");
    printf("\n   ¶¶¶ ¶¶  ¶¶¶             ¶¶¶¶¶¶¶¶           8    ¶¶¶¶¶¶¶¶            1    ¶¶¶¶¶¶¶¶                    ¶¶¶¶¶¶¶   ¶¶");
    printf("\n  ¶¶¶   ¶¶¶¶¶¶¶¶¶           ¶¶¶¶¶¶                  ¶¶¶¶¶¶                   ¶¶¶¶¶¶                 ¶¶¶¶¶¶¶¶      ¶¶  ");
    printf("\n ¶¶¶¶  ¶¶¶¶   ¶¶¶¶                                                                               ¶¶¶¶¶¶¶¶¶¶       ¶¶     ");
    printf("\n ¶¶¶  ¶¶¶¶ ¶¶¶  ¶¶¶                                                                            ¶¶¶¶¶¶¶¶   ¶¶       ¶¶        ");
    printf("\n¶¶¶¶  ¶¶¶¶¶¶¶¶¶  ¶¶¶                                                                            ¶¶¶¶¶     ¶¶   ¶¶¶¶¶¶      ");
    printf("\n ¶¶¶  ¶¶¶ ¶¶  ¶  ¶¶¶                                              _       _____ _    __         ¶¶        ¶¶  ¶¶¶¶¶¶¶       ");
    printf("\n ¶¶¶¶  ¶¶¶¶¶¶¶¶  ¶¶          ____  _________  ________  _________| |     / /   | |  / /        ¶¶¶     ¶¶¶¶   ¶¶¶¶¶       ");
    printf("\n  ¶¶¶¶    ¶¶¶  ¶¶¶          / __ \\/ ___/ __ \\/ ___/ _ \\/ ___/ ___/ | /| / / /| | | / /           ¶¶   ¶¶¶¶¶¶     ");
    printf("\n   ¶¶¶¶¶¶   ¶¶¶¶¶          / /_/ / /  / /_/ / /__/  __(__  |__  )| |/ |/ / ___ | |/ /            ¶¶   ¶¶¶¶¶¶     ");
    printf("\n     ¶¶¶¶¶¶¶¶¶¶           / .___/_/   \\____/\\___/\\___/____/____/ |__/|__/_/  |_|___/              ¶¶  ¶¶¶¶     ");
    printf("\n        ¶¶¶ ¶¶¶          /_/                                                                  ¶¶¶¶¶¶        ");
    printf("\n       ¶¶¶¶¶ ¶¶                                                                              ¶¶¶¶¶¶¶");
    printf("\n       ¶¶¶   ¶¶                                                                              ¶¶¶¶¶¶");
    printf("\n         ¶¶¶¶¶                                                                                               ");
    printf("\n\n");
}

unsigned int LittleToBigToDec (byte WAVheaderInput[], int start ,int end){ // Convert little Endianness to big and return the right decimal number.
    int temp[8]={0,0,0,0,0,0,0,0};
    int len;

    len=(end-start)+1;                             // length is position of end - start plus 1.

    if (len==4){                                   // If sting length is 4.

        if (WAVheaderInput[start]<16){             // Convert 1st cell.
            temp[0]=WAVheaderInput[start];         // Mod(%) of deviation.
            temp[1]=0;                             // Div(/) of deviation.
        }
        else{
            temp[0]=WAVheaderInput[start]%16;      // Mod(%) of deviation.
            temp[1]=WAVheaderInput[start]/16;      // Div(/) of deviation.
        }
        if (WAVheaderInput[1]<16){                 // Convert 2nd cell.
            temp[2]=WAVheaderInput[start+1];
            temp[3]=0;
        }
        else{
            temp[2]=WAVheaderInput[start+1]%16;
            temp[3]=WAVheaderInput[start+1]/16;
        }
        if (WAVheaderInput[2]<16){                  // Convert 3rd cell.
            temp[4]=WAVheaderInput[2];
            temp[5]=0;
        }
        else{
            temp[4]=WAVheaderInput[start+2]%16;
            temp[5]=WAVheaderInput[start+2]/16;
        }
        if (WAVheaderInput[3]<16){                   // Convert 4th cell.
            temp[6]=WAVheaderInput[start+3];
            temp[7]=0;
        }
        else{
            temp[6]=WAVheaderInput[start+3]%16;
            temp[7]=WAVheaderInput[start+3]/16;
        }
    }
    else if (len==2){                               // If sting length is 2.

        if (WAVheaderInput[0]<16){                  // Convert 1st cell.
            temp[0]=WAVheaderInput[start];          // Mod(%) of deviation.
            temp[1]=0;                              // Div(/) of deviation.
        }
        else{
            temp[0]=WAVheaderInput[start]%16;      // Div(/) of deviation.
            temp[1]=WAVheaderInput[start]/16;      // Mod(%) of deviation.
        }
         if (WAVheaderInput[1]<16){                // Convert 2nd cell.
            temp[2]=WAVheaderInput[start+1];
            temp[3]=0;
        }
        else{
            temp[2]=WAVheaderInput[start+1]%16;
            temp[3]=WAVheaderInput[start+1]/16;
        }
    }
    else{
        printf("\nHave give wrong type of string.");
        exit(0);
    }
   return ((temp[7]*268435456)+(temp[6]*16777216)+(temp[5]*1048576)+(temp[4]*65536)+(temp[3]*4096)+(temp[2]*256)+(temp[1]*16)+(temp[0]*1)); // Power of 16 (from 7 to 0 by 1).
}

unsigned int DecToLittle (byte WAVheader[],int value, int start ,int end){
    int temp[8]={0,0,0,0,0,0,0,0};
    int divis[8]={0,0,0,0,0,0,0,0};
    int len;

    len=(end-start)+1;                             // length is position of end - start plus 1.

    if (len==4){                                   // If sting length is 4.

        temp[0]=value%16;                          // 1st(from Right to Left) Hex symbol of Decimal.
        divis[0]=value/16;

        temp[1]=divis[0]%16;                       // 2nd (from Right to Left) Hex symbol of Decimal.
        divis[1]=divis[0]/16;

        temp[2]=divis[1]%16;                       // 3th (from Right to Left) Hex symbol of Decimal.
        divis[2]=divis[1]/16;

        temp[3]=divis[2]%16;                       // 4th (from Right to Left) Hex symbol of Decimal.
        divis[3]=divis[2]/16;

        temp[4]=divis[3]%16;                       // 5th (from Right to Left) Hex symbol of Decimal.
        divis[4]=divis[3]/16;

        temp[5]=divis[4]%16;                       // 6th (from Right to Left) Hex symbol of Decimal.
        divis[5]=divis[4]/16;

        temp[6]=divis[5]%16;                       // 7th (from Right to Left) Hex symbol of Decimal.
        divis[6]=divis[5]/16;

        temp[7]=divis[6]%16;                       // 8th (from Right to Left) Hex symbol of Decimal.
        divis[7]=divis[6]/16;

        WAVheader[start]=(temp[1]*16)+temp[0];          // Convert 1st cell. (2rd Hex symbol *16 1st Hex symbol).
        WAVheader[start+1]=(temp[3]*16)+temp[2];        // Convert 2nd cell. (4rd Hex symbol *16 3rd Hex symbol).
        WAVheader[start+2]=(temp[5]*16)+temp[4];        // Convert 3rd cell. (6th Hex symbol *16 5th Hex symbol).
        WAVheader[start+3]=(temp[7]*16)+temp[6];        // Convert 4th cell. (8th Hex symbol *16 7th Hex symbol).
    }
    else if (len==2){                                   // If sting length is 2.

        temp[0]=value%16;                               // 1st(from Right to Left) Hex symbol of Decimal.
        divis[0]=value/16;

        temp[1]=divis[0]%16;                            // 2nd (from Right to Left) Hex symbol of Decimal.
        divis[1]=divis[0]/16;

        temp[2]=divis[1]%16;                            // 3th (from Right to Left) Hex symbol of Decimal.
        divis[2]=divis[1]/16;

        temp[3]=divis[2]%16;                            // 4th (from Right to Left) Hex symbol of Decimal.
        divis[3]=divis[2]/16;

        WAVheader[start]=(temp[1]*16)+temp[0];          // Convert 1st cell. (2rd Hex symbol *16 1st Hex symbol).
        WAVheader[start+1]=(temp[3]*16)+temp[2];        // Convert 2nd cell. (4rd Hex symbol *16 3rd Hex symbol).
    }
    else{
        printf("\nHave give value over 4.294.967.295");
        exit(0);
    }
    return;
}

void  headerList(unsigned int ChunkSize, unsigned int Subchunk1Size, unsigned int AudioFormat, unsigned int NumChannels, unsigned int SampleRate, unsigned int ByteRate, unsigned int BlockAlign, unsigned int BitsPerSample, unsigned int Subchunk2Size, char ChunkID[], char Format[], char Subchunk1ID[], char Subchunk2ID[]){ // Just print the HEADER info.
    printf("\nRIFF_CHUNK_HEADER");
    printf("\n=================");
    printf("\nChunkID:%s",ChunkID);
    printf("\nChunkSize:%d",ChunkSize);
    printf("\nFormat:%s\n",Format);
    printf("\nFMT_SUBCHUNK_HEADER");
    printf("\n===================");
    printf("\nSubchunk1ID:%s",Subchunk1ID);
    printf("\nSubchunk1Size:%d",Subchunk1Size);
    printf("\nAudioFormat:%d",AudioFormat);
    printf("\nNumChannels:%d",NumChannels);
    printf("\nSampleRate:%d",SampleRate);
    printf("\nByteRate:%d",ByteRate);
    printf("\nBlockAlign:%d",BlockAlign);
    printf("\nBitsPerSample:%d\n",BitsPerSample);
    printf("\nDATA_SUBCHUNK_HEADER");
    printf("\n====================");
    printf("\nSubchunk2ID:%s",Subchunk2ID);
    printf("\nSubchunk2Size:%d\n",Subchunk2Size);

    return;
}

void reverse(byte WAVheaderInput[],unsigned int ChunkSize, char nameInput[],char nameOutput[]){
    int i;
    byte a,b,c,d; // Temp byte values for loading and .

    FILE* fpInput;
    FILE* fpOutput;

    fpInput=fopen(nameInput,"rb");                          // Open Input binary file.
    fpOutput=fopen(nameOutput,"wb");                        // Create and open Output binary file.

    if (fpOutput==NULL){
        printf("\nError: File can not be created.");
        exit(1);
    }
    else{
        fwrite(WAVheaderInput,sizeof(byte),44,fpOutput);

        for (i = (ChunkSize+7); i>45; i=i-4) {              // Access to Input binary file from the end until the end of the Header.
            fseek(fpInput,i, SEEK_SET);                     // Change in each loop position of 'fpInput'.

            fread(&d,1,1,fpInput);                          // Last.
            fread(&c,1,1,fpInput);                          // Last-1.
            fread(&b,1,1,fpInput);                          // Last-2.
            fread(&a,1,1,fpInput);                          // Last-3.

            fwrite(&a,1,1,fpOutput);                        // First
            fwrite(&b,1,1,fpOutput);                        // First+1.
            fwrite(&c,1,1,fpOutput);                        // First+2.
            fwrite(&d,1,1,fpOutput);                        // First+3.
       }
       printf("\nSuccess: The reverse function completed.\n");
    }

    fclose(fpOutput);                                       // Close Input binary file.
    fclose(fpInput);                                        // Close Output binary file.

    return;
}

void mono(byte WAVheaderMono[],unsigned int Subchunk2Size, char nameInput[],char nameOutput[]){
    int i;
    byte a,b;                                               // Temp byte values for loading bytes.

    FILE* fpInput;
    FILE* fpOutput;

    fpInput=fopen(nameInput,"rb");                          // Open Input binary file.
    fpOutput=fopen(nameOutput,"wb");                        // Create and open Output binary file.

    if (fpOutput==NULL){
        printf("\nError: File can not be created.");
        exit(1);
    }
    else{
        fwrite(WAVheaderMono,sizeof(byte),45,fpOutput);

        for (i=45; i<(Subchunk2Size-1); i=i+4){            // Access to Input binary file from start of Sample until end.
            fseek(fpInput,i, SEEK_SET);                     // Change in each loop/sample position of 'fpInput'.

            fread(&a,1,1,fpInput);                          // Load first of Left.
            fread(&b,1,1,fpInput);                          // Load second of Left.

            fwrite(&a,1,1,fpOutput);                        // Write first of Left.
            fwrite(&b,1,1,fpOutput);                        // Write second of Left.
            //printf("%d\n",i);
       }
       printf("\nSuccess: The mono function completed.\n");
    }

    fclose(fpOutput);                                       // Close Input binary file.
    fclose(fpInput);                                        // Close Output binary file.

    return;
}

void crop(byte WAVheaderCrop[],unsigned int Subchunk2Size, char nameInput[],char nameOutput[], unsigned int SampleRate, unsigned int NumChannels, unsigned int BitsPerSample,int tStart, int tEnd){

    byte a;                                           // Temp byte values for loading bytes.
    unsigned int i, bytesStart, bytesEnd;

    bytesStart=tStart*((SampleRate*BitsPerSample*NumChannels)/8);
    bytesEnd=tEnd*((SampleRate*BitsPerSample*NumChannels)/8);

    bytesStart=bytesStart+43;
    bytesEnd=bytesEnd+43;

    FILE* fpInput;
    FILE* fpOutput;

    fpInput=fopen(nameInput,"rb");                          // Open Input binary file.
    fpOutput=fopen(nameOutput,"wb");                        // Create and open Output binary file.

    if (fpOutput==NULL){
        printf("\nError: File can not be created.");
        exit(1);
    }
    else{
        fwrite(WAVheaderCrop,sizeof(byte),45,fpOutput);

        for (i=bytesStart;i<bytesEnd; i++){            // Access to Input binary file from start of Sample until end.
            fseek(fpInput,i, SEEK_SET);                     // Change in each loop/sample position of 'fpInput'.

            fread(&a,1,1,fpInput);                          // Load.

            fwrite(&a,1,1,fpOutput);                        // Write.
            //printf("%d\n",i);
       }
       printf("\nSuccess: The crop function completed.\n");
    }

    fclose(fpOutput);                                       // Close Input binary file.
    fclose(fpInput);                                        // Close Output binary file.

    return;
}
