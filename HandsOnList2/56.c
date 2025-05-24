/*
Program Number: 56
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program to measure the time taken to
execute 100 getppid() system calls using a time stamp counter.
*/
#include <stdio.h>
#include <unistd.h>
#include <time.h>
int main()
{
    clock_t start_time, end_time;
    start_time = clock();
    for (int i = 0; i < 100; i++)
    {
        getppid(); 
    }
    end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken for 100 getppid() system calls: %f seconds\n", time_taken);
    return 0;
}
