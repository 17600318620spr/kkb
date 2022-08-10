/*************************************************************************
	> File Name: mysleep.c
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Mar 2022 03:35:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

void sig_alarm(int signo)
{
    return ;
}

unsigned int mysleep(unsigned int sec)
{
    struct sigaction newact, oldact;
    sigset_t newmask, oldmask, susmask;
    newact.sa_handler = sig_alarm;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);

    sigaction(SIGALRM, &newact, &oldact);

    //阻塞闹钟信号
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGALRM);
    sigprocmask(SIG_BLOCK, &newmask, &oldmask);

    //开启闹钟
    alarm(sec);

    //读取老的信号屏蔽字
    susmask = oldmask;
    //删除里面的alarm信号
    sigdelset(&susmask, SIGALRM);
    //临时设置信号屏蔽字为susmask, 并且挂起程序等待信号到来
    sigsuspend(&susmask);

    int unslept;
    unslept = alarm(0);
    sigaction(SIGALRM, &oldact, NULL);
    sigprocmask(SIG_SETMASK, &oldmask, NULL);

    return unslept;
}

int main()
{
    int n = 5;
    while(n)
    {
        printf("hello my sleep 1s\n");
        mysleep(1);
        n--;
    }

    return 0;
}
