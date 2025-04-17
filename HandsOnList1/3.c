/* 
Program Number: 3
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date:15/02/2025  
Description: This program will create a file and 
prints its file descriptor value using the creat() system call. 
*/ 
#include <fcntl.h>
#include <stdio.h>
int main() {
    // Hardcoded filename
    char filename[] = "output.txt";
    // Create the file with read,write and execute permissions for all users
    int fd = creat(filename, 0777);
    if (fd == -1) {
        perror("create failed");
        return 1;
    }
    // Print the file descriptor value
    printf("File %s created with fd = %d\n", filename, fd);
    return 0;
}