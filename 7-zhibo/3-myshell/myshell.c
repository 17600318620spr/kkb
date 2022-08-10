/*************************************************************************
> File Name: myshell.c
> Author: 
> Mail: 
> Created Time: Tue 29 Mar 2022 02:59:37 PM CST
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<ctype.h>

char *strip(char *str)
{
    //去除字符串两端的空白
    int head = 0, tail = strlen(str) - 1;
    while(isspace(str[head]))
    {
        head++;
    }
    while(isspace(str[tail]))
    {
        str[tail--] = '\0';
    }

    return str + head;
}

void runcmd(char *buff)
{
    int redfd = -1;
    if(strstr(buff, "<"))
    {
        //0 标准输入
        redfd = 0;
    }
    else if(strstr(buff, ">"))
    {
        //1 标准输出
        redfd = 1;
    }

    char *cmd = NULL;
    char *file = NULL;
    if(redfd < 0)
    {
        //没有重定向
        cmd = strip(buff);
    }
    else
    {
        //有重定向
        cmd = strip(strtok(buff, "<>"));
        file = strip(strtok(NULL, "><"));
        int fd;
        if(redfd == 0)
        {
            fd = open(file, O_RDONLY);
        }
        else
        {
            fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0664);
        }
        if(fd < 0)
        {
            perror("open");
            exit(1);
        }
        close(redfd);
        dup2(fd, redfd);
        close(fd);
    }
    printf("cmd = [%s] file = [%s]\n", cmd, file);

    char *argarr[100];
    int i = 0;
    argarr[i++] = strtok(cmd, " ");

    while(argarr[i++] = strtok(NULL, " "))
    {

    }

    if(execvp(cmd, argarr) < 0)
    {
        perror("execvp");
        exit(1);
    }
    }

int main()
{
    char buff[1024] = {0};
    while(1)
    {
        //printf("shipingrui@localhost ~ $");
        printf("\033[31mshipingrui\033[0m@\033[35mlocalhost\033[0m ~ $");
        fgets(buff, sizeof(buff), stdin);
        buff[strlen(buff) - 1] = '\0';
        if(!strcmp(buff, "exit"))
        {
            break;
        }
        else if(!buff[0])
        {
            continue;
        }

        char *cmdarr[20];
        int i = 0;
        cmdarr[i++] = strtok(buff, "|");
        while(cmdarr[i] = strtok(NULL, "|"))
        {
            i++;
        }

        if(!cmdarr[1])
        {
            //没有管道符号
            pid_t pid = fork();
            if(pid == 0)
            {
                runcmd(buff);
                printf("执行命令：[%s]\n", buff);
            }
            else
            {
                wait(NULL);
            }
        }
        else
        {
            //有管道符号
            int pipefd[20][2];
            int j;
            pid_t pid;

            for(j = 0; j < i - 1; j++)
            {
                if(pipe(pipefd[j]) < 0)
                {
                    perror("pipe");
                    exit(1);
                }
            }
            for(j = 0; j < i; j++)
            {
                if((pid = fork()) < 0)
                {
                    perror("fork1");
                    exit(1);
                }
                if(pid == 0)
                {
                    
                }
            }

            if(pid == 0)
            {
                close(pipefd[0]);
                dup2(pipefd[1], 1);
                close(pipefd[1]);
                runcmd(cmdarr[0]);
            }
            if((pid = fork()) < 0)
            {
                perror("fork2");
                continue;
            }
            if(pid == 0)
            {
                close(pipefd[1]);
                dup2(pipefd[0], 0);
                close(pipefd[0]);
                runcmd(cmdarr[1]);
            }
            close(pipefd[0]);
            close(pipefd[1]);
            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}
