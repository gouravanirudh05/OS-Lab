
/*
Program Number: 61a
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 11/05/2025
Description: This is a program to catch SIGSEGV using sigaction system call
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigsegv(int signum)
{
    printf("Caught SIGSEGV (Segmentation Fault).Signal number: %d\n", signum);
    exit(1);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = handle_sigsegv;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGSEGV, &sa, NULL);

    printf("Causing segmentation fault...\n");
    int *ptr = NULL;
    *ptr = 42; // Causes SIGSEGV

    return 0;
}
