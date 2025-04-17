/*    Program Number: 37b
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date:14/04/2025
Description:This is a part two of the program where two programs so that both can communicate by FIFO -Use one way communication.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd = open("fifo",O_WRONLY);
    char message[100] = "Hello how are you\n";
    write(fd,message,100);
    return 0 ;

}