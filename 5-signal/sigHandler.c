/*************************************************************************
	> File Name: sigHandler.c
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Mar 2022 03:00:08 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

void undead(int signo)
{
    printf("get signo=%d, i'm happy, i'm alive.\n", signo);
    return ;
}

int main(void)
{
    struct sigaction newact, oldact;
    newact.sa_handler = undead;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);

    sigaction(SIGINT, &newact, &oldact);
    int n = 20;
    while(n > 0)
    {
        sleep(1);
        n--;
    }
    sigaction(SIGINT, &oldact, NULL);

    return 0;
}
