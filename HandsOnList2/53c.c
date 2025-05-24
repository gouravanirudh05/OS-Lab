/*
Program Number: 53c
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program sets an interval timer using ITIMER_PROF,
which delivers SIGPROF after 10 seconds and 10 microseconds of combined user+system time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void prof_handler(int signum)
{
    printf("ITIMER_PROF: SIGPROF triggered!\n");
    exit(0);
}

int main()
{
    struct itimerval timer;
    signal(SIGPROF, prof_handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_PROF, &timer, NULL) == -1)
    {
        perror("setitimer");
        exit(1);
    }

    printf("Generating CPU + system activity for SIGPROF...\n");
    while (1)
        ; // Keep CPU active
}
