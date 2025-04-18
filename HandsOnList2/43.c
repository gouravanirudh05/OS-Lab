/*  
    Program Number: 43  
    Student Name: Gourav Anirudh; Register Number: IMT2023005  
    Date: 18/04/2025  
    Description: This program sends a message to an existing message queue.  
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#define MAX_TEXT 100
struct message {
    long mtype;
    char mtext[MAX_TEXT];
};
int main() {
    int key;
    int msgid;
    struct message msg;
    key = ftok(".", 'm');
    if (key == -1) {
        perror("ftok error");
        return 1;
    }
    msgid = msgget(key, 0);
    if (msgid == -1) {
        perror("msgget error");
        return 1;
    }
    msg.mtype = 10;
    printf("Enter message to send: ");
    fgets(msg.mtext, MAX_TEXT, stdin);
    if (msgsnd(msgid, &msg, sizeof(msg.mtext), 0) == -1) {
        perror("msgsnd error");
        return 1;
    }
    execlp("ipcs", "ipcs", "-q", NULL);
    return 0;
}
