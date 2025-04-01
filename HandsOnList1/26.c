/*
Program Number: 26
Student Name: Gourav Anirudh B J; Register Number: IMT2023005
Date: 31/03/2025
Description: Execute `ls -Rl` using various exec family functions
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void run_execl()
{
    execl("/bin/ls", "ls", "-R", "-l", NULL);
}
void run_execlp()
{
    execlp("ls", "ls", "-R", "-l", NULL);
}
void run_execle()
{
    char *envp[] = {NULL};
    execle("/bin/ls", "ls", "-R", "-l", NULL, envp);
}
void run_execv()
{
    char *args[] = {"/bin/ls", "-R", "-l", NULL};
    execv(args[0], args);
}
void run_execvp()
{
    char *args[] = {"ls", "-R", "-l", NULL};
    execvp(args[0], args);
}

void test_exec(const char *name, void (*exec_func)())
{
    pid_t pid = fork();
    if (pid == 0)
    { 
        // Child process
        printf("\nRunning %s:\n", name);
        exec_func();
        perror("exec failed");
        exit(1);
    }
    else
    {
        wait(NULL); 
    }
}
int main()
{
    test_exec("execl", run_execl);
    test_exec("execlp", run_execlp);
    test_exec("execle", run_execle);
    test_exec("execv", run_execv);
    test_exec("execvp", run_execvp);
    return 0;
}
