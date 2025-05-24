/*
Program Number: 63
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date: 11/05/2025
Description: This is a program to create an orphan process. Utilize
the kill system call to send a SIGKILL signal from the child process to the parent
process.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
    int child_pid = fork();
    if (child_pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        printf("Child process:PID is %d\n", getpid());
        sleep(5);
        if (kill(getppid(), SIGKILL) == -1)
        {
            perror("kill");
            exit(EXIT_FAILURE);
        }
        printf("Child process: Sent SIGKILL signal to parent\n");
    }
    else
    {
        printf("Parent process:PID is %d\n", getpid());
        wait(NULL);
        printf("Parent process: Child process terminated\n");
    }
    return 0;
}
