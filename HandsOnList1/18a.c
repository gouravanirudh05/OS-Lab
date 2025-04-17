/*  
Program Number: 18a  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 31/03/2025  
Description: record based write lock implementation  
*/  

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("file_18.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    int rec_num;
    printf("Enter record number to lock (1, 2, or 3): ");
    scanf("%d", &rec_num);

    struct flock lock = {F_WRLCK, SEEK_SET, (rec_num - 1) * sizeof(int), sizeof(int), getpid()};

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Lock failed");
        close(fd);
        return 1;
    }

    printf("Write lock set. Press Enter to unlock.\n");
    getchar(); 
    getchar(); 
    close(fd);
    return 0;
}
