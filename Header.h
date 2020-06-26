typedef unsigned char byte;     // byte struct declaration

/*----------------------------Functions declaration----------------------------*/

void textArt ();
unsigned int LittleToBigToDec (byte WAVheaderInput[], int start ,int end);
unsigned int DecToLittle (byte WAVheader[],int value, int start ,int end);
void headerList(unsigned int ChunkSize,unsigned int Subchunk1Size,unsigned int AudioFormat, unsigned int NumChannels, unsigned int SampleRate, unsigned int ByteRate, unsigned int BlockAlign, unsigned int BitsPerSample, unsigned int Subchunk2Size, char ChunkID[], char Format[], char Subchunk1ID[], char Subchunk2ID[]);
void reverse(byte WAVheaderInput[],unsigned int ChunkSize, char nameInput[], char nameOutput[]);
void mono(byte WAVheaderMono[],unsigned int Subchunk2Size, char nameInput[],char nameOutput[]);
void crop(byte WAVheaderCrop[],unsigned int Subchunk2Size, char nameInput[],char nameOutput[], unsigned int SampleRate, unsigned int NumChannels, unsigned int BitsPerSample,int tStart, int tEnd);

