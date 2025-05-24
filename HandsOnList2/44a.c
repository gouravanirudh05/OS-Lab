/*    Program Number: 44a
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date:11/05/2025
Description: This is a program to receive messages from the message queue with 0 as a flag.
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
struct msgbuf
{
    long int type;
    char text[100];
} msgq;
int main()
{
    int msg_id;
    key_t key;
    key = ftok(".", 'm');
    msg_id = msgget(key, 0);
    msgq.type = 10;
    msgrcv(msg_id, &msgq, sizeof(msgq), 10, 0);
    printf("Message recieved %s", msgq.text);
    execlp("ipcs", "ipcs", "-q", NULL);
    return 0;
}