/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Feb 2022 05:42:37 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<strings.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<ctype.h>

#define SERV_PORT 8000
#define MAXLINE 80

int main(void)
{
    struct sockaddr_in servaddr;

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    int n;
    char buf[MAXLINE];
    socklen_t servaddr_len;
    while(n = read(0, buf, MAXLINE))
    {
        n = sendto(sockfd, buf, n, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));

        n = recvfrom(sockfd, buf, MAXLINE, 0, (struct sockaddr *)&servaddr, &servaddr_len);
        //n = recvfrom(sockfd, buf, MAXLINE, 0, NULL, 0);
        write(1, buf, n);
    }

    close(sockfd);
    return 0;
}
