/*  
Program Number: 23  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 21/02/2025  
Description: This program creates an orphan process and shows that its parent is changed.  
*/  

#include <stdio.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <stdlib.h>
int main() {
    int pid = fork();
    if (pid > 0) {  
        printf("Parent (PID: %d) created child (PID: %d).\n", getpid(), pid);
        printf("Parent exiting, leaving orphan child...\n");
        exit(0);  
    } else {  
        printf("Orphan child (PID: %d) has initial parent (PID: %d).\n", getpid(), getppid());
        sleep(5);  
        printf("Orphan child (PID: %d) now has new parent (PID: %d).\n", getpid(), getppid());
    }
    return 0;
}