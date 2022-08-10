/*************************************************************************
> File Name: multiProc.c
> Author: 
> Mail: 
> Created Time: Thu 24 Feb 2022 10:42:05 AM CST
************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    char *msg;

    for(int i = 0; i < 10; i++)
    {
        pid_t pid = fork();
        if(pid < 0)
        {
            perror("fork");
            exit(1);
        }

        if(!pid)
        {
            printf("child[%d], self = %d, parent=%d\n", i, getpid(), getppid());
            sleep(1);
            break;
        }
    }

    return 0;
}
