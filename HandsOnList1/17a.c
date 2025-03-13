/*  
Program Number: 17a  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 21/02/2025  
Description: This program initializes a ticket number and stores it  
in a file named "ticket.txt". This file will be used by other  
processes to read and update the ticket number in subsequent operations.  
*/ 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int fd = open("ticket.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    int ticket = 1;
    write(fd, &ticket, sizeof(ticket));
    printf("Initial ticket number stored: %d\n", ticket);
    close(fd);
    return 0;
}
