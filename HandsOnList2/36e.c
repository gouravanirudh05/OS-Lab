/*
Program Number: 36e
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program demonstrates how to create a FIFO file using the mkfifo library function in C.
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    const char *fifo_name = "fifo_using_mkfifo";

    // Create FIFO using mkfifo
    if (mkfifo(fifo_name, 0666) == -1)
    {
        perror("mkfifo");
        return 1;
    }

    printf("FIFO file '%s' created using mkfifo.\n", fifo_name);
    return 0;
}
