/*    Program Number: 42
Student Name: Gourav Anirudh; Register Number: IMT2023005
Date:14/04/2025
Description: This is a program to print a message queue's attributes
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>

int main(){
    key_t key; 
	int msgqid; 
	key = ftok(".", 'm'); 

	msgqid = msgget(key, 0744 | IPC_CREAT); 
    struct msqid_ds info;
	msgctl(msgqid,IPC_STAT,&info);
    struct ipc_perm permissions = info.msg_perm;
    printf("a)Access permissions = %d\n",permissions.mode);
    printf("b)UID = %d ",permissions.uid);
    printf(" GID = %d\n",permissions.gid);
    printf("c)Time of last message sent = %ld ",info.msg_stime);
    printf(" Time of last message received = %ld\n",info.msg_rtime);
    printf("d)Time of last change in the message queue = %ld\n",info.msg_ctime);
    printf("e)Size of message queue = %ld\n",info.msg_cbytes);
    printf("f)Number of messages = %ld\n",info.msg_qnum);
    printf("g)Maximum number of bytes allowed = %ld\n",info.msg_qbytes);
    printf("h)PID of last message sent = %d",info.msg_lspid);
    printf(" PID of last message received = %d\n",info.msg_lrpid);
	return 0; 
}