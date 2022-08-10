/*************************************************************************
	> File Name: pipe.c
	> Author: 
	> Mail: 
	> Created Time: Thu 31 Mar 2022 10:55:37 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

//无名管道 有亲缘关系
int main()
{
    pid_t pid;
    int fd[2];
    if(pipe(fd) < 0)
    {
        perror("pipe");
        exit(1);
    }

    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    if(pid > 0)
    {
        close(fd[0]);
        printf("i am father!\n");
        char buff[1024] = {0};
        scanf("%[^\n]s", buff);
        getchar();
        write(fd[1], buff, strlen(buff));
        wait(NULL);
    }
    else
    {
        close(fd[1]);
        char buff[1024] = {0};
        read(fd[0], buff, sizeof(buff));
        printf("i am child!\n");
        printf("%s\n", buff);
    }

    return 0;
}
