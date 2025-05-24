/*
Program Number: 59b
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program catches the SIGINT (Interrupt from keyboard) signal using the signal system call.
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig)
{
    printf("\nCaught SIGINT: You pressed Ctrl+C!\n");
}

int main()
{
    signal(SIGINT, handle_sigint);
    while (1)
    {
        printf("Running... Press Ctrl+C to trigger SIGINT\n");
        sleep(2);
    }
    return 0;
}
