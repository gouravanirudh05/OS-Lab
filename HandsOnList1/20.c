/*  
Program Number: 20  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 21/02/2025  
Description: This program prints the parent and child process IDs using fork.
*/  

#include <stdio.h>  
#include <unistd.h>  

int main() {  
    int pid = fork();  
    if (pid == 0)  
        printf("Child Process: PID = %d\n", getpid());  
    else  
        printf("Parent Process: PID = %d\n",getpid());  
    return 0;  
}
