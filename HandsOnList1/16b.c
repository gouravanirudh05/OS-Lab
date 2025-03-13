/* 
Program Number: 16a
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date: 21/02/2025  
Description: Implements a read lock using fcntl. 
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("lockfile.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_RDLCK;  // Read lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Lock failed");
        return 1;
    }

    printf("Read lock acquired. Press Enter to release.\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    close(fd);
    return 0;
}
