/*  
    Program Number: 45
    Student Name: Gourav Anirudh; Register Number: IMT2023005  
    Date: 18/04/2025  
    Description: This program to change the existing 
message queue permissions using the msqid_ds structure. 
*/
#include <stdio.h>
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
    msqid = msgget(key, 0744 | IPC_CREAT);
    if (msqid == -1) {
        perror("msgget failed");
        return 1;
    }
    struct msqid_ds ms_info;
    if (msgctl(msqid, IPC_STAT, &ms_info) == -1) {
        perror("msgctl IPC_STAT failed");
        return 1;
    }
    printf("Current permissions: %o\n", ms_info.msg_perm.mode);
    ms_info.msg_perm.mode = 0777;
    if (msgctl(msqid, IPC_SET, &ms_info) == -1) {
        perror("msgctl IPC_SET failed");
        return 1;
    }
    printf("\nNew permissions set successfully.\n");
    if (msgctl(msqid, IPC_STAT, &ms_info) == -1) {
        perror("msgctl IPC_STAT (confirm) failed");
        return 1;
    }
    printf("Updated permissions: %o\n", ms_info.msg_perm.mode);
    return 0;
}