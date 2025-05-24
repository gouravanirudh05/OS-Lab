/*
Program Number: 49d
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program demonstrates the removal of a semaphore after its use. The semaphore is destroyed after the critical section has been executed by all threads.
*/
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
sem_t cleanup_semaphore;
void *cleanup_task(void *arg)
{
    sem_wait(&cleanup_semaphore); 
    printf("Performing cleanup task...\n");
    sleep(1); 
    sem_post(&cleanup_semaphore); 
    return NULL;
}
int main()
{
    pthread_t threads[3];
    sem_init(&cleanup_semaphore, 0, 1); 
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&threads[i], NULL, cleanup_task, NULL);
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&cleanup_semaphore); 
    printf("Semaphore destroyed.\n");
    return 0;
}
