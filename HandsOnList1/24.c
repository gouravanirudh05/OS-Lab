/*  
Program Number: 24  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 21/02/2025  
Description: This  a program to create three child 
processes. The parent process should wait for a specific child process using the 
waitpid system call.  
*/  

#include <stdio.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <stdlib.h>
int main() {
    int pid1 = fork();
    int pid2 = fork();
    int pid3 = fork();
    if (pid1 > 0) {
        waitpid(pid1, NULL, 0);
        printf("Parent waited for child %d\n", pid1);
    }
    return 0;
}
