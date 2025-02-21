/* 
Program Number: 10
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date: 15/02/2025  
Description: This program opens a file, writes 10 bytes, moves the file pointer, and writes another 10 bytes. 
*/ 
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("seekfile.txt", "w+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    fprintf(file, "ABCDEFGHIJ");
    fseek(file, 10, SEEK_CUR);
    fprintf(file, "1234567890");
    fclose(file);
    return 0;
}