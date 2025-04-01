/*  
Program Number: 19  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 21/02/2025  
Description: This program creates a child process that goes through running,  
sleeping, and stopped states. The parent process monitors the child.
*/  
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <signal.h>  
int main() {  
    int pid = fork();  
    if (pid < 0) {  
        perror("Fork failed");  
        return 1;  
    }  
    if (pid == 0) {  
        printf("Child process (PID %d) is RUNNING.\n", getpid());  
        sleep(2);  
        printf("Child process (PID %d) is now in SLEEPING state (2 sec).\n", getpid());  
        sleep(2);  
        printf("Child process (PID %d) is exiting.\n", getpid());  
    } else {  
        sleep(1);  
        printf("Parent process (PID %d) will STOP the child (PID %d).\n", getpid(), pid);  
        kill(pid, SIGSTOP);  
        printf("Child process (PID %d) is now STOPPED.\n", pid);  
        sleep(2);  
        printf("Parent process will now CONTINUE the child (PID %d).\n", pid);  
        kill(pid, SIGCONT);  
        wait(NULL);  
        printf("Child process has finished execution.\n");  
    }  
    return 0;  
}
