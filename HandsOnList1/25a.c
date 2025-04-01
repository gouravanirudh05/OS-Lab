/*  
Program Number: 25a  
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 25/02/2025  
Description: This program runs an executable using the execl system 
*/  
#include <stdio.h>  
#include <fcntl.h>  
#include <unistd.h>  
#include <stdlib.h>  

int main()
{
    execl("/bin/ls","ls","-l",(char *)0);
    printf("Error occured");
}
