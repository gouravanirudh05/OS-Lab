/*
Program Number: 62
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 11/05/2025
Description: This is a program to ignore a SIGINT signal and
then reset it to the default action using the sigaction system call.
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum)
{
    printf("\nSIGINT received\n");
    exit(0);
}

int main()
{
    struct sigaction s;
    s.sa_handler = SIG_IGN;
    if (sigaction(SIGINT, &s, NULL) == -1)
    {
        perror("sigaction");
        exit(1);
    }
    printf("Ignoring SIGINT...\n");
    sleep(5);
    s.sa_handler = sigint_handler;
    if (sigaction(SIGINT, &s, NULL) == -1)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    printf("\nResetting SIGINT to default action...\n");
    printf("Sending SIGINT to the process again...\n");
    sleep(5);
    return 0;
}
