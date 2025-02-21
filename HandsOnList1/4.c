/* 
Program Number: 4
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date:15/02/2025  
Description: This program is to open an existing file in read-write mode. 
Experiment with the O_EXCL flag. 
 
*/ 
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    FILE *fp=fopen("file_4.txt","w+");
    if(fp==NULL)
    {
        printf("File not created\n");
        return 1;
    }
    fprintf(fp,"This is file_4.txt\n");
    fclose(fp);
        char filename[] = "file_4.txt";
        int fd = open(filename, O_RDWR | O_EXCL);
        if (fd == -1) {
            perror("open");
            return 1;
        }
        printf("File %s opened successfully with fd = %d\n", filename, fd);
        return 0;

}