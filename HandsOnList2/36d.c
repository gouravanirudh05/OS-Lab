/*
Program Number: 36d
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 12/05/2025
Description: This program demonstrates how to create a FIFO file using the mknod system call in C.
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    const char *fifo_name = "fifo_using_mknod";

    // Create FIFO using mknod
    if (mknod(fifo_name, S_IFIFO | 0666, 0) == -1)
    {
        perror("mknod");
        return 1;
    }

    printf("FIFO file '%s' created using mknod.\n", fifo_name);
    return 0;
}
