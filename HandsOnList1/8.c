/*  
Program Number: 8  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 15/02/2025  
Description: This program creates a file, writes some content to it, and then reads it line by line using system calls.  
*/  

#include <stdio.h>  
#include <stdlib.h>  
#include <fcntl.h>  
#include <unistd.h>  
#include <string.h>  

int main() {  
    int fd;  
    char *filename = "file_8.txt";  
    char *content = "Hello, this is a test file.\nThis is the second line.\n";  

    // Creating and writing to the file  
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);  
    if (fd == -1) {  
        perror("Error creating file");  
        return 1;  
    }  

    if (write(fd, content, strlen(content)) == -1) {  
        perror("Error writing to file");  
        close(fd);  
        return 1;  
    }  
    close(fd);  

    // Reading the file  
    fd = open(filename, O_RDONLY);  
    if (fd == -1) {  
        perror("Error opening file");  
        return 1;  
    }  

    char buffer[256];  
    int  countOfBytes;  
    while ((countOfBytes = read(fd, buffer, sizeof(buffer) - 1)) > 0) {  
        buffer[countOfBytes] = '\0';   
        printf("%s", buffer);  
    }  

    if (countOfBytes == -1) {  
        perror("Error reading file");  
    }  

    close(fd);  
    return 0;  
}  
