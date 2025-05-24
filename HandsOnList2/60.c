/*
Program Number: 60
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 11/05/2025
Description: This is a program to ignore a SIGINT signal and
then reset it to the default action using the signal system call.
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    void (*original_handler)(int);

    printf("Setting custom SIGINT handler...\n");
    signal(SIGINT, SIG_IGN); // Ignore SIGINT
    printf("SIGINT is now being ignored. Try pressing Ctrl+C...\n");
    sleep(5);

    // Restore default signal handler
    printf("\nRestoring default SIGINT behavior...\n");
    signal(SIGINT, SIG_DFL);

    printf("Default SIGINT behavior restored. Press Ctrl+C again to terminate the program.\n");
    sleep(10); 

    printf("No SIGINT received. Exiting normally.\n");
    return 0;
}
