/*
Program Number: 53b
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program sets an interval timer using ITIMER_VIRTUAL,
which delivers SIGVTALRM after 10 seconds and 10 microseconds of process CPU time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void vtalrm_handler(int signum)
{
    printf("ITIMER_VIRTUAL: SIGVTALRM triggered!\n");
    exit(0);
}

int main()
{
    struct itimerval timer;
    signal(SIGVTALRM, vtalrm_handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1)
    {
        perror("setitimer");
        exit(1);
    }

    printf("Consuming CPU time to trigger SIGVTALRM...\n");
    while (1); 
}
