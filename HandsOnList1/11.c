/* 
Program Number: 11
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date: 21/02/2025  
Description: This program demonstrates file descriptor duplication and appending using dup, dup2, and fcntl. 
*/ 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("appendfile.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    
    int fd_dup = dup(fd);
    int fd_dup2 = dup2(fd, 10);
    int fd_fcntl = fcntl(fd, F_DUPFD, 0);
    
    write(fd, "Original FD\n", 12);
    write(fd_dup, "Dup FD\n", 8);
    write(fd_dup2, "Dup2 FD\n", 9);
    write(fd_fcntl, "Fcntl FD\n", 10);
    
    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);
    return 0;
}