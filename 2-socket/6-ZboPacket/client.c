/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Feb 2022 03:19:31 PM CST
 ************************************************************************/

#include "head.h"

struct Packet
{
    char filename[50];
    ssize_t size;
    char body[1024];
};

int send_file(int sockfd, const char *file)
{
    //打开文件
    //确定文件大小
    FILE *fp;
    if((fp = fopen(file, "r")) == NULL)
    {
        return -1;
    }

    struct Packet packet;
    memset(&packet, 0, sizeof(packet));
    strcpy(packet.filename, file);
    fseek(fp, 0, SEEK_END);
    packet.size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    //ssize_t rsize = 0;
    while(1)
    {
        if(fread(packet.body, 1, sizeof(packet.body), fp) <= 0)
        {
            break;
        }
        if(send(sockfd, (void *)&packet, sizeof(packet), 0) < 0)
        {
            return -1;
        }
        memset(packet.body, 0, sizeof(packet.body));
    }

    fclose(fp);
    return 0;
}

int main(int argc, char **argv)
{
    // ./client ip port filename
    if(argc != 4)
    {
        fprintf(stderr, "Usage:%s ip port filename\n", argv[0]);
        exit(1);
    }

    int sockfd;
    int port = atoi(argv[2]);
    char ip[20] = {0};
    strcpy(ip, argv[1]);
    if((sockfd = socket_connect(ip, port)) < 0)
    {
        perror("socket_connect");
        exit(1);
    }

    if(send(sockfd, "mengdi", 6, 0) < 0)
    {
        perror("send");
        exit(1);
    }

    char file[50] = {0};
    strcpy(file, argv[3]);
    if(send_file(sockfd, file) < 0)
    {
        perror("send_file");
        exit(1);
    }
    close(sockfd);

    return 0;
}
