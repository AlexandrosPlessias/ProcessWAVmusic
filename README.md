# ProcessWAVmusic
* By opening the WAV (input.wav) uncompressed audio file, we make sure to copy the contents of the header (first 44 bytes) to a 45-position bytes table. Then we convert the contents to the corresponding audio file data as shown below. Once the appropriate checks have been made (that the file is WAV type) we are ready to run the program.

* Function -list (export information)
The -list function is for printing the header data of a specified audio file in the form below. These data are derived from the LittleToBigToDec function which converts the little endian data to the numbers described in the header to decimal. It is worth noting that the variables related to the header are unsigned int so that they are able to fit more data. Here is an example of how to execute the function of extracting information from an audio file (piano2.wav from WAVexamples):

 * Reverse mode (audio file reversal)
The -reverse command reverses the data of an audio file (makes the file sound from the end to the beginning). This function copies the input.wav header to the new file. Then the input.wav file runs from the end to the header that you find at the beginning and copies every 4 bytes, ie every 1 sample in the new file (for example in a file with n samples the 1st takes the place of n and vice versa, the 2nd place of n-1 and so on). The result is the creation of a new audio file with inverted content. Here is the code that performs this process.

* Operation –mono (conversion from stereo to monophonic)
The -mono function converts the audio file from stereo (existence of 2 channels) to monophonic (existence of only 1 channel). This can be done by selecting a channel (right or left). In this work we chose the left channel, since the right channel is the most familiar to the human ear and the difference would not be noticed. Great care (after checking if the stereo file) we had to give the values ​​that change from the original format of the header (input.wav) which are: ChunkSize, NumChannels, ByteRate, BlockAlign, Subchunk2Size, which change after changing it file size and samples and are passed to the new header with the DecToLittle function. The mono function changes the details of the new audio file (which are described in the header) and then reads from the input file every 4 and we keep the first 2 of each sample.

* Operation –crop (audio track output)
The -crop function cuts one audio file from one time to another. Quite important is the formula (SampleRate × BitsPerSample × NumChannels) ÷ 8 where it gives us how many bytes it has in a second and here we change ChunkSize and Subchunk2Size using the DecToLittle function. After we have first checked that the 2 moments that the user has given are less than the duration of the piece. In the crop function we first find the bytes of the first time given by the user and then we find the bytes of the second. Then within a repeat loop (from bytesStart to bytesEnd we copy the bytes 1-1, as shown below:
Structure
        
* LittleToBigToDec function
It converts from the header what is in little endian to decimal numbers. As headers it takes the header and the start and end positions that we want to convert. Its operation is explained in the comments

* DecToLittle function
It converts data from the decimal system to big endian and then to small endian. As headings, the header takes the value of the decimal you want to convert and the start and end positions to which we want to store it. Its operation is explained in the comments

