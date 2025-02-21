/* 
Program Number: 12
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date: 21/02/2025  
Description: This program determines the opening mode of a file using fcntl.
*/ 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("file_12.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl failed");
        return 1;
    }

    printf("File opening mode: ");
    if (flags & O_RDONLY)
    printf("Read Only\n");
    if (flags & O_WRONLY) 
    printf("Write Only\n");
    if (flags & O_RDWR)   
    printf("Read and Write\n");
    close(fd);
    return 0;
}
