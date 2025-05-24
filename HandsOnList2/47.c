/*
Program Number: 47
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 11/05/2025
Description: This is a program to create shared memory and
perform the following operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    key_t key = 1234;
    int shmid;
    char *write_data, *read_data;

    // Create the shared memory segment
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0)
    {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment with read-write permissions
    write_data = (char *)shmat(shmid, NULL, 0);
    if (write_data == (char *)-1)
    {
        perror("shmat (read-write)");
        exit(1);
    }

    // Write data to the shared memory
    sprintf(write_data, "This is program 47");

    // Attach to the shared memory segment with read-only permissions
    read_data = (char *)shmat(shmid, NULL, SHM_RDONLY);
    if (read_data == (char *)-1)
    {
        perror("shmat (read-only)");
        exit(1);
    }

    // Read and print the content from the read-only pointer
    printf("Read from shared memory: %s\n", read_data);

    // Detach both mappings
    if (shmdt(write_data) == -1)
    {
        perror("shmdt (write_data)");
        exit(1);
    }

    if (shmdt(read_data) == -1)
    {
        perror("shmdt (read_data)");
        exit(1);
    }

    // Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl(IPC_RMID)");
        exit(1);
    }

    return 0;
}
