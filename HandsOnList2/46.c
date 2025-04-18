/*  
    Program Number: 46
    Student Name: Gourav Anirudh; Register Number: IMT2023005  
    Date: 18/04/2025  
    Description: This program to remove the message queue.  
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main() {
    key_t key;
    int msqid;
    key = ftok(".", 'm');
    if (key == -1) {
        perror("ftok failed");
        return 1;
    }
    msqid = msgget(key, IPC_CREAT | 0744);
    if (msqid == -1) {
        perror("msgget failed");
        return 1;
    }
    printf("Message Queue ID: %d\n", msqid);
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID failed");
        return 1;
    }
    printf("Message queue removed successfully.\n");
    execlp("ipcs", "ipcs", "-q", NULL);
    perror("execlp failed");
    return 1;
}