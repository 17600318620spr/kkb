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

typedef struct Task{
    int fd;
    struct Task *next;
}Task;

typedef struct Task_pool{
    Task *head;
    Task *tail;
    pthread_mutex_t lock;
    pthread_cond_t havetask;
}Task_pool;

Task_pool *task_pool_init()
{
    Task_pool *tp = (Task_pool *)malloc(sizeof(Task_pool));
    tp->head = NULL;
    tp->tail = NULL;
    pthread_mutex_init(&tp->lock, NULL);
    pthread_cond_init(&tp->havetask, NULL);

    return tp;
}

void task_pool_push(Task_pool *tp, int fd)
{
    pthread_mutex_lock(&tp->lock);

    Task *t = (Task *)malloc(sizeof(Task));
    t->fd = fd;
    t->next = NULL;

    if(!tp->tail)
    {
        tp->head = tp->tail = t;
    }
    else
    {
        tp->tail->next = t;
        tp->tail = t;
    }

    pthread_cond_broadcast(&tp->havetask);

    pthread_mutex_unlock(&tp->lock);
}

Task task_pool_pop(Task_pool *tp)
{
    pthread_mutex_lock(&tp->lock);

    while(tp->head == NULL) //不能用if
        pthread_cond_wait(&tp->havetask, &tp->lock);

    Task tmp, *k;
    k = tp->head;
    tmp = *k;
    tp->head = tp->head->next;
    if(!tp->head) //if(tp->head == NULL)
        tp->tail = NULL;
    free(k);

    pthread_mutex_unlock(&tp->lock);

    return tmp;
}

void task_pool_free(Task_pool *tp)
{
    pthread_mutex_lock(&tp->lock);

    Task *p = tp->head, *k;

    while(p)
    {
        k = p;
        p = p->next;
        free(k);
    }
    tp->head = NULL;

    pthread_mutex_unlock(&tp->lock);
    pthread_mutex_destroy(&tp->lock);
    pthread_cond_destroy(&tp->havetask);
    free(tp);
    return ;
}

void *up_server(void *arg)
{
    pthread_detach(pthread_self());

    char buf[MAXLINE];

    Task_pool *tp = arg;

    while(1)
    {
        Task tmp = task_pool_pop(tp);
        int connfd = tmp.fd;
        printf("get task fd = %d\n", connfd);
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
        printf("finish task fd = %d\n", connfd);
        close(connfd);
    }
    return (void *)0;
}

int main(void)
{
    int listenfd, connfd;
    struct sockaddr_in serveraddr, cliaddr;
    socklen_t cliaddr_len;

    Task_pool *tp = task_pool_init();

    //多线程
    pthread_t tid;
    for(int i = 0; i < 4; i++)
    {
        pthread_create(&tid, NULL, up_server, (void *)tp);
        printf("new thread is %#lx\n", tid);
    }
    
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

        task_pool_push(tp, connfd);
    }

    task_pool_free(tp);

    return 0;
}
