/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Feb 2022 01:39:21 PM CST
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
#include<string.h>

#define SERV_PORT 8000
#define MAXLINE 80

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    char buf[MAXLINE] = {"hello tcp"};
    int n;
    while(n = read(0, buf, MAXLINE))
    {
        if(!strncmp(buf, "quit", 4))
            break;
        write(sockfd, buf, n);
        n = read(sockfd, buf, MAXLINE);
        printf("response from server: ");
        write(1, buf, n);
    }
#if 0
    while(1)
    {
        sleep(1);
    }
#endif
    close(sockfd);
    return 0;
}
