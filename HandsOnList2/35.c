/*    Program Number: 34c
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date:14/04/2025
Description:This is a program to find out total number of directories on the pwd executing ls -l | grep ^d | wc  using only dup2.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include<fcntl.h>
int main(){
    int fd1[2];
    int fd2[2];
    pipe(fd1);pipe(fd2);
    int pid = fork();
    if(pid==0){
        close(1);
        close(fd1[0]);
        dup2(fd1[1],1);
        execl("ls","ls","-l",(char*)NULL); 
        return 0 ;
    } 
    else{
        if(!fork()){
            close(fd1[1]);
            close(fd2[0]);
            close(0);
            dup2(fd1[0],0);
            close(1);
            dup2(fd2[1],1);
            wait(NULL);
            execl("grep","grep","^d",(char*)NULL);
            return 0 ; 
        }
        else{
            close(fd2[1]);
            close(0);
            dup2(fd2[0],0);
            execlp("wc","wc",(char*)NULL);
        }
    }
    return 0 ; 
}