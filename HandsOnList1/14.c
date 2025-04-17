/*
Program Number: 14
Student Name: Gourav Anirudh B J; Register Number: IMT2023005
Date: 21/02/2025
Description: This program identifies the type of a file.
*/
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Use it like this: %s <filename>\n", argv[0]);
        return 1;
    }
    struct stat status;
    if (stat(argv[1], &status) == -1)
    {
        perror("stat failed");
        return 1;
    }
    printf("File Type: ");
    if (S_ISREG(status.st_mode))
        printf("Regular File\n");
    else if (S_ISLNK(status.st_mode))
        printf("Symbolic Link\n");
    else if (S_ISCHR(status.st_mode))
        printf("Character Device\n");
    else if (S_ISDIR(status.st_mode))
        printf("Directory\n");
    else if (S_ISFIFO(status.st_mode))
        printf("FIFO (Named Pipe)\n");
    else if (S_ISSOCK(status.st_mode))
        printf("Socket\n");
    else if (S_ISBLK(status.st_mode))
        printf("Block Device\n");
    else
        printf("Unknown Type\n");

    return 0;
}
