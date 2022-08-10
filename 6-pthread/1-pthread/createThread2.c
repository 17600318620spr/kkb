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

pthread_t ntid;

void printid(char *);
void *thr_fn(void *arg);

int main()
{
    int ret;
    ret = pthread_create(&ntid, NULL, thr_fn, "new thread");
    if(ret)
    {
        printf("create thread err:%s\n", strerror(ret));
        exit(1);
    }

    //sleep(1);
    pthread_join(ntid, NULL);
    printid("main thread");

    return 0;
}

void *thr_fn(void *arg)
{
    printid(arg);
    printf("%s ntid=%p\n", arg, ntid);
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
