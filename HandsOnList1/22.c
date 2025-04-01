/*
Program Number: 22
Student Name: Gourav Anirudh B J; Register Number: IMT2023005
Date: 21/02/2025
Description: This program creates a zombie state
*/
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid = fork();

    if (pid == 0)
    { 
        //child process 
        exit(0);
    }
    else
    {             
        // parent process
        sleep(10); // wait for 10 seconds without calling wait()
    }

    return 0;
}