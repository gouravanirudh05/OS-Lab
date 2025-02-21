/* 
Program Number: 9
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date: 15/02/2025  
Description: This program prints various details about a given file. 
*/ 
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    FILE *file = fopen("file_9.txt", "w");
    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }
    fprintf(file, "Hello, this is a test file.\nThis is the second line.\n");
    fclose(file);
    char filename[] = "file_9.txt";
    struct stat fileStat;
    if (stat(filename, &fileStat) == -1) {
        perror("stat");
        return 1;
    }
    printf("a)Inode: %ld\n", fileStat.st_ino);
    printf("b)Number of Hard Links: %ld\n", fileStat.st_nlink);
    printf("c)UID: %d\n", fileStat.st_uid);
    printf("d)GID: %d\n", fileStat.st_gid);
    printf("e)Size: %ld bytes\n", fileStat.st_size);
    printf("f)Block Size: %ld\n", fileStat.st_blksize);
    printf("g)Number of Blocks: %ld\n", fileStat.st_blocks);
    printf("h)Last Access Time: %s", ctime(&fileStat.st_atime));
    printf("i)Last Modification Time: %s", ctime(&fileStat.st_mtime));
    printf("j)Last Change Time: %s", ctime(&fileStat.st_ctime));
    return 0;
}