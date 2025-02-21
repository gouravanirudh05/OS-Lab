/*  
Program Number: 20  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 21/02/2025  
Description: This program prints the parent and child process IDs using fork.
*/  

#include <stdio.h>  
#include <unistd.h>  

int main() {  
    pid_t pid = fork();  
    if (pid == 0)  
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());  
    else  
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);  
    return 0;  
}
