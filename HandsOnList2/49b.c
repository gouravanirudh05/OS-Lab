/*
Program Number: 49b
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program uses a semaphore to protect shared memory from concurrent write access by multiple threads. The semaphore ensures that only one thread can write to the shared memory at a time.
*/
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
sem_t memory_semaphore;
int shared_memory = 0;
void *write_to_memory(void *arg)
{
    sem_wait(&memory_semaphore); 
    printf("Writing to shared memory. Current value: %d\n", shared_memory);
    shared_memory += 10; 
    printf("Written to shared memory. New value: %d\n", shared_memory);
    sem_post(&memory_semaphore); 
    return NULL;
}
int main()
{
    pthread_t threads[5];
    sem_init(&memory_semaphore, 0, 1); 
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, write_to_memory, NULL);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&memory_semaphore); 
    return 0;
}
