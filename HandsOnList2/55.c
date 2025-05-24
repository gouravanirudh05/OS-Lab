/*
Program Number: 55
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program  to set a system resource limit
using the setrlimit system call.
*/
#include <stdio.h>
#include <sys/resource.h>

void setResourceLimit(int resource, rlim_t soft_limit, rlim_t hard_limit)
{
    struct rlimit s;
    s.rlim_cur = soft_limit;
    s.rlim_max = hard_limit;
    if (setrlimit(resource, &s) != 0)
    {
        perror("setrlimit");
    }
    else
    {
        printf("Resource limit for ");
        switch (resource)
        {

        case RLIMIT_FSIZE:
            printf("File Size");
            break;
        case RLIMIT_SIGPENDING:
            printf("Pending Signals");
            break;
        case RLIMIT_MEMLOCK:
            printf("Max Locked Memory");
            break;
        case RLIMIT_CORE:
            printf("Core File Size");
            break;
        case RLIMIT_DATA:
            printf("Data Size");
            break;
        case RLIMIT_NICE:
            printf("Nice Priority");
            break;
        case RLIMIT_MSGQUEUE:
            printf("Message Queue");
            break;

        case RLIMIT_NPROC:
            printf("Max User Processes");
            break;
        case RLIMIT_AS:
            printf("Virtual Memory");
            break;
        case RLIMIT_LOCKS:
            printf("File Locks");
            break;
        case RLIMIT_RTPRIO:
            printf("Real-Time Priority");
            break;
        case RLIMIT_STACK:
            printf("Stack Size");
            break;
        case RLIMIT_RTTIME:
            printf("CPU Time");
            break;
        }
        printf("Set successfully.\n");
    }
}

void getResourceLimit(int resource)
{
    struct rlimit s;
    switch (resource)
    {
    case RLIMIT_CORE:
        getrlimit(RLIMIT_CORE, &s);
        printf("Core File Size (soft limit): %10lu (hard limit): %lu\n", s.rlim_cur, s.rlim_max);
        break;
    case RLIMIT_DATA:
        getrlimit(RLIMIT_DATA, &s);
        printf("Data Size (soft limit): %10lu (hard limit): %lu\n", s.rlim_cur, s.rlim_max);
        break;
    case RLIMIT_NICE:
        getrlimit(RLIMIT_NICE, &s);
        printf("Nice Priority (soft limit): %10lu (hard limit): %lu\n", s.rlim_cur, s.rlim_max);
        break;
    case RLIMIT_FSIZE:
        getrlimit(RLIMIT_FSIZE, &s);
        printf("File Size (soft limit): %10lu (hard limit): %lu\n", s.rlim_cur, s.rlim_max);
        break;
    case RLIMIT_SIGPENDING:
        getrlimit(RLIMIT_SIGPENDING, &s);
        printf("Pending Signals (soft limit): %10lu (hard limit): %lu\n", s.rlim_cur, s.rlim_max);
        break;
    case RLIMIT_MEMLOCK:
        getrlimit(RLIMIT_MEMLOCK, &s);
        printf("Max Locked Memory (soft limit): %10lu (hard limit): %lu\n", s.rlim_cur, s.rlim_max);
        break;
    case RLIMIT_MSGQUEUE:
        getrlimit(RLIMIT_MSGQUEUE, &s);
        printf("Message Queue (soft limit): %10lu (hard limit): %lu\n", s.rlim_cur, s.rlim_max);
        break;
    case RLIMIT_RTPRIO:
        getrlimit(RLIMIT_RTPRIO, &s);
        printf("Real-Time Priority (soft limit): %10lu (hard limit): %lu\n", s.rlim_cur, s.rlim_max);
        break;
    case RLIMIT_STACK:
        getrlimit(RLIMIT_STACK, &s);
        printf("Stack Size (soft limit): %10lu (hard limit): %lu\n", s.rlim_cur, s.rlim_max);
        break;
    case RLIMIT_RTTIME:
        getrlimit(RLIMIT_RTTIME, &s);
        printf("CPU Time (soft limit): %10lu (hard limit): %lu\n", s.rlim_cur, s.rlim_max);
        break;
    case RLIMIT_NPROC:
        getrlimit(RLIMIT_NPROC, &s);
        printf("Max User Processes (soft limit): %10lu (hard limit): %lu\n", s.rlim_cur, s.rlim_max);
        break;
    case RLIMIT_AS:
        getrlimit(RLIMIT_AS, &s);
        printf("Virtual Memory (soft limit): %10lu (hard limit): %lu\n", s.rlim_cur, s.rlim_max);
        break;
    case RLIMIT_LOCKS:
        getrlimit(RLIMIT_LOCKS, &s);
        printf("File Locks (soft limit): %10lu (hard limit): %lu\n", s.rlim_cur, s.rlim_max);
        break;
    }
}

int main()
{
    struct
    {
        int resource;
        rlim_t soft_limit;
        rlim_t hard_limit;
    } resource_limits[] = {
        {RLIMIT_NICE, 10, 10},
        {RLIMIT_SIGPENDING, 20000, 25000}};
    for (int i = 0; i < sizeof(resource_limits) / sizeof(resource_limits[0]); i++)
    {
        setResourceLimit(resource_limits[i].resource, resource_limits[i].soft_limit, resource_limits[i].hard_limit);
        perror("setResourceLimit");
    }
    printf("\nUpdated Resource Limits:\n");
    for (int i = 0; i < sizeof(resource_limits) / sizeof(resource_limits[0]); i++)
    {
        getResourceLimit(resource_limits[i].resource);
        perror("getResourceLimit");
    }
    return 0;
}
