/*************************************************************************
	> File Name: common.c
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Feb 2022 11:03:30 AM CST
 ************************************************************************/

#include "head.h"

/* 服务端-socket-bind-listen */
int socket_create(int port)
{
    //socket
    int sockfd;
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        return -1;
    }

    //bind
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    if(bind(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0)
    {
        return -1;
    }

    //listen
    if(listen(sockfd, 20) < 0)
    {
        return -1;
    }

    return sockfd;
}

/* 客户端-socket-connect */
int socket_connect(const char *ip, int port)
{
   //socket 
    int sockfd;
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        return -1;
    }

    //connect
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) < 0)
    {
        return -1;
    }

    return sockfd;
}
