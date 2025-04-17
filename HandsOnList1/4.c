/* 
Program Number: 4
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date:15/02/2025  
Description: This program is to open an existing file in read-write mode. 
Experiment with the O_EXCL flag. 
 
*/ 
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char filename[] = "file_4.txt";
    int fd = open(filename, O_RDWR | O_CREAT | O_EXCL, 0777);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    printf("File %s opened successfully with fd = %d\n", filename, fd);
    close(fd);  // Close the file descriptor
    return 0;
}