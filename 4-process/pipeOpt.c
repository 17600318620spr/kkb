/*************************************************************************
	> File Name: pipeOpt.c
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Feb 2022 02:53:30 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main1()
{
    int fd[2];
    if(pipe(fd) < 0)
    {
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        exit(1);
    }

    int n;
    char buf[32];
    if(pid > 0)
    {
        close(fd[0]);
        write(fd[1], "hello pipe\n", 11);
        wait(NULL);
    }
    else
    {
        close(fd[1]);
        sleep(1);
        n = read(fd[0], buf, 32);
        write(1, buf, n);
    }

    return 0;
}

int main()
{
    int fd[2];
    if(pipe(fd) < 0)
    {
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        exit(1);
    }

    char test[1024];
    if(pid > 0)
    {
        close(fd[0]);
        for(int i = 0; i < 100; i++)
        {
            write(fd[1], test, 1024);
            printf("i=%d\n", i);
        }
        wait(NULL);
    }
    else
    {
        close(fd[1]);
        sleep(5);
    }

    return 0;
}
