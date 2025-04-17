/* 
Program Number: 1a
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date:15/02/2025  
Description: This program creates a soft link using the symlink system call. 
*/ 
#include <unistd.h>
#include <stdio.h>
int main() 
{
   
    FILE *fp=fopen("file1a.txt","w");
    if(fp==NULL)
    {
        printf("File not created\n");
        return 1;
    }
    fprintf(fp,"This is file1a.txt\n");
    fclose(fp);
    //Creating a softlink to file1a.txt 
    if(symlink("file1a.txt","softlink1a.txt")==-1)
    {
        printf("Failed to create softlink\n");
        return 1;
    }
    printf("Softlink created successfully\n");
    return 0;
}

