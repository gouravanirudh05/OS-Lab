/*  
Program Number: 28
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 31/03/2025  
Description: Get and modify the priority (nice value) of the process  
*/  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h> 

int main() {
    int nice_value = getpriority(PRIO_PROCESS, 0);
    printf("Current nice value: %d\n", nice_value);
    // Modifying priority using nice
    nice(10); 
    nice_value = getpriority(PRIO_PROCESS, 0);
    printf("Updated nice value: %d\n", nice_value);
    return 0;
}
