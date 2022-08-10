/*************************************************************************
	> File Name: sigMask.c
	> Author: 
	> Mail: 
	> Created Time: Tue 01 Mar 2022 04:43:16 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    sigset_t set, oldset;

    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    sigprocmask(SIG_BLOCK, &set, &oldset);
    int n = 10;
    while(n > 0)
    {
        sleep(1);
        printf("proc sleep 1s\n");
        n--;
    }

    sigprocmask(SIG_SETMASK, &oldset, NULL);
    n = 10;
    while(n > 0)
    {
        sleep(1);
        printf("proc sleep 1s\n");
        n--;
    }

    return 0;
}
