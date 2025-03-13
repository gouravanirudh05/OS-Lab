/* 
Program Number: 15
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date: 21/02/2025  
Description: This program displays the environmental variables of the user.
*/ 
#include <stdio.h>

extern char **environ;
int main() {
    
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    return 0;
}
