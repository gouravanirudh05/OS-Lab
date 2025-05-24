/*
Program Number: 59g
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program catches the SIGPROF signal using the setitimer system call with ITIMER_PROF.
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void handle_sigprof(int sig)
{
    printf("Caught SIGPROF: Profiling timer expired!\n");
}

int main()
{
    signal(SIGPROF, handle_sigprof);

    struct itimerval timer;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1)
    {
        // This uses both system + user time (counts toward profiling)
    }

    return 0;
}
