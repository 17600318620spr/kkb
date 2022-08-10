/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Feb 2022 10:21:20 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<strings.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<pthread.h>

#define SERV_PORT 8000
#define MAXLINE 80

#define perrexit(msg) { \
    perror(msg); \
    exit(1); \
}

void *up_server(void *arg)
{
    pthread_detach(pthread_self());

    int connfd = (int)arg;
    char buf[MAXLINE];
    while(1)
    {
        int n = read(connfd, buf, MAXLINE);
        if(!strncmp(buf, "quit", 4))
            break;
        write(1, buf, n);
        for(int i = 0; i < n; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        write(connfd, buf, n);
    }
    close(connfd);
    return (void *)0;
}

int main(void)
{
    int listenfd, connfd;
    struct sockaddr_in serveraddr, cliaddr;
    socklen_t cliaddr_len;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0)
        perrexit("socket");

    //服务器ip地址:端口初始化
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERV_PORT);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
        perrexit("bind");

    if(listen(listenfd, 2) < 0)
        perrexit("listen");
    printf("Accepting connections...\n");

    char str[INET_ADDRSTRLEN]; //16
    while(1)
    {
        cliaddr_len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
        if(connfd < 0)
            perrexit("accept");
        printf("received from %s:%d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), ntohs(cliaddr.sin_port));

#if 0 //多进程
        pid_t pid = fork();
        if(pid < 0)
            perrexit("fork");

        //父进程：等待 创建连接
        if(pid > 0)
        {
            close(connfd);
            while(waitpid(-1, NULL, WNOHANG) > 0) {}
            continue;
        }

        //子进程
        close(listenfd);
        while(1)
        {
            int n = read(connfd, buf, MAXLINE);
            if(!strncmp(buf, "quit", 4))
                break;
            write(1, buf, n);
            for(int i = 0; i < n; i++)
            {
                buf[i] = toupper(buf[i]);
            }
            write(connfd, buf, n);
        }
#else //多线程
        pthread_t tid;
        pthread_create(&tid, NULL, up_server, (void *)connfd);
        printf("new thread is %#lx\n", tid);
#endif
#if 0 //watch status!!!
        while(1)
        {
            sleep(1);
        }
#endif
    }

    return 0;
}
