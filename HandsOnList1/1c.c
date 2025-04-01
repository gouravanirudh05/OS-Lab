/* 
Program Number: 1c 
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date:15/02/2025  
Description: This program creates a FIFO file using mkfifo system call. 
*/ 
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main() 
{
    char *fifo_path = "fifo"; 
    // Creating FIFO using mkfifo
    if (mkfifo(fifo_path,0744) == -1)  
    {
        perror("Failed to create FIFO");
        return 1;
    }
    printf("FIFO '%s' created successfully\n", fifo_path);
    return 0;
}

