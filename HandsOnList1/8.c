/* 
Program Number: 8
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date: 15/02/2025  
Description: This program creates a file, writes some content to it, and then reads it line by line. 
*/ 
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    
    FILE *file = fopen("file_8.txt", "w");
    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }
    fprintf(file, "Hello, this is a test file.\nThis is the second line.\n");
    fclose(file);
    
    file = fopen("file_8.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
    return 0;
}