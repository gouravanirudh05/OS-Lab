/*    Program Number: 31
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date:14/04/2025
Description: This is a program to create a pipe, write
to the pipe, read from the pipe, and display the content on the monitor.
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("Pipe creation failed");
        return 1;
    }
    char *msg = "This is program number 31\n";
    int len = strlen(msg);
    if (write(fd[1], msg, len) != len)
    {
        perror("Write to pipe failed");
        return 1;
    }
    char ans[100];
    if (read(fd[0], ans, len) != len)
    {
        perror("Read from pipe failed");
        return 1;
    }
    write(1, ans, len);
    return 0;
}