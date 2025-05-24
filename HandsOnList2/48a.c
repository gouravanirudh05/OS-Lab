/*
Program Number: 48
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 11/05/2025
Description: This is a program to a program to create a semaphore
and initialize its value. Part A) Create a binary semaphore
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
union semun
{
    int count;
    struct semid_ds describe_sem;
    unsigned short int set_get_val;
} s;
int main()
{
    int key = ftok(".", 'm');
    int semid = semget(key, 1, IPC_CREAT | 0744);
    printf("SEM_ID %d\n", semid);
    s.count = 1;
    semctl(semid, 0, SETVAL, s);
}