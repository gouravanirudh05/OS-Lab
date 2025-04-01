/*  
Program Number: 27 
Student Name: Gourav Anirudh B J; Register Number: IMT2023005  
Date: 31/03/2025  
Description:To retrieve the maximum and minimum real-time priority.    
*/ 
#include <stdio.h>
#include <sched.h>

int main(){
    int max_priority = sched_get_priority_max(SCHED_RR);
    int min_priority = sched_get_priority_min(SCHED_RR);
    printf("Maximum real-time priority: %d\n", max_priority);
    printf("Minimum real-time priority: %d\n", min_priority);
    return 0;
}
