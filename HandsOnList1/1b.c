/* 
Program Number: 1b 
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date:15/02/2025  
Description: This program creates a hard link using the link system call. 
*/ 
#include <unistd.h>
#include <stdio.h>

int main() 
{
    FILE *fp = fopen("file1b.txt", "w");
    if (fp == NULL)
    {
        printf("File not created\n");
        return 1;
    }
    fprintf(fp, "This is file1b.txt\n");
    fclose(fp);
    if (link("file1b.txt", "hardlink1b.txt") == -1)  
    {
        perror("Failed to create hardlink");  
        return 1;
    }

    printf("Hardlink created successfully\n");
    return 0;
}
