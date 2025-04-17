/*    Program Number: 38b
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date:14/04/2025
Description: This is part two of the program where two programs establish communication 
through FIFO using two-way communication.
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
    char msg_write[15];
    char msg_read[15];
    while (1) {
        printf("Enter Message: ");
        fgets(msg_write, sizeof(msg_write), stdin);
        write(fd, msg_write, sizeof(msg_write));
        int size = read(fd, msg_read, sizeof(msg_read));
        if (size > 0) {
            printf("Received: %s", msg_read);
        }
    }
    close(fd);
    return 0;
}
