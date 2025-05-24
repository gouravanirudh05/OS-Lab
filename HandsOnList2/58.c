/*
Program Number: 58
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program to create three threads and
print the IDs of the created threads.
*/

#include <stdio.h>
#include <pthread.h>

void *thread_func(void)
{
    printf("Thread id is %ld\n", pthread_self());
    return NULL;
}

int main()
{
    pthread_t mythread1, mythread2, mythread3;
    pthread_create(&mythread1, NULL, (void *)thread_func, NULL);
    pthread_create(&mythread2, NULL, (void *)thread_func, NULL);
    pthread_create(&mythread3, NULL, (void *)thread_func, NULL);
    pthread_join(mythread1, NULL);
    pthread_join(mythread2, NULL);
    pthread_join(mythread3, NULL);
    return 0;
}
