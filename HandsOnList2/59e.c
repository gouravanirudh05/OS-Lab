/*
Program Number: 59e
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program catches the SIGALRM signal using the setitimer system call.
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_sigalrm(int sig)
{
    printf("Caught SIGALRM: Timer expired (setitimer)!\n");
}

int main()
{
    signal(SIGALRM, handle_sigalrm);

    struct itimerval timer;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);
    printf("Waiting for timer...\n");
    pause();
    return 0;
}
