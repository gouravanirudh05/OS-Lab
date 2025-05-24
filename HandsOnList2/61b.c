/*
Program Number: 61b
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 11/05/2025
Description: This is a program to catch SIGINT using sigaction system call
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void handle_sigint(int signum)
{
    printf("Caught SIGINT (Interrupt).Signal number: %d\n", signum);
    exit(0);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    printf("Press Ctrl+C to trigger SIGINT...\n");
    while (1)
    {
        printf("Running... Press Ctrl+C to exit.\n");
        sleep(1);
    }

    return 0;
}
