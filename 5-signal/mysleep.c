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
    newact.sa_handler = sig_alarm;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);

    sigaction(SIGALRM, &newact, &oldact);

    alarm(sec);
    pause();

    int unslept;
    unslept = alarm(0);
    sigaction(SIGALRM, &oldact, NULL);

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
