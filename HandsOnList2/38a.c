/*    Program Number: 38a
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date:14/04/2025
Description: This is part one of the program where two programs communicate using FIFO - Two-way communication.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int fd;
    mkfifo("fifo2", 0666);
    fd = open("fifo2", O_RDWR);
    if (fd == -1) {
        perror("Error opening fifo2");
        return 1;
    }
    char message_read[15];
    char message_write[15];
    while (1) {
        read(fd, message_read, sizeof(message_read));
        printf("Received: %s", message_read);
        printf("Enter Message: ");
        fgets(message_write, sizeof(message_write), stdin);
        write(fd, message_write, sizeof(message_write));
    }
    close(fd);
    return 0;
}
