/*  
Program Number: 21  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 21/02/2025  
Description: This program demonstrates writing to a file by both parent and child processes and displaying its content.
*/  
#include <stdio.h>  
#include <unistd.h>  
#include <fcntl.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <string.h>  
int main() {  
    int fd = open("file_21.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);  
    if (fd == -1) {  
        perror("Error opening file");  
        return 1;  
    }  
    pid_t pid = fork();  
    if (pid == 0) {  
        char child_msg[] = "Hello from child!\n";
        write(fd, child_msg, strlen(child_msg));  
    } else {  
        char parent_msg[] = "Hello from parent!\n";
        write(fd, parent_msg, strlen(parent_msg));  
    }  
    close(fd);  
    fd = open("file_21.txt", O_RDONLY);  
    if (fd == -1) {  
        perror("Error opening file for reading");  
        return 1;  
    }  
    char buffer[1024];  
    ssize_t bytesRead;  
    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {  
        buffer[bytesRead] = '\0';  
        printf("%s", buffer);  
    }  
    close(fd);  
    return 0;  
}
