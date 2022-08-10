/*************************************************************************
> File Name: sigChild.c
> Author: 
> Mail: 
> Created Time: Wed 02 Mar 2022 06:15:34 PM CST
************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

void sig_child(int signo)
{
    int sts;

    wait(&sts);
    if(WIFEXITED(sts))
    {
        printf("exit with code %d\n", WEXITSTATUS(sts));
    }
    else
    {
        printf("Lemon\n");
    }

    return ;
}

int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        exit(1);
    }

    if(pid)
    {
        pid = fork();
        if(pid < 0)
        {
            perror("fork time:2");
            exit(1);
        }

        if(pid > 0)
        {
            struct sigaction newact, oldact;

            newact.sa_handler = sig_child;
            sigemptyset(&newact.sa_mask);
            newact.sa_flags = 0;

            sigaction(SIGCHLD, &newact, &oldact);

            int n = 10;
            while(n--)
            {
                printf("work ~\n");
                sleep(1);
            }
        }
        else
        {
            sleep(5);
            exit(5);
        }
    }
    else
    {
        sleep(3);
        exit(3);
    }

    return 0;
}
