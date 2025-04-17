/*    Program Number: 40
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date:14/04/2025
Description: This is a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
*/
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
    int pd[2];
    pipe(pd);
    int pipe_size = fcntl(pd[0],F_GETPIPE_SZ);
    printf("pipe size = %d\n",pipe_size);
    printf("max numbers of open fds = %d\n",FOPEN_MAX);
    return 0;
}