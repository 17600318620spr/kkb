/*************************************************************************
	> File Name: createThread.c
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Mar 2022 11:21:15 AM CST
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>

void printid(char *);
void *thr_fn(void *arg);

int main()
{
    pthread_t ntid;
    int ret;
    ret = pthread_create(&ntid, NULL, thr_fn, "new thread");
    if(ret)
    {
        printf("create thread err:%s\n", strerror(ret));
        exit(1);
    }

    sleep(1);
    printid("main thread");

    return 0;
}

void *thr_fn(void *arg)
{
    printid(arg);
    return NULL;
}

void printid(char *tip)
{
    pid_t pid = getpid();
    pthread_t tid = pthread_self();

    printf("%s pid=%u tid=%u (%p)\n", tip, pid, tid, tid);
    //printf("%s thr_fn=%p\n", tip, thr_fn);

    return ;
}
