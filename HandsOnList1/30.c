/*  
Program Number: 30  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 31/03/2025  
Description: Daemon Process
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
    int pid = fork();
    if(pid == 0){
        // Child process
        setsid();
        chdir("/");
        umask(0);
        while(1){
            printf("Hello this is a daemon process\n");
            sleep(10);
        }
        
    }
    else{
        // Parent process
        exit(0);
    }
    return 0;
}
