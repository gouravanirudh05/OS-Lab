/* 
Program Number: 6
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date: 15/02/2025  
Description: This program takes input from STDIN and displays it on STDOUT using read/write system calls. 
*/ 
#include <stdio.h>
#include <unistd.h>

int main() {
    char buf[100];
    int contents = read(0, buf, sizeof(buf));
    if (contents == -1) {
        perror("read");
        return 1;
    }
    write(1, buf, contents);
    return 0;
}