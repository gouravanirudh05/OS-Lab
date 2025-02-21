/* 
Program Number: 13
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date: 21/02/2025  
Description: This program waits for input from STDIN for 10 seconds using select.
*/ 
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input... (10 seconds timeout)\n");
    
    int retval = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);
    if (retval == -1) {
        perror("select() failed");
    } else if (retval) {
        printf("Data available! Reading input:\n");
        char buffer[100];
        read(STDIN_FILENO, buffer, sizeof(buffer));
        printf("You entered: %s", buffer);
    } else {
        printf("No input received within 10 seconds.\n");
    }

    return 0;
}
