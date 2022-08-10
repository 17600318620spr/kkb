/*************************************************************************
  > File Name: server.c
  > Author: 
  > Mail: 
  > Created Time: Wed 16 Feb 2022 02:08:17 PM CST
 ************************************************************************/

#include "head.h"

#define MAX 20

struct User
{
    int fd;
    char ip[20];
    char name[20];
};

struct Packet
{
    char filename[50];
    ssize_t size;
    char body[1024];
};

int recv_file(int sockfd, const char *dirname)
{
    //处理粘包和拆包情况
    struct Packet packet, packet_t, packet_pre;
    ssize_t recv_size = 0, total_size = 0, write_size = 0, offset = 0;
    ssize_t packet_size = sizeof(struct Packet);
    int cnt = 0;
    FILE *fp;
    if(mkdir(dirname, 0777) < 0)
    {
        if(errno == EEXIST)
        {

        }
        else
        {
            return -1;
        }
    }

    while(1)
    {
        //循环收
        memcpy((void *)&packet, &packet_pre, offset);
        while((recv_size = recv(sockfd, (void *)&packet_t, packet_size, 0)) > 0)
        {
            //循环凑包
            if(offset + recv_size == packet_size) 
            {
                //整包
                printf("整包\n");
                memcpy((void *)&packet + offset, &packet_t, recv_size);
                offset = 0;
                break;
            }
            else if(offset + recv_size < packet_size)
            {
                //拆包
                printf("拆包\n");
                memcpy((void *)&packet + offset, &packet_t, recv_size);
                offset += recv_size;
            }
            else
            {
                //粘包
                printf("粘包\n");
                memcpy((void *)&packet + offset, &packet_t, packet_size - offset);
                memcpy((void *)&packet_pre, (char *)&packet_t + (packet_size - offset), recv_size - (packet_size - offset));
                offset = recv_size - (packet_size - offset);
                break;
            }
        }

        if(cnt == 0)
        {
            //第一次接收消息，打开文件
            char filepath[64] = {0};
            sprintf(filepath, "./%s/%s", dirname, packet.filename);
            if((fp = fopen(filepath, "w+")) == NULL)
            {
                return -1;
            }
        }
        cnt++;

        //最后一次整合
        if(packet.size - total_size >= sizeof(packet.body))
        {
            write_size = fwrite(packet.body, 1, sizeof(packet.body), fp);
        }
        else
        {
            write_size = fwrite(packet.body, 1, packet.size - total_size, fp);
        }
        total_size += write_size;
        if(total_size >= packet.size)
        {
            printf("Finished!\n");
            break;
        }
    }

    fclose(fp);
    return 0;
}

void *work(void *arg)
{
    struct User *user;
    user = (struct User *)arg;
    recv_file(user->fd, user->name);

    close(user->fd); //一次连接发送一次文件，全部接收成功后，主动关闭连接
    return NULL;
}

int main(int argc, char **argv)
{
    // ./server port
    if(argc != 2)
    {
        fprintf(stderr, "Usage:%s port\n", argv[0]);
        exit(1);
    }

    int sockfd;
    int port = atoi(argv[1]);
    if((sockfd = socket_create(port)) < 0)
    {
        perror("socket_create");
        exit(1);
    }

    pthread_t tid[MAX + 5] = {0};
    struct User users[MAX + 5];
    bzero(&users, sizeof(users));
    while(1)
    {
        int new_fd;
        struct sockaddr_in client;
        socklen_t len;
        if((new_fd = accept(sockfd, (struct sockaddr *)&client, &len)) < 0)
        {
            perror("accept");
            continue;
        }

        //连接成功后，马上从client接收一个表明client身份的结构
        if(recv(new_fd, users[new_fd].name, sizeof(users[new_fd].name), 0) < 0)
        {
            close(new_fd);
            continue;
        }
        else
        {
            strcpy(users[new_fd].ip, inet_ntoa(client.sin_addr));
            users[new_fd].fd = new_fd;
        }

        pthread_create(&tid[new_fd], NULL, work, (void *)&users[new_fd]);
    }

    return 0;
}
