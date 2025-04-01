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

    int i,j,k;
    if(!(i=fork()))
    {
        sleep(1);
    }
    else 
    {
        if((!(j=fork())))
        {
            sleep(3);
        }
        else 
        {
            if(!(k=fork()))
            {
                sleep(10);
            }
            else 
            {
                waitpid(k,NULL,0);
            }
        }
    }
}
