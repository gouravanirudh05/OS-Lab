/*    Program Number: 46
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date:11/05/2025
Description: This is a program to remove the message queue.
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    key_t key = ftok(".", 'm');
    int msg_id = msgget(key, IPC_CREAT | 0744);
    printf("msg id : %d\n", msg_id);
    msgctl(msg_id, IPC_RMID, NULL);
    execlp("ipcs", "ipcs", "-q", NULL);
}