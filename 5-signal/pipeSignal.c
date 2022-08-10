/*************************************************************************
	> File Name: pipeSignal.c
	> Author: 
	> Mail: 
	> Created Time: Tue 01 Mar 2022 01:34:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int pfd[2];
    if(pipe(pfd) < 0)
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

    if(pid)
    {
        close(pfd[0]);
        close(pfd[1]);

        int sts;
        wait(&sts);
        if(WIFSIGNALED(sts))
        {
            printf("signal = %d\n", WTERMSIG(sts));
        }
        else
        {
            printf("exit other ways\n");
        }
    }
    else
    {
        sleep(3);
        close(pfd[0]);
        write(pfd[1], "hello\n", 6);
        sleep(3);
    }


    return 0;
}
