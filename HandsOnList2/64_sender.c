/*
Program Number: 64_sender
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 11/05/2025
Description: This is a program to create thw second program sends the signal using the kill system call.

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int pid = atoi(argv[1]);
    if (kill(pid, SIGSTOP) == -1)
    {
        perror("kill");
        exit(EXIT_FAILURE);
    }
    printf("Sent SIGSTOP signal to process with PID %d\n", pid);
    return 0;
}
