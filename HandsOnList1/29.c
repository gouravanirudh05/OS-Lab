/*  
Program Number: 29  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 31/03/2025  
Description: Get and modify the scheduling policy of the process  
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

void print_policy(int policy) {
    if (policy == SCHED_FIFO)
        printf("Current scheduling policy: FIFO\n");
    else if (policy == SCHED_RR)
        printf("Current scheduling policy: RR\n");
    else
        printf("Current scheduling policy: OTHER\n");
}

int main() {
    int policy;
    struct sched_param param;

    // Get the current scheduling policy
    policy = sched_getscheduler(0);
    print_policy(policy);

    // Set scheduling priority
    param.sched_priority = 50;

    // Change to SCHED_FIFO
    if (sched_setscheduler(0, SCHED_FIFO, &param) == 0)
        printf("New scheduling policy: FIFO\n");
    else
        perror("Failed to set SCHED_FIFO");

    // Change to SCHED_RR
    if (sched_setscheduler(0, SCHED_RR, &param) == 0)
        printf("New scheduling policy: RR\n");
    else
        perror("Failed to set SCHED_RR");

    return 0;
}
