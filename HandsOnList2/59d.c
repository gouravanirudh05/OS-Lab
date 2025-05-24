/*
Program Number: 59d
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program catches the SIGALRM signal using the alarm system call and the signal system call.
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigalrm(int sig)
{
    printf("Caught SIGALRM: alarm() expired!\n");
}

int main()
{
    signal(SIGALRM, handle_sigalrm);
    alarm(3); // Triggers SIGALRM after 3 seconds
    printf("Waiting for alarm...\n");
    pause(); // Wait for signal
    return 0;
}
