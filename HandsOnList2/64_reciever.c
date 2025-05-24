/*
Program Number: 64_reciever
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 11/05/2025
Description: This is a program to create the program awaits the
SIGSTOP signal
*/

#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("The PID is %d\n", getpid());
    printf("Waiting for SIGSTOP...\n");
    while (1);
    return 0;
}