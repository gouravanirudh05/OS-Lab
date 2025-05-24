/*
Program Number: 61c
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 11/05/2025
Description: This is a program to catch SIGFPE using sigaction system call
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void handle_sigfpe(int signum)
{
    printf("Caught SIGFPE (Floating Point Exception).Signal number: %d\n", signum);
    exit(1);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = handle_sigfpe;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGFPE, &sa, NULL);

    printf("Causing divide by zero...\n");
    int a = 5;
    int b = 0;
    int c = a / b; // Causes SIGFPE
    printf("Result: %d\n", c);

    return 0;
}
