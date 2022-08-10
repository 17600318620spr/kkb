/*************************************************************************
	> File Name: waitOpt.c
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Feb 2022 10:33:05 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        exit(1);
    }

    if(pid == 0)
    {
        int n = 10;
        while(n > 0)
        {
            printf("this is child process %d\n", getpid());
            sleep(1);
            n--;
        }
        exit(3);
    }
    else
    {
        int stat_val;
        waitpid(pid, &stat_val, 0);
        if(WIFEXITED(stat_val))
        {
            printf("child exited with code %d\n", WEXITSTATUS(stat_val));
        }
        else if(WIFSIGNALED(stat_val))
        {
            printf("child terminated abnormally, signal %d\n", WTERMSIG(stat_val));
        }
    }

    return 0;
}
