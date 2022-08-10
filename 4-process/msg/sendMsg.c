/*************************************************************************
	> File Name: mqOpt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 28 Feb 2022 03:43:21 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/msg.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define MSGLEN 20

typedef struct msgbuf{
    long mtype;
    char mtext[MSGLEN];
}MSG;

int main(void)
{
    key_t key = ftok("./test", 9);
    printf("key=%#x\n", key);

    int mqid = msgget(key, IPC_CREAT | 0666);
    printf("mqid=%d\n", mqid);

    MSG msg;
    msg.mtype = 1;
    strncpy(msg.mtext, "hi, how are you?\n", MSGLEN);
    msgsnd(mqid, &msg, MSGLEN, 0);

    msg.mtype = 2;
    strncpy(msg.mtext, "xiaokai:online\n", MSGLEN);
    msgsnd(mqid, &msg, MSGLEN, 0);

    return 0;
}
