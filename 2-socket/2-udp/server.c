/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Feb 2022 04:49:29 PM CST
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

int main(void)
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in servaddr, cliaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("udpserver ready~\n");

    char buf[MAXLINE];
    socklen_t cliaddr_len;
    char str[INET_ADDRSTRLEN];
    while(1)
    {
        int n = recvfrom(sockfd, buf, MAXLINE, 0, (struct sockaddr *)&cliaddr, &cliaddr_len);
        if(n < 0)
            perrexit("recvfrom");

        printf("received from %s:%d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), ntohs(cliaddr.sin_port));

        for(int i = 0; i < n; i++)
            buf[i] = toupper(buf[i]);
        sendto(sockfd, buf, n, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
    }

    close(sockfd);
    return 0;
}
