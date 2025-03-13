/*  
Program Number: 17b  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 21/02/2025  
Description: This program implements a write lock to ensure that only  
one process at a time can update the ticket number stored in  
"ticket.txt". It reads the current ticket number, increments it,  
and writes the updated value back while holding the write lock.  
*/  

#include <stdio.h>  
#include <fcntl.h>  
#include <unistd.h>  
#include <stdlib.h>  

int main() {
    int fd = open("ticket.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;  
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Process %d: Trying to acquire lock...\n", getpid());

    if (fcntl(fd, F_SETLKW, &lock) == -1) { // Blocking write lock
        perror("Lock failed");
        return 1;
    }

    printf("Process %d: Lock acquired. Processing...\n", getpid());

    int ticket;
    read(fd, &ticket, sizeof(ticket));
    printf("Process %d: Current ticket number: %d\n", getpid(), ticket);
    
    sleep(5);  

    ticket++;
    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket, sizeof(ticket));

    printf("Process %d: Updated ticket number: %d\n", getpid(), ticket);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Process %d: Lock released.\n", getpid());

    close(fd);
    return 0;
}
