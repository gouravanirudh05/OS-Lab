/*
Program Number: 54
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program  to print system resource limits using the
getrlimit system call.
*/

#include <stdio.h>
#include <sys/resource.h>

void printLimit(const char *desc, int resource)
{
    struct rlimit limit;
    if (getrlimit(resource, &limit) == 0)
    {
        printf("%-25s (soft limit): %10lu  (hard limit): %10lu\n", desc, limit.rlim_cur, limit.rlim_max);
    }
    else
    {
        perror("getrlimit");
    }
}

int main()
{
    struct
    {
        int resource;
        const char *description;
    } limits[] = {
        {RLIMIT_CORE, "Core File Size"},
        {RLIMIT_DATA, "Data Size"},
        {RLIMIT_NICE, "Nice Priority"},
        {RLIMIT_FSIZE, "File Size"},
        {RLIMIT_SIGPENDING, "Pending Signals"},
        {RLIMIT_MEMLOCK, "Max Locked Memory"},
        {RLIMIT_MSGQUEUE, "Message Queue"},
        {RLIMIT_RTPRIO, "Real-Time Priority"},
        {RLIMIT_STACK, "Stack Size"},
        {RLIMIT_RTTIME, "CPU Time"},
        {RLIMIT_NPROC, "Max User Processes"},
        {RLIMIT_AS, "Virtual Memory"},
        {RLIMIT_LOCKS, "File Locks"}};

    int count = sizeof(limits) / sizeof(limits[0]);
    for (int i = 0; i < count; ++i)
    {
        printLimit(limits[i].description, limits[i].resource);
    }

    return 0;
}
