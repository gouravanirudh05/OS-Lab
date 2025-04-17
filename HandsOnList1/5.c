/* 
Program Number: 5
Student Name: Gourav Anirudh B J; Register Number: IMT2023005 
Date: 15/02/2025  
Description: This program continuously creates five new files in an infinite loop. 
*/ 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int count = 0 ;
	char arr[][100]={"file1.txt","file2.txt","file3.txt","file4.txt","file5.txt"};
	while(1){
		if(count<5) {
            creat(arr[count++],O_CREAT); 
        }
	}
    return 0;
}
