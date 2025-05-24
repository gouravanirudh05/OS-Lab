/*
Program Number: 59c
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program catches the SIGFPE (Floating Point Exception) signal using the signal system call.
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigfpe(int sig)
{
    printf("Caught SIGFPE: Division by zero!\n");
    exit(1);
}

int main()
{
    signal(SIGFPE, handle_sigfpe);
    int a = 5, b = 0;
    int c = a / b; // Triggers SIGFPE
    printf("Result: %d\n", c);
    return 0;
}
