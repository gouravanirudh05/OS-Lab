/*  
Program Number: 25b  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 25/02/2025  
Description: Pass argument to executable  
*/  
#include <stdio.h>
#include <unistd.h>
int main() {
    char *arr[] = {"/bin/echo", "hello", NULL};
    printf("Executing echo with parameter: hello\n");
    execv(arr[0], arr);
    perror("execv failed");
    return 1;
}
