/*
Program Number: 59f
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program catches the SIGVTALRM signal using the setitimer system call with ITIMER_VIRTUAL.
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void handle_sigvtalrm(int sig)
{
    printf("Caught SIGVTALRM: Virtual timer expired!\n");
}

int main()
{
    signal(SIGVTALRM, handle_sigvtalrm);

    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1)
    {
        // This consumes CPU and thus counts as virtual time
    }

    return 0;
}
