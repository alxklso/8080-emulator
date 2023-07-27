#include <stdlib.h>
#include <stdio.h>

int main(int argc, char**argv) {
    
    // File handling 
    char file_path[] = "../files/invaders.h"; 
    FILE *file_pointer = fopen(file_path, "r");

    if (file_pointer == NULL) {
        printf("ERROR: %s could not be opened.\n", file_path);
        exit(1);
    } 

    // Read file contents into buffer 
    fseek(file_pointer, 0L, SEEK_END); // Place pointer at end of file 
    int file_size = ftell(file_pointer); // Get the location of the pointer (at the end)
    fseek(file_pointer, 0L, SEEK_SET); // Place pointer back at start of file 

    printf("SUCCESS: %s could be opened (size: %d bytes).\n", file_path, file_size);
 
 
    exit(1);
}