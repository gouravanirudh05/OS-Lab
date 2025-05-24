/*
Program Number: 57
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program to print system limitations
*/
#include <stdio.h>
#include <unistd.h>

// Function to print a system configuration value
void print_sysconf_value(const char *description, int name)
{
    long value = sysconf(name);
    if (value == -1)
    {
        perror("sysconf");
    }
    else
    {
        printf("%s : %ld\n", description, value);
    }
}

int main()
{
    char *descriptions[] = {
        "a) Maximum length of arguments in exec family of functions",
        "b) Maximum number of simultaneous processes per user ID",
        "c) Number of clock ticks per second",
        "d) Maximum number of open files",
        "e) Size of a memory page (bytes)",
        "f) Total number of physical memory pages",
        "g) Number of available physical memory pages"};

    int sysconf_names[] = {
        _SC_ARG_MAX,
        _SC_CHILD_MAX,
        _SC_CLK_TCK,
        _SC_OPEN_MAX,
        _SC_PAGE_SIZE,
        _SC_PHYS_PAGES,
        _SC_AVPHYS_PAGES};

    int count = sizeof(sysconf_names) / sizeof(sysconf_names[0]);

    for (int i = 0; i < count; ++i)
    {
        print_sysconf_value(descriptions[i], sysconf_names[i]);
    }

    return 0;
}