/*
Program Number: 49a
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program simulates the creation of ticket numbers using a semaphore to protect the critical section. The semaphore ensures that only one process can create a ticket number at a time.
*/
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
sem_t ticket_semaphore;
int ticket_number = 1;
void *create_ticket(void *arg)
{
    sem_wait(&ticket_semaphore); 
    printf("Ticket Number: %d\n", ticket_number);
    ticket_number++; 
    sem_post(&ticket_semaphore); 
    return NULL;
}
int main()
{
    pthread_t threads[5];
    sem_init(&ticket_semaphore, 0, 1); 
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, create_ticket, NULL);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&ticket_semaphore); 
    return 0;
}
