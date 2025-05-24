/*
Program Number: 49c
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program uses a counting semaphore to protect multiple pseudo resources. In this case, the counting semaphore will manage two resources, ensuring that no more than two threads can access the resources at the same time.
*/
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
sem_t resource_semaphore;
void *access_resource(void *arg)
{
    sem_wait(&resource_semaphore); 
    printf("Thread accessing resource\n");
    sleep(1); 
    sem_post(&resource_semaphore); 
    return NULL;
}
int main()
{
    pthread_t threads[5];
    sem_init(&resource_semaphore, 0, 2); 
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, access_resource, NULL);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&resource_semaphore); 
    return 0;
}
