/* 
Program Number: 7
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date: 15/02/2025  
Description: This program creates two new files, writes data into them, and then copies file1 into file2 manually using fprintf and fscanf. 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file1 = fopen("file1.txt", "w");
    FILE *file2 = fopen("file2.txt", "w");
    if (file1 == NULL || file2 == NULL) {
        fprintf(stderr, "Error creating files\n");
        return 1;
    }
    fprintf(file1, "Hello, this is file1.\nThis is a test line.\n");
    fclose(file1);
    fclose(file2);
    // Open file1 for reading and file2 for writing
    file1 = fopen("file1.txt", "r");
    file2 = fopen("file2.txt", "w");
    if (file1 == NULL || file2 == NULL) {
        fprintf(stderr, "Error opening files for copying\n");
        return 1;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file1) != NULL) {
        fputs(buffer, file2);
    }
    fclose(file1);
    fclose(file2);
    printf("Copied file1.txt to file2.txt successfully\n");
    return 0;
}
