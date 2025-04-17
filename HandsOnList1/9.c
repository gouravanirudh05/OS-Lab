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
    printf(
        "a) Inode: %ld\n"
        "b) Number of Hard Links: %ld\n"
        "c) UID: %d\n"
        "d) GID: %d\n"
        "e) Size: %ld bytes\n"
        "f) Block Size: %ld\n"
        "g) Number of Blocks: %ld\n"
        "h) Last Access Time: %s"
        "i) Last Modification Time: %s"
        "j) Last Change Time: %s",
        fileStat.st_ino,
        fileStat.st_nlink,
        fileStat.st_uid,
        fileStat.st_gid,
        fileStat.st_size,
        fileStat.st_blksize,
        fileStat.st_blocks,
        ctime(&fileStat.st_atime),
        ctime(&fileStat.st_mtime),
        ctime(&fileStat.st_ctime)
    );
    
    return 0;
}