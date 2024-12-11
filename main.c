#include "filemanip.h"

/* 
Communicating with files using the C libaries.
Files are veiwed as a continuous sequence of bytes.
Input and outputs are ussually transfered 512bytes at a time ( more like 
a buffer system )
*/
int main (int argc, char *argv[]){
    checkCommand(argc, argv);
    //writeAndReadFile(argv[1]);
    WriteLinesToFile(argv[1]);
    return 0;
}