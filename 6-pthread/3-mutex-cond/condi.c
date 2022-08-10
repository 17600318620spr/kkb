/*************************************************************************
	> File Name: condi.c
	> Author: 
	> Mail: 
	> Created Time: Fri 04 Mar 2022 02:45:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

typedef struct Goods
{
    int data;
    struct Goods *next;
}Goods;

Goods *head = NULL;
pthread_mutex_t headlock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t hasGoods = PTHREAD_COND_INITIALIZER;

void *producer(void *arg)
{
    Goods *ng;
    while(1)
    {
        ng = (Goods *)malloc(sizeof(Goods));
        ng->data = rand() % 100;

        pthread_mutex_lock(&headlock);
        // 头插法
        ng->next = head;
        head = ng;
        pthread_mutex_unlock(&headlock);
        pthread_cond_signal(&hasGoods);

        printf("produce %d\n", ng->data);
        sleep(rand() % 3);
    }
}

void *consumer(void *arg)
{
    Goods *k;
    while(1)
    {
        pthread_mutex_lock(&headlock);
        if(!head)
        {
            pthread_cond_wait(&hasGoods, &headlock);
        }
        k = head;
        head = head->next;
        pthread_mutex_unlock(&headlock);

        printf("consume %d\n", k->data);
        free(k);
        sleep(rand() % 3);
    }
}

int main()
{
    srand(time(NULL));

    pthread_t pid, cid;
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);

    return 0;
}
