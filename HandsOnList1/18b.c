/*  
Program Number: 18b  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 31/03/2025  
Description: Simple read lock implementation  
*/  

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("file18_.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    int rec_num;
    printf("Enter record number to lock (1, 2, or 3): ");
    scanf("%d", &rec_num);

    struct flock lock = {F_RDLCK, SEEK_SET, (rec_num - 1) * sizeof(int), sizeof(int), getpid()};

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Read lock failed");
        close(fd);
        return 1;
    }

    printf("Read lock set. Press Enter to unlock.\n");
    getchar(); 
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Read lock released.\n");

    close(fd);
    return 0;
}
