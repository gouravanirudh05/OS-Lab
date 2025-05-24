/*
Program Number: 59a
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program catches the SIGSEGV (Segmentation Fault) signal using the signal system call.
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigsegv(int sig)
{
    printf("Caught SIGSEGV: Segmentation fault occurred!\n");
    exit(1);
}

int main()
{
    signal(SIGSEGV, handle_sigsegv);
    int *ptr = NULL;
    *ptr = 10; // Triggers SIGSEGV
    return 0;
}
