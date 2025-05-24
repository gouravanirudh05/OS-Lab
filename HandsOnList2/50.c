/*
Program Number: 50
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 11/05/2025
Description: This is a program to intentionally induces a deadlock scenario using
semaphores.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1, sem2;
void *thread1(void *arg)
{
    printf("Thread 1 trying to acquire semaphore 1...\n");
    sem_wait(&sem1);
    printf("Thread 1 acquired semaphore 1.\n");
    sleep(1);
    printf("Thread 1 trying to acquire semaphore 2...\n");
    sem_wait(&sem2);
    printf("Thread 1 acquired semaphore 2.\n");
    sem_post(&sem2);
    printf("Thread 1 released semaphore 2.\n");
    sem_post(&sem1);
    printf("Thread 1 released semaphore 1.\n");
    pthread_exit(NULL);
}

void *thread2(void *arg)
{
    printf("Thread 2 trying to acquire semaphore 2...\n");
    sem_wait(&sem2);
    printf("Thread 2 acquired semaphore 2.\n");
    sleep(1);
    printf("Thread 2 trying to acquire semaphore 1...\n");
    sem_wait(&sem1);
    printf("Thread 2 acquired semaphore 1.\n");
    sem_post(&sem1);
    printf("Thread 2 released semaphore 1.\n");
    sem_post(&sem2);
    printf("Thread 2 released semaphore 2.\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t threadOne;
    pthread_t threadTwo;

    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 1);

    pthread_create(&threadOne, NULL, thread1, NULL);
    pthread_create(&threadTwo, NULL, thread2, NULL);
    pthread_join(threadOne, NULL);
    pthread_join(threadTwo, NULL);

    sem_destroy(&sem1);
    sem_destroy(&sem2);

    return 0;
}
