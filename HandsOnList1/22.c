/*  
Program Number: 22  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 21/02/2025  
Description: This program creates a zombie state and detects it within the program itself.  
*/  
#include <stdio.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <sys/wait.h>  
#include <stdlib.h>  
#include <string.h>
void check_zombie(pid_t child_pid) {
    char path[40], status[256];
    FILE *fp;
    snprintf(path, sizeof(path), "/proc/%d/status", child_pid);
    sleep(2);  
    fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Error opening status file");
        return;
    }
    while (fgets(status, sizeof(status), fp)) {
        if (strncmp(status, "State:", 6) == 0) {  
            printf("Child process status: %s", status);
            break;
        }
    }
    fclose(fp);
}
int main() {
    pid_t pid = fork();
    if (pid == 0) {  
        printf("Child process (PID: %d) exiting...\n", getpid());
        _exit(0);  
    } else {  
        printf("Parent process (PID: %d) created child (PID: %d).\n", getpid(), pid);
        printf("Parent sleeping for 10 seconds to keep child in zombie state...\n");
        check_zombie(pid);  
        sleep(10);  
        printf("Parent exiting. Zombie process will be cleaned up.\n");
    }
    return 0;
}
