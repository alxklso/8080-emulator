#include <stdlib.h>
#include <stdio.h>

/* DRIVER CODE */
int main(int argc, char**argv) 
{
    
    // File handling 
    char filePath[] = "../files/invaders.h"; 
    FILE *filePointer = fopen(filePath, "rb");

    if (filePointer == NULL) 
    {
        printf("ERROR: %s could not be opened.\n", filePath);
        exit(1);
    } 

    // Read file contents into buffer 
    fseek(filePointer, 0L, SEEK_END); // Place pointer at end of file 
    int fileSize = ftell(filePointer); // Get the location of the pointer (at the end)
    fseek(filePointer, 0L, SEEK_SET); // Place pointer back at start of file 

    printf("SUCCESS: %s could be opened (size: %d bytes).\n", filePath, fileSize);
    
    // Create buffer and load file data into it
    unsigned char *buffer = malloc(fileSize);
    printf("Buffer created\n");
    fread(buffer, fileSize, 1, filePointer);
    fclose(filePointer);

    int programCounter = 0;
    while (programCounter < fileSize) 
    {
        programCounter += disassembler(buffer, programCounter);
    }

    printf("Done.\n");
 
    exit(1);
}