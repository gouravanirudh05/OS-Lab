/*
Program Number: 48
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 11/05/2025
Description: This is a program to a program to create a semaphore
and initialize its value. Part A) Create a counting semaphore
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>
union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
}s;
int main()
{
    int key, semid;
    key = ftok(".", 'a');
    semid = semget(key, 1, IPC_CREAT | 0666);
    printf("%d\n", semid);
    s.val = 2;
    semctl(semid, 0, SETVAL, s);
}
