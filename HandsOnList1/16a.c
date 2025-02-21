/* 
Program Number: 16a
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date: 21/02/2025  
Description: Implements a write lock using fcntl. 
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("file_16a.txt", O_WRONLY | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;  // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // Lock entire file

    printf("Trying to acquire write lock...\n");
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error acquiring write lock");
        close(fd);
        return 1;
    }
    printf("Write lock acquired! Writing to file...\n");

    write(fd, "Write lock applied\n", 19);
    sleep(10); // Keep lock for demonstration

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Write lock released.\n");

    close(fd);
    return 0;
}
