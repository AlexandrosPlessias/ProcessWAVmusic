#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

int main(int argc, char **argv){    // start of main, use of command line: argc variable for the count of arguements and **argv for arguements as strings

    FILE* fpInput;                  //file pointer create

    int i,j,tStart=0,tEnd=0,ChoiseFlag=0,totalTime;     // integer variable declaration
    unsigned int ChunkSize,Subchunk1Size,AudioFormat, NumChannels, SampleRate, ByteRate, BlockAlign, BitsPerSample, Subchunk2Size;
    char ChunkID[20], Format[20], Subchunk1ID[20], Subchunk2ID[20]; //char arrays declaration that being used as strings

    textArt();  //textArt function call


    if(argc==1){    //if there is only 1 arguement, print error message
        printf("\nError: Wrong arguments.");
        exit(1);
    }

    if(!strcmp("-list",argv[1]) && argc==3) //ckeck if the arguements are correct
        ChoiseFlag=1;
    if(!strcmp("-reverse",argv[1]) && argc==4)
        ChoiseFlag=2;
    if(!strcmp("-mono",argv[1]) && argc==4)
        ChoiseFlag=3;
    if(!strcmp("-crop",argv[1]) && argc==6)
        ChoiseFlag=4;
    if (ChoiseFlag==0){
        printf("\nError: Wrong arguments.\n");
        exit(0);
    }


    byte WAVheaderInput[45],WAVheaderMono[45],WAVheaderCrop[45];    //byte tyoe declaration strings

    fpInput=fopen(argv[2],"rb");    //open file only to read bytes
    if (fpInput==NULL){
        printf("\nError: File can not be loaded.\n");
        exit(1);
    }
    else{
        fread (WAVheaderInput,sizeof(byte),45,fpInput);
        WAVheaderInput[45]='\0';
    }

    fclose(fpInput);        //file close

    /*Take data of WAV*/
    for(i=0;i<4;i++)
        ChunkID[i]=WAVheaderInput[i];
    ChunkID[4]='\0';
    ChunkSize=LittleToBigToDec(WAVheaderInput,4,7);
    for(i=0;i<4;i++)
        Format[i]=WAVheaderInput[8+i];
    Format[4]='\0';
    for(i=0;i<4;i++)
        Subchunk1ID[i]=WAVheaderInput[12+i];
    Subchunk1ID[3]='\0';
    Subchunk1Size=LittleToBigToDec(WAVheaderInput,16,19);
    AudioFormat=LittleToBigToDec(WAVheaderInput,20,21);
    NumChannels=LittleToBigToDec(WAVheaderInput,22,23);
    SampleRate=LittleToBigToDec(WAVheaderInput,24,27);
    ByteRate=LittleToBigToDec(WAVheaderInput,28,31);
    BlockAlign=LittleToBigToDec(WAVheaderInput,32,33);
    BitsPerSample=LittleToBigToDec(WAVheaderInput,34,35);
    for(i=0;i<4;i++)
        Subchunk2ID[i]=WAVheaderInput[36+i];
    Subchunk2ID[4]='\0';
    Subchunk2Size=LittleToBigToDec(WAVheaderInput,40,43);


    if (!((!strcmp("RIFF",ChunkID)) && (!strcmp("WAVE",Format)) && (!strcmp("fmt",Subchunk1ID)) && (!strcmp("data",Subchunk2ID)) && (AudioFormat==1))){ // If input is WAV  show the Header List.
        // Informs the user that gave the wrong audio format.
        printf("\nError: Format of input isn't WAV.\n");
        exit(0);
    }
    if (ChoiseFlag==1)  // -list Function.
        headerList(ChunkSize,Subchunk1Size,AudioFormat, NumChannels, SampleRate, ByteRate, BlockAlign, BitsPerSample, Subchunk2Size, ChunkID, Format, Subchunk1ID, Subchunk2ID);


    if (ChoiseFlag==2){//-reverse Function.
        reverse(WAVheaderInput,ChunkSize,argv[2],argv[3]);
    }

    if (ChoiseFlag==3){// -mono Function.
        if (NumChannels==1){
            printf("\nError: The input WAV is already in Mono mode.\n");
        }
        else{
            for(i=0;i<45;i++)                                               //Copy Input Header to Mono Header.
                WAVheaderMono[i]=WAVheaderInput[i];

            DecToLittle (WAVheaderMono,((Subchunk2Size/2)+36),4,7);         // Change/Overwrite mono_ChunkSize is size of Left or Right Channel plus 36.
            DecToLittle (WAVheaderMono,1,22,23);                            // Change/Overwrite Number of Channels to '1' because want only one Channel (Left or Right).
            DecToLittle (WAVheaderMono,(ByteRate/2),28,31);                 // Change/Overwrite ByteRate because ByteRate== SampleRate * NumChannels * BitsPerSample/8
            DecToLittle (WAVheaderMono,(BlockAlign/2),32,33);               // Change/Overwrite BlockAlign because BlockAlign==NumChannels * BitsPerSample/8.
            DecToLittle (WAVheaderMono,(Subchunk2Size/2),40 ,43);           // Change/Overwrite mono_Subchunk2Size is size of Left or Right Channel.

            mono(WAVheaderMono,(Subchunk2Size+44),argv[2],argv[3]);
        }
    }

    if (ChoiseFlag==4){ // -crop Function.
        totalTime=Subchunk2Size/((SampleRate*BitsPerSample*NumChannels)/8);

        int p=1;       // Check user times
        for (i=(strlen(argv[3])-1);i>=0;i--){       //check if user game somthing other than just numbers
            if ((argv[3][i]<'0') || (argv[3][i]>'9')){
                printf("\nError: Wrong arguments.\n");
                exit(0);
            }
            tStart+=(argv[3][i]-'0')*p;
            p=p*10;
        }

        p=1;
       for (i=(strlen(argv[4])-1);i>=0;i--){
            if ((argv[4][i]<'0') || (argv[4][i]>'9')){
                printf("\nError: Wrong arguments.\n");
                exit(0);
            }
            tEnd+=(argv[4][i]-'0')*p;
            p=p*10;
        }


        for(i=0;i<45;i++)                                               //Copy Input Header to Crop Header.
            WAVheaderCrop[i]=WAVheaderInput[i];

        DecToLittle(WAVheaderCrop,((tEnd-tStart)*((SampleRate*BitsPerSample*NumChannels)/8))+36,4,7); // crop_ChunkSize
        DecToLittle(WAVheaderCrop,(tEnd-tStart)*((SampleRate*BitsPerSample*NumChannels)/8),40,43); // crop_Subchunk2Size

        if((tStart<totalTime)&&(tEnd<=totalTime))
             crop(WAVheaderCrop,(tEnd-tStart)*((SampleRate*BitsPerSample*NumChannels)/8),argv[2],argv[5],SampleRate,NumChannels,BitsPerSample,tStart,tEnd);
        else
            printf("\nError: Time is out of limit.\n");

    }

return 0;
}
