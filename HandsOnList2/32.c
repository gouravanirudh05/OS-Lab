/*    Program Number: 32
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date:14/04/2025
Description: This is a program to send some data from parent to the child process
*/
#include<stdio.h>
#include <unistd.h>

int main(){
    int fd[2];
    pipe(fd);
    int id = fork();
    if(id==0){
        
        close(fd[1]);
        char buffer[13];
        read(fd[0],buffer,13);
        printf("%s",buffer);

    }
    else{
        close(fd[0]);
        write(fd[1],"Hello World\n",13);

    }
    return 0 ;
}