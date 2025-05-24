/*    Program Number: 42
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date:11/05/2025
Description: This is a program to print a message queue's attributes
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include<string.h>
int main()
{
    key_t key;
    int msgq_id;
    key = ftok(".", 'm');
    msgq_id = msgget(key, 0744 | IPC_CREAT);
    struct msqid_ds ms_info;
    msgctl(msgq_id, IPC_STAT, &ms_info);
    struct ipc_perm permissions = ms_info.msg_perm;
    printf("Access permissions = %d\n", permissions.mode);
    printf("UID = %d ", permissions.uid);
    printf("GID = %d\n", permissions.gid);
    printf("Time of last message sent = %ld\n", ms_info.msg_stime);
    printf("Time of last message received = %ld\n", ms_info.msg_rtime);
    printf("Time of last change = %ld\n", ms_info.msg_ctime);
    printf("Size of message queue = %ld\n", ms_info.msg_cbytes);
    printf("Number of messages = %ld\n", ms_info.msg_qnum);
    printf("Maximum number of bytes allowed= %ld\n", ms_info.msg_qbytes);
    printf("PID of last msg sent = %d\n", ms_info.msg_lspid);
    printf("PID of last msg received = %d\n", ms_info.msg_lrpid);
    return 0;
}
