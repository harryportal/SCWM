#include <stdio.h>
#include <stdlib.h>
#include "filemanip.h"

#define MAX_STRLEN 258


// check command arguments 
void checkCommand(int argc, char **argv){
    if(argc < 2){
        printf("Not enough arguments, program: %s", argv[0]);
        exit(EXIT_FAILURE);
    }
}
// a simple program to add words to a program and 
// display the words after

void writeAndReadFile(const char *filename){
    /* A file pointer that points to a data object containing
    information about the file*/
    FILE * fp; 
    const int wordsize = 40;
    char word[wordsize];

    // tries to open file: blows powder
    if((fp = fopen(filename, "a+")) == NULL){
        fprintf(stdout, "Failed to open file. Filename: %s", filename);
        exit(EXIT_FAILURE);
    }

    // read from the user word by word and add the word to the file
    puts("Please enter a word to be added to the file. \n");
    puts("Enter \"#\" to quit.\n");
    while(scanf(word, "%40s") == 1 && word[0] != '#'){
        fprintf(fp, "%s\n", word);
    }

    // move to the beginning of the file
    rewind(fp);

    while(fscanf(fp, "%s", word) == 1){
        puts(word);
    }

    puts("Done!");
    if(fclose(fp) != 0){
        fprintf(stderr, "Error closing file.");
    }
}

/*
A simple variation of the function above, except now it reads
per line not per word. For the limit to the line input, let's set a 
reasonable STR_LEN for 258( assuming the terminal cannot text per line up to this ).
*/
void WriteLinesToFile(const char *filename){
    FILE *fp;
    char line[MAX_STRLEN];
    // try to open the file
    if( (fp = fopen(filename, "a+")) == NULL ) {
        printf("Unable to read file, filename: %s", filename);
        exit(EXIT_FAILURE);
    }

    // get user to write something 
    puts("Enter a story or whatever to insert into the file:");
    puts("Enter full stop on a new line to end the statement.");
    while ( fgets(line, MAX_STRLEN, stdin) != NULL && line[0] != '.' ){
        fputs(line, fp);
    }

    if (fclose(fp) != 0){
        printf("Unable to close file, filename: %s", line);
        exit(EXIT_FAILURE);
    }

}
