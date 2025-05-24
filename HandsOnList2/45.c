/*    Program Number: 45
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date:11/05/2025
Description: This is a program  to change the existing
message queue permissions using the msg_id_ds structure.
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    key_t key= ftok(".", 'm');
    int msg_id = msgget(key, 0744 | IPC_CREAT);
    struct msqid_ds ms_info;
    msgctl(msg_id, IPC_STAT, &ms_info);
    struct ipc_perm *permissions = &ms_info.msg_perm;
    printf("Current permissions : %d\n", permissions->mode);
    permissions->mode = 777;
    ms_info.msg_perm = *permissions;
    msgctl(msg_id, IPC_SET, &ms_info);
    msgctl(msg_id, IPC_STAT, &ms_info);
    printf("New permissions set are: %d \n", permissions->mode);
    return 0;
}
